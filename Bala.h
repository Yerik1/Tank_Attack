//
// Created by gabonm7 on 11/10/24.
//
#ifndef BALA_H
#define BALA_H

#include <QWidget>
#include <QPainter>

class Bala : public QWidget {
    Q_OBJECT  // Macro necesaria para clases que usan señales y slots

private:
    int id;
    float damage;
    int x, y;  // Posición actual de la bala


public:
    // Constructor
    Bala(int id, float damage, int x, int y, QWidget *parent = nullptr);

    // Getters
    int getId() const;
    float getDamage() const;
    int getX() const;
    int getY() const;

    // Setters
    void setX(int x);
    void setY(int y);

    // Otros métodos
    void mover(int nuevoX, int nuevoY);

protected:
    void paintEvent(QPaintEvent* event) override;  // Dibuja la bala
};

#endif  // BALA_H
