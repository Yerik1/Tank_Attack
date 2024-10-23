//
// Created by gabonm7 on 22/10/24.
//

#ifndef POWERUPS_H
#define POWERUPS_H

#include <string>

class PowerUps {
private:
    std::string nombre;  // Nombre del power-up

public:
    // Constructor
    PowerUps(const std::string &nombre = "");

    // Getters
    std::string getNombre() const;

    // Setters
    void setNombre(const std::string &nombre);
};

#endif // POWERUPS_H


