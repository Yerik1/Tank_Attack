//
// Created by yerik on 9/29/24.
//
#include "window.h"
#include "ui_gameui.h"
#include <QTableWidget>
#include <QMouseEvent>
#include <QDebug>

Window::Window(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), dragging(false), lastSelectedRow(-1), lastSelectedColumn(-1) {
    ui->setupUi(this);

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
    connect(ui->Tablero, &QTableWidget::cellPressed, this, &Window::cellPressed);

    // Habilitar la transparencia para el mouse
    ui->Tablero->setAttribute(Qt::WA_TransparentForMouseEvents);
}

Window::~Window() {
    delete ui;
}

// Método para manejar la selección de la celda
void Window::cellPressed(int row, int column) {
    qDebug() << "Cell pressed:" << row << column; // Mensaje de depuración
    QTableWidgetItem* item = ui->Tablero->item(row, column);
    if (item) {
        ui->Tablero->clearSelection();
        item->setSelected(true);
        lastSelectedRow = row;
        lastSelectedColumn = column;
    }
}

// Manejar el evento de presión del mouse
void Window::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
        QPoint pos = ui->Tablero->mapFromGlobal(event->globalPos());
        QTableWidgetItem* item = ui->Tablero->itemAt(pos);
        if (item) {
            cellPressed(item->row(), item->column());
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