//
// Created by gabonm7 on 11/10/24.
//

#ifndef TANQUE_H
#define TANQUE_H

class Tanque {
private:
    int id;
    int color;  // 1 = azul/celeste, 2 = rojo/amarillo
    float vida; // vida del tanque
    int x, y;   // posición del tanque en el mapa

public:
    // Constructor
    Tanque(int id, int color, float vida, int x, int y);

    // Getters
    int getId() const;
    int getColor() const;
    float getVida() const;
    int getX() const;
    int getY() const;

    // Setters
    void setVida(float vida);
    void setX(int x);
    void setY(int y);

    // Otros métodos
    void mover(int nuevoX, int nuevoY);
    void recieveDamage(float cantidad);
};

#endif

