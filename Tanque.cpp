//
// Created by gabonm7 on 11/10/24.
//

#include "Tanque.h"

// Constructor
Tanque::Tanque(int id, int color, float vida, int x, int y)
    : id(id), color(color), vida(vida), x(x), y(y) {}

// Getters
int Tanque::getId() const { return id; }
int Tanque::getColor() const { return color; }
int Tanque::getVida() const { return vida; }
int Tanque::getX() const { return x; }
int Tanque::getY() const { return y; }
QWidget *Tanque::getImagen() const { return Imagen; }
QLabel *Tanque::getLabel() const { return Vida; }


// Setters
void Tanque::setVida(float vida) { this->vida = vida; }
void Tanque::setX(int x) { this->x = x; }
void Tanque::setY(int y) { this->y = y; }
void Tanque::setImagen(QWidget *imagen) {this->Imagen = imagen; }
void Tanque::setLabel(QLabel *label) { this->Vida = label; }


// Otros métodos
void Tanque::mover(int nuevoX, int nuevoY) {
    this->x = nuevoX;
    this->y = nuevoY;
}

void Tanque::recieveDamage(float cantidad) {
    vida -= cantidad;
    if (vida <= 0) {
        vida = 0;
        this->Imagen->hide();
    }
    this->Vida->setText(QString::number(vida));
}

