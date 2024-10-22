//
// Created by yerik on 9/29/24.
//
#include "Game.h"



/** INICIO ADMINISTRACION DE VENTANA Y JUEGO */

/**
 * Metodo Principal del juego, aqui se administran los objetos y propiedades principales del juego
 * @param parent
 */
Window::Window(QWidget *parent) :
    //Iniciar la ventana
    QMainWindow(parent), ui(new Ui::MainWindow), dragging(false), lastSelectedRow(-1), lastSelectedColumn(-1) {
    ui->setupUi(this);

    Jugador1.agregarTanque(&Rojo1);
    Jugador1.agregarTanque(&Rojo2);
    Jugador1.agregarTanque(&Azul1);
    Jugador1.agregarTanque(&Azul2);
    Jugador1.setImagen(ui->PowerUPP1);

    Jugador2.agregarTanque(&Amarillo1);
    Jugador2.agregarTanque(&Amarillo2);
    Jugador2.agregarTanque(&Celeste1);
    Jugador2.agregarTanque(&Celeste2);
    Jugador2.setImagen(ui->PowerUpP2);

    generarPowerUps(&Jugador1,&Jugador2);


    //Asignar Widget a cada tanque
    Rojo1.setImagen(ui->TRojo1);
    Rojo2.setImagen(ui->TRojo2);
    Azul1.setImagen(ui->TAzul1);
    Azul2.setImagen(ui->TAzul2);
    Amarillo1.setImagen(ui->TAmarillo1);
    Amarillo2.setImagen(ui->TAmarillo2);
    Celeste1.setImagen(ui->TCeleste1);
    Celeste2.setImagen(ui->TCeleste2);
    Rojo1.setLabel(ui->VidaRojo1L);
    Rojo2.setLabel(ui->VidaRojo2L);
    Azul1.setLabel(ui->VidaAzul1L);
    Azul2.setLabel(ui->VidaAzul2L);
    Amarillo1.setLabel(ui->VidaAmarillo1L);
    Amarillo2.setLabel(ui->VidaAmarillo2L);
    Celeste1.setLabel(ui->VidaCeleste1L);
    Celeste2.setLabel(ui->VidaCeleste2L);
    setupEventFilter();

    //Propiedades para eventos de Mouse en el tablero
    ui->Tablero->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->Tablero->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->Tablero->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->Tablero->setAttribute(Qt::WA_TransparentForMouseEvents);

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


    //Se genera el mapa a nivel interno y se hace un debug para observarlo
    generateMapBorder();
    generateRandomObstacles();
    grafo.mostrarMatriz();

}

/**
 * Destructor de la ventana
 */
Window::~Window() {
    delete ui;
}

/** FIN ADMINISTRACION DE VENTANA Y JUEGO */

/** INICIO GENERACION DE MAPA */

/**
 * Generador del Borde del Mapa
 */
void Window::generateMapBorder() {
    //Recorre el mapa
    for (int row = 0; row < 20; ++row) {
        for (int column = 0; column < 40; ++column) {
            QTableWidgetItem *item = new QTableWidgetItem();

            // Solo agregar imágenes a las celdas del borde
            if (row != 0 && column != 0 && row!=19 && column!=39) {
                // Dejar la celdas centrales vacías
                item->setBackground(Qt::transparent); // o no establecer ninguna imagen
            } else {
                // Establecer la imagen para las otras celdas
                QLabel *label = new QLabel();
                QPixmap pixmap("../Imagenes/Obstaculo.png"); // Cargar la imagen como QPixmap
                label->setPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Escalar la imagen
                label->setFixedSize(23, 23); //  QLabel con mismo tamaño que la celda
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

/**
 * Generador del resto de obstaculos en el mapa de manera aleatoria
 */
void Window::generateRandomObstacles() {
    // Generar obstáculos solo en la mitad izquierda del tablero (columnas 0 a 19)
    for (int row = 1; row < 20; ++row) {
        for (int column = 1; column < 19; ++column) {
            // Evitar las celdas especificadas (Donde se generan los tanques)
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

/** FIN GENERACION DE MAPA */

/** INICIO ANIIMACIONES */

/**
 * Animacion de Movimiento del tanque por las posiciones
 * @param movimientos Lista de Movimientos a Realizar
 * @return 1 si hay que realizar movimientos, 0 si no hay movimientos en la lista
 */
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
int Window::movimientoBala(const std::vector<std::pair<int, int> > &movimientos) {
    Bala* bala = new Bala(2, 1, 104+23*SelectedTank->getY(), 234+23*SelectedTank->getX(), ui->centralwidget);

    if (movimientos.empty()) {
        bala->hide();
        return 0;
    }else {

        int index = movimientos.size() - 1;  // Comenzamos desde el último movimiento
        QTimer* timer = new QTimer(this);

        connect(timer, &QTimer::timeout, [=]() mutable {
            if (index >= 0) {
                int x = movimientos[index].first;
                int y = movimientos[index].second;

                // Mover el widget
                bala->mover(104 + 23 * y, 234 + 23 * x);

                --index;  // Retroceder al siguiente movimiento
            } else {
                timer->stop();  // Detener el temporizador cuando llegamos al inicio
                timer->deleteLater();  // Liberar el temporizador después de detenerse
                bala->hide();
                bala->deleteLater();
                SelectedTank=&Defecto;
                auto [row, column] = movimientos.front();
                if(Rojo1.getX()==row && Rojo1.getY()==column) {
                    Rojo1.recieveDamage(1);
                }
                if(Rojo2.getX()==row && Rojo2.getY()==column) {
                    Rojo2.recieveDamage(1);
                }
                if(Azul1.getX()==row && Azul1.getY()==column) {
                    Azul1.recieveDamage(1);
                }
                if(Azul2.getX()==row && Azul2.getY()==column) {
                    Azul2.recieveDamage(1);
                }
                if(Amarillo1.getX()==row && Amarillo1.getY()==column) {
                    Amarillo1.recieveDamage(1);
                }
                if(Amarillo2.getX()==row && Amarillo2.getY()==column) {
                    Amarillo2.recieveDamage(1);
                }
                if(Celeste1.getX()==row && Celeste1.getY()==column) {
                    Celeste1.recieveDamage(1);
                }
                if(Celeste2.getX()==row && Celeste2.getY()==column) {
                    Celeste2.recieveDamage(1);
                }
            }
        });

        timer->start(200);  // Inicia el temporizador con un intervalo de 500 ms (ajustable)

    }
    return 1;
}

/** FIN ANIIMACIONES */

/** INICIO GESTOR DE EVENTOS DE MOUSE */

/**
 * Metodo para asignar el evento de click a los tanques
 */
void Window::setupEventFilter() {
    ui->TRojo1->installEventFilter(this);
    ui->TRojo2->installEventFilter(this);
    ui->TAzul1->installEventFilter(this);
    ui->TAzul2->installEventFilter(this);
    ui->TAmarillo1->installEventFilter(this);
    ui->TAmarillo2->installEventFilter(this);
    ui->TCeleste1->installEventFilter(this);
    ui->TCeleste2->installEventFilter(this);
}


/**
 * Metodo para Cambiar el tanque Seleccionado en el juego
 * @param obj Widget clickeado
 * @param event Click Realizado
 * @return True si fue presionado con el click izquierdo, False si fue presionado con cualquier otro boton
 */
bool Window::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (obj == ui->TRojo1) {
                SelectedTank = &Rojo1; // Asigna la dirección de Rojo1
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true;
            }
            else if (obj == ui->TRojo2) {
                SelectedTank = &Rojo2; // Asigna la dirección de Rojo2
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true;
            }
            else if (obj == ui->TAzul1) {
                SelectedTank = &Azul1; // Asigna la dirección de Azul1
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true;
            }
            else if (obj == ui->TAzul2) {
                SelectedTank = &Azul2; // Asigna la dirección de Azul2
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true;
            }
            else if (obj == ui->TAmarillo1) {
                SelectedTank = &Amarillo1; // Asigna la dirección de Amarillo1
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true;
            }
            else if (obj == ui->TAmarillo2) {
                SelectedTank = &Amarillo2; // Asigna la dirección de Amarillo2
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true;
            }
            else if (obj == ui->TCeleste1) {
                SelectedTank = &Celeste1; // Asigna la dirección de Celeste1
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true;
            }
            else if (obj == ui->TCeleste2) {
                SelectedTank = &Celeste2; // Asigna la dirección de Celeste2
                qDebug() << "Selected tank id:" << SelectedTank->getId(); // Mensaje de depuración
                return true;
            }
        }
    }
    return QMainWindow::eventFilter(obj, event); // Pasa el evento al manejador base
}

/**
 * Metodo para detectar que una celda se presiono y realizar su debida accion
 * @param row fila presionada
 * @param column columna realizada
 * @param action accion a realizar (Disparar o moverse)
 */
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
            if(iniciarMovimiento(objAStar.aStar(grafo.getMatriz(), (*SelectedTank).getX() * 40 + (*SelectedTank).getY(), row * 40 + column, 40))==1) {
                (*SelectedTank).setX(row);
                (*SelectedTank).setY(column);
            };
            //Utilzar BFS
            /**if(iniciarMovimiento(objBFS.bfs(grafo.getMatriz(), (*SelectedTank).getX() * 40 + (*SelectedTank).getY(), row * 40 + column, 40))==1) {
                (*SelectedTank).setX(row);
                (*SelectedTank).setY(column);
            };*/
        }else if((*SelectedTank).getColor()==2) {
            //Utilizar Linea Vista
            std::vector<std::pair<int, int>> movimientos = mAleatorio.moverTanque(grafo.getObstaculos(),(*SelectedTank).getX(),(*SelectedTank).getY(),row,column,1);
            iniciarMovimiento(movimientos);
            auto [row, column] = movimientos.front();
            (*SelectedTank).setX(row);
            (*SelectedTank).setY(column);


            //Utilizar Djikstra
            /**if(iniciarMovimiento(objDijkstra.dijkstra(grafo.getMatriz(), (*SelectedTank).getX() * 40 + (*SelectedTank).getY(), row * 40 + column, 40))==1) {
                (*SelectedTank).setX(row);
                (*SelectedTank).setY(column);
            };*/
        }
    }else if (action=="Shoot at:") {
        std::vector<std::pair<int, int>> movimientos=objAStar.aStar(grafo.getMatriz(), (*SelectedTank).getX() * 40 + (*SelectedTank).getY(), row * 40 + column, 40);
        //std::vector<std::pair<int, int>> movimentos = mAleatorio.moverBala(grafo.getMatriz(),40,(*SelectedTank).getX(),(*SelectedTank).getY(),row,column);
        movimientoBala(movimientos);


    }
}

/** FIN GESTOR DE EVENTOS DE MOUSE */

/** INICIO DETECCION DE EVENTOS DE MOUSE TABLERO */

/**
 * Metodo para distinguir si hubo un click derecho o izquierdo
 * @param event Click realizado
 */
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

/**
 * Metodo para evitar el arrastre entre las casillas del tablero
 * @param event Click Realizado
 */
void Window::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
        dragging = false;  // Finalizar el arrastre
    }

    // Llama a la implementación base
    QMainWindow::mouseReleaseEvent(event);
}

/**
 * Metodo auxiiar para evitar el arrastre entre las casillas del tablero
 * @param event Click Realziado
 */
void Window::mouseMoveEvent(QMouseEvent *event) {
    if (dragging) {
        return;  // Evita cambiar la selección
    }

    // Llama a la implementación base
    QMainWindow::mouseMoveEvent(event);
}

/** FIN DETECCION DE EVENTOS DE MOUSE TABLERO */

// Metodo para generar power-ups en un hilo separado

void Window::generarPowerUps(Jugador* jugador1, Jugador* jugador2) {
    std::thread([this, jugador1, jugador2]() {
        while (true) {
            // Pausar 10 segundos entre la generación de power-ups
            std::this_thread::sleep_for(std::chrono::seconds(10));

            // Crear power-ups aleatorios para ambos jugadores
            PowerUps powerUp1 = generarPowerUpAleatorio();
            PowerUps powerUp2 = generarPowerUpAleatorio();

            // Asignar power-ups a los jugadores
            jugador1->agregarPowerUp(powerUp1);
            jugador2->agregarPowerUp(powerUp2);

            if (jugador1->hayPowerUps()) {
                PowerUps primerPowerUpJugador1 = jugador1->returnTop();  // Obtener el primer power-up
                actualizarPowerUpWidget(jugador1, primerPowerUpJugador1);  // Actualizar el widget en la interfaz
            }

            if (jugador2->hayPowerUps()) {
                PowerUps primerPowerUpJugador2 = jugador2->returnTop();  // Obtener el primer power-up
                actualizarPowerUpWidget(jugador2, primerPowerUpJugador2);  // Actualizar el widget en la interfaz
            }

            // Aquí puedes agregar lógica para notificar a los jugadores que recibieron un power-up
            // o actualizar la interfaz gráfica, si es necesario.
        }
    }).detach();  // El hilo se ejecutará de forma independiente
}
// Metodo  para generar un power-up aleatorio
PowerUps Window::generarPowerUpAleatorio() {
    int randomNum = rand() % 4;  // Generar un número aleatorio entre 0 y 3
    std::string nombrePowerUp;

    switch (randomNum) {
        case 0:
            nombrePowerUp = "Doble Turno";
        break;
        case 1:
            nombrePowerUp = "Precisión Movimiento";
        break;
        case 2:
            nombrePowerUp = "Precisión Ataque";
        break;
        case 3:
            nombrePowerUp = "Poder Ataque";
        break;
    }

    return PowerUps(nombrePowerUp);
}

void Window::actualizarPowerUpWidget(Jugador* jugador, const PowerUps& powerUp) {
    QString rutaImagen;

    // Asignar la ruta de la imagen según el nombre del power-up
    if (powerUp.getNombre() == "Doble Turno") {
        rutaImagen = "../Imagenes/DobleTurno.png";
    } else if (powerUp.getNombre() == "Precisión Movimiento") {
        rutaImagen = "../Imagenes/Movimiento.png";
    } else if (powerUp.getNombre() == "Precisión Ataque") {
        rutaImagen = "../Imagenes/Precision.png";
    } else if (powerUp.getNombre() == "Poder Ataque") {
        rutaImagen = "../Imagenes/Headshot.png";
    }

    // Suponiendo que tienes un QLabel asociado al jugador para mostrar el power-up
    QLabel* ImgPowerUp = jugador->getImagen();  // Obtener el QLabel correspondiente al jugador

    // Cambiar la imagen en el QLabel
    QPixmap pixmap(rutaImagen);
    ImgPowerUp->setPixmap(pixmap.scaled(ImgPowerUp->size(), Qt::KeepAspectRatio));
}

