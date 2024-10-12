//
// Created by gabonm7 on 11/10/24.
//

#include "Timer.h"

Timer::Timer(QLabel *label, QObject *parent) : QObject(parent), label(label) {
    timer = new QTimer(this);
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
        emit timeUp();
    }
}

