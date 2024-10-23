//
// Created by gabonm7 on 11/10/24.
//

#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QLabel>

#include "Jugador.h"

class Timer : public QObject {
    Q_OBJECT

private:
    int secondsRemaining;   // Segundos restantes
    Jugador* P1;
    Jugador* P2;
    bool* JuegoActivo;
    QTimer *timer;
    QLabel *label;          // Referencia al QLabel del contador

public:
    Timer(QLabel *label, QObject *parent,Jugador* P1, Jugador* P2, bool* JuegoActivo);

    // Métodos
    void start(int durationSeconds);  // Inicia el temporizador
    void stop();                      // Detiene el temporizador

    private slots:
        void updateTime();  // Actualiza el tiempo y la etiqueta

    signals:
        void timeUp();  // Señal para indicar que el tiempo ha terminado
};

#endif // TIMER_H

