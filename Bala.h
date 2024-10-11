//
// Created by gabonm7 on 11/10/24.
//

#ifndef BALA_H
#define BALA_H

class Bala {
private:
    int id;
    float damage;
    int x, y;  // posición actual de la bala
    int objetivoX, objetivoY; // destino de la bala
    bool enMovimiento;

public:
    // Constructor
    Bala(int id, float damage, int x, int y, int objetivoX, int objetivoY);

    // Getters
    int getId() const;
    float getDamage() const;
    int getX() const;
    int getY() const;
    bool isEnMovimiento() const;

    // Setters
    void setX(int x);
    void setY(int y);
    void setEnMovimiento(bool enMovimiento);

    // Otros métodos
    void mover(int nuevoX, int nuevoY);
    bool haAlcanzadoObjetivo() const;
};

#endif
