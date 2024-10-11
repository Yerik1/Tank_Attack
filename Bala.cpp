//
// Created by gabonm7 on 11/10/24.
//

#include "Bala.h"

// Constructor
Bala::Bala(int id, float danio, int x, int y, int objetivoX, int objetivoY)
    : id(id), damage(damage), x(x), y(y), objetivoX(objetivoX), objetivoY(objetivoY), enMovimiento(true) {}

// Getters
int Bala::getId() const { return id; }
float Bala::getDamage() const { return damage; }
int Bala::getX() const { return x; }
int Bala::getY() const { return y; }
bool Bala::isEnMovimiento() const { return enMovimiento; }

// Setters
void Bala::setX(int x) { this->x = x; }
void Bala::setY(int y) { this->y = y; }
void Bala::setEnMovimiento(bool enMovimiento) { this->enMovimiento = enMovimiento; }

// Otros métodos
void Bala::mover(int nuevoX, int nuevoY) {
    this->x = nuevoX;
    this->y = nuevoY;
}

bool Bala::haAlcanzadoObjetivo() const {
    return x == objetivoX && y == objetivoY;
}
