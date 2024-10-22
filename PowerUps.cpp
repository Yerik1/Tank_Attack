//
// Created by gabonm7 on 22/10/24.
//

#include "PowerUps.h"

// Constructor
PowerUps::PowerUps(const std::string &nombre) : nombre(nombre) {}

// Getter
std::string PowerUps::getNombre() const {
    return nombre;
}

// Setter
void PowerUps::setNombre(const std::string &nombre) {
    this->nombre = nombre;
}


