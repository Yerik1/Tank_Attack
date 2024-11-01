//
// Created by gabonm7 on 11/10/24.
//

#include "Timer.h"
#include "QDebug"

Timer::Timer(QLabel *label, QObject *parent, Jugador* P1, Jugador* P2, bool* JuegoActivo) : QObject(parent), label(label) {
    timer = new QTimer(this);
    this->P1 = P1;
    this->P2 = P2;
    this->JuegoActivo = JuegoActivo;
    connect(timer, &QTimer::timeout, this, &Timer::updateTime);
}

void Timer::start(int durationSeconds) {
    secondsRemaining = durationSeconds;
    updateTime();  // Mostrar el tiempo inicial
    timer->start(1000);  // Actualiza cada segundo
}

void Timer::stop() {
    timer->stop();
}

void Timer::updateTime() {
    if (secondsRemaining > 0) {
        --secondsRemaining;
        int minutes = secondsRemaining / 60;
        int seconds = secondsRemaining % 60;
        label->setText(QString::number(minutes) + ":" + QString::number(seconds).rightJustified(2, '0'));
    } else {
        timer->stop();
        *JuegoActivo = false;
        if(P1->getNumeroTanques()>P2->getNumeroTanques()) {
            qDebug()<<"Jugador 1 Gano";
        }else if(P2->getNumeroTanques()>P1->getNumeroTanques()) {
            qDebug()<<"Jugador 2 Gano";
        }else {
            qDebug()<<"Empate";

        }
        emit timeUp();
    }
}

