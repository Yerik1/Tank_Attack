//
// Created by yerik on 9/29/24.
//
#include "Game.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), dragging(false), lastSelectedRow(-1), lastSelectedColumn(-1) {
    ui->setupUi(this);
    Rojo1.setImagen(ui->TRojo1);
    Rojo2.setImagen(ui->TRojo2);
    Amarillo1.setImagen(ui->TAmarillo1);
    Amarillo2.setImagen(ui->TAmarillo2);
    setupEventFilter();

    ui->Tablero->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->Tablero->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->Tablero->setSelectionBehavior(QAbstractItemView::SelectItems);

    // Establecer la geometría y propiedades del tablero
    ui->Tablero->setRowCount(20);
    ui->Tablero->setColumnCount(40);
    ui->Tablero->horizontalHeader()->setVisible(false);
    ui->Tablero->verticalHeader()->setVisible(false);
    ui->Tablero->setShowGrid(false);

    // Inicializar elementos en el tablero
    for (int row = 0; row < 20; ++row) {
        for (int column = 0; column < 40; ++column) {
            QTableWidgetItem *item = new QTableWidgetItem();
            ui->Tablero->setItem(row, column, item);
        }
    }

    // Conectar el evento cellPressed
    connect(ui->Tablero, &QTableWidget::cellPressed, this, [this](int row, int column) {
    QString action;
    if (QApplication::mouseButtons() & Qt::LeftButton) {
        action = "Move to:";
    } else if (QApplication::mouseButtons() & Qt::RightButton) {
        action = "Shoot at:";
    }
    this->cellPressed(row, column, action);
});

    // Habilitar la transparencia para el mouse
    ui->Tablero->setAttribute(Qt::WA_TransparentForMouseEvents);
    //ui->TRojo1->setAttribute(Qt::WA_TransparentForMouseEvents);
    generateMapBorder();
    generateRandomObstacles();
    grafo.mostrarMatriz();


}

Window::~Window() {
    delete ui;
}

// Método para manejar la selección de la celda
void Window::cellPressed(int row, int column, const QString& action) {
    qDebug() << action << row << column; // Mensaje de depuración
    QTableWidgetItem* item = ui->Tablero->item(row, column);
    if (item) {
        ui->Tablero->clearSelection();
        item->setSelected(true);
        lastSelectedRow = row;
        lastSelectedColumn = column;
    }
    if(action=="Move to:") {
        if((*SelectedTank).getColor()==1) {

        }else if((*SelectedTank).getColor()==2) {
            if(iniciarMovimiento(objDijkstra.dijkstra(grafo.getMatriz(), (*SelectedTank).getX() * 40 + (*SelectedTank).getY(), row * 40 + column, 40))==1) {
                (*SelectedTank).setX(row);
                (*SelectedTank).setY(column);
            } ;

        }




    }
}

void Window::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
        QPoint pos = ui->Tablero->mapFromGlobal(event->globalPos());
        QTableWidgetItem* item = ui->Tablero->itemAt(pos);
        if (item) {
            QString action;
            if (event->button() == Qt::LeftButton) {
                action = "Move to:";
            } else if (event->button() == Qt::RightButton) {
                action = "Shoot at:";
            }
            cellPressed(item->row(), item->column(), action);
            dragging = true;  // Iniciar el arrastre
        }
    }

    // Llama a la implementación base
    QMainWindow::mousePressEvent(event);
}

// Manejar el evento de liberación del mouse
void Window::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
        dragging = false;  // Finalizar el arrastre
    }

    // Llama a la implementación base
    QMainWindow::mouseReleaseEvent(event);
}

// Manejar el evento de movimiento del mouse
void Window::mouseMoveEvent(QMouseEvent *event) {
    if (dragging) {
        return;  // Evita cambiar la selección
    }

    // Llama a la implementación base
    QMainWindow::mouseMoveEvent(event);
}

void Window::setupEventFilter() {
    ui->TRojo1->installEventFilter(this);
    ui->TRojo2->installEventFilter(this);
    ui->TAmarillo1->installEventFilter(this);
    ui->TAmarillo2->installEventFilter(this);
}

bool Window::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (obj == ui->TRojo1) {
                SelectedTank = &Rojo1; // Asigna la dirección de Rojo1
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true; // Indica que el evento fue manejado
            }
            else if (obj == ui->TRojo2) {
                SelectedTank = &Rojo2; // Asigna la dirección de Rojo2
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true; // Indica que el evento fue manejado
            }
            else if (obj == ui->TAmarillo1) {
                SelectedTank = &Amarillo1; // Asigna la dirección de Rojo1
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true; // Indica que el evento fue manejado
            }
            else if (obj == ui->TAmarillo2) {
                SelectedTank = &Amarillo2; // Asigna la dirección de Rojo2
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true; // Indica que el evento fue manejado
            }
        }
    }
    return QMainWindow::eventFilter(obj, event); // Pasa el evento al manejador base
}


void Window::generateMapBorder() {
    for (int row = 0; row < 20; ++row) {
        for (int column = 0; column < 40; ++column) {
            QTableWidgetItem *item = new QTableWidgetItem();

            // Solo agregar imágenes a las celdas que no sean la central
            if (row != 0 && column != 0 && row!=19 && column!=39) {
                // Dejar la celda central vacía
                item->setBackground(Qt::transparent); // o no establecer ninguna imagen
            } else {
                // Establecer la imagen para las otras celdas
                QLabel *label = new QLabel();
                QPixmap pixmap("../Imagenes/Obstaculo.png"); // Cargar la imagen como QPixmap
                label->setPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Escalar la imagen
                label->setFixedSize(23, 23); // Asegúrate de que el QLabel tenga el mismo tamaño que la celda
                label->setAlignment(Qt::AlignCenter); // Centrar la imagen dentro del QLabel

                // Eliminar cualquier borde
                label->setStyleSheet("border: none; background-color: transparent;");

                // Colocar el QLabel en la celda
                ui->Tablero->setCellWidget(row, column, label);
                grafo.agregarObstaculo(row,column);
            }

        }
    }
}

void Window::generateRandomObstacles() {
    // Generar obstáculos solo en la mitad izquierda del tablero (columnas 0 a 19)
    for (int row = 1; row < 20; ++row) {
        for (int column = 1; column < 19; ++column) {
            // Evitar las celdas especificadas
            if ((row == 7 && (column == 7 || column == 12)) ||
                (row == 12 && (column == 7 || column == 12))||
                (row == 9 && (column == 7 || column == 12)) ||
                (row == 14 && (column == 7 || column == 12))) {
                continue; // Saltar estas celdas
                }

            // Decidir aleatoriamente si colocar un obstáculo
            if (QRandomGenerator::global()->bounded(5) == 1) { // 20% de probabilidad
                // Colocar obstáculo en la celda actual
                QLabel *label = new QLabel();
                QPixmap pixmap("../Imagenes/Obstaculo.png");
                label->setPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                label->setFixedSize(23, 23);
                label->setAlignment(Qt::AlignCenter);
                label->setStyleSheet("border: none; background-color: transparent;");
                ui->Tablero->setCellWidget(row, column, label);
                grafo.agregarObstaculo(row,column);

                // Colocar el obstáculo en la celda reflejada (espejo)
                QLabel *mirrorLabel = new QLabel();
                mirrorLabel->setPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                mirrorLabel->setFixedSize(23, 23);
                mirrorLabel->setAlignment(Qt::AlignCenter);
                mirrorLabel->setStyleSheet("border: none; background-color: transparent;");
                ui->Tablero->setCellWidget(row, 39 - column, mirrorLabel); // Columna espejo
                grafo.agregarObstaculo(row,39-column);
            }
        }
    }
}

int Window::iniciarMovimiento(const std::vector<std::pair<int, int> > &movimientos) {
    if (movimientos.empty()) {
        return 0;
    }else {

        int index = movimientos.size() - 1;  // Comenzamos desde el último movimiento
        QTimer* timer = new QTimer(this);

        connect(timer, &QTimer::timeout, [=]() mutable {
            if (index >= 0) {
                int x = movimientos[index].first;
                int y = movimientos[index].second;

                // Mover el widget
                (*SelectedTank).getImagen()->move(100 + 23 * y, 230 + 23 * x);

                --index;  // Retroceder al siguiente movimiento
            } else {
                timer->stop();  // Detener el temporizador cuando llegamos al inicio
                timer->deleteLater();  // Liberar el temporizador después de detenerse
                SelectedTank=&Defecto;
            }
        });

        timer->start(200);  // Inicia el temporizador con un intervalo de 500 ms (ajustable)

    }
    return 1;
}
