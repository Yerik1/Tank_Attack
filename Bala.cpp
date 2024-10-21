//
// Created by gabonm7 on 11/10/24.
//
#include "Bala.h"

#include <iostream>

// Constructor
Bala::Bala(int id, float damage, int x, int y, QWidget* parent)
    : QWidget(parent), id(id), damage(damage), x(x), y(y) {
    setFixedSize(15, 15);  // Tamaño del widget 15x15
    move(x, y);  // Mueve el widget a la posición inicial
    // Fuerza un redibujado inmediato del widget
    show();
    repaint();
}

// Getters
int Bala::getId() const { return id; }
float Bala::getDamage() const { return damage; }
int Bala::getX() const { return x; }
int Bala::getY() const { return y; }

// Setters
void Bala::setX(int x) {
    this->x = x;
    move(x, y);  // Actualiza la posición del widget
}

void Bala::setY(int y) {
    this->y = y;
    move(x, y);  // Actualiza la posición del widget
}


// Método para mover la bala
void Bala::mover(int nuevoX, int nuevoY) {
    setX(nuevoX);
    setY(nuevoY);
    repaint();  // Redibuja el widget después de moverlo
}


// Método que dibuja la bala como un cuadrado de color azul
void Bala::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);  // No necesitamos usar este parámetro

    QPainter painter(this);
    if(id==1) {
        painter.setBrush(Qt::yellow);
    }else if (id==2) {
        painter.setBrush(Qt::green);
    }else if (id==3) {
        painter.setBrush(Qt::red);
    }
    painter.setPen(Qt::NoPen);   // Sin borde

    // Dibuja un cuadrado que ocupe todo el widget (15x15)
    painter.drawRect(0, 0, width(), height());
}

