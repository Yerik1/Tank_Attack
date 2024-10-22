//
// Created by gabonm7 on 22/10/24.
//

#include "Jugador.h"

// Constructor
Jugador::Jugador()
    : numeroTanques(0), powerUpDobleTurno(false), powerUpPrecisionMov(false),
      powerUpPrecisionAtaque(false), powerUpPoderAtaque(false), turnoActivo(false) {}

// Getters
int Jugador::getNumeroTanques() const {
    return numeroTanques;
}

bool Jugador::isPowerUpDobleTurnoActivo() const {
    return powerUpDobleTurno;
}

bool Jugador::isPowerUpPrecisionMovActivo() const {
    return powerUpPrecisionMov;
}

bool Jugador::isPowerUpPrecisionAtaqueActivo() const {
    return powerUpPrecisionAtaque;
}

bool Jugador::isPowerUpPoderAtaqueActivo() const {
    return powerUpPoderAtaque;
}

bool Jugador::isTurnoActivo() const {
    return turnoActivo;
}

// Setters
void Jugador::setTurnoActivo(bool activo) {
    turnoActivo = activo;
}

void Jugador::activarPowerUpDobleTurno() {
    powerUpDobleTurno = true;
}

void Jugador::desactivarPowerUpDobleTurno() {
    powerUpDobleTurno = false;
}

void Jugador::activarPowerUpPrecisionMov() {
    powerUpPrecisionMov = true;
}

void Jugador::activarPowerUpPrecisionAtaque() {
    powerUpPrecisionAtaque = true;
}

void Jugador::activarPowerUpPoderAtaque() {
    powerUpPoderAtaque = true;
}

void Jugador::desactivarPowerUps() {
    powerUpDobleTurno = false;
    powerUpPrecisionMov = false;
    powerUpPrecisionAtaque = false;
    powerUpPoderAtaque = false;
}

// Métodos para gestionar tanques
void Jugador::agregarTanque(Tanque* tanque) {
    tanques.push_back(tanque);
    numeroTanques++;
}

void Jugador::eliminarTanque(Tanque* tanque) {
    auto it = std::find(tanques.begin(), tanques.end(), tanque);
    if (it != tanques.end()) {
        tanques.erase(it);
        numeroTanques--;
    }
}



// Métodos para turnos
bool Jugador::verificarFinPartida() {
    // Verifica si las condiciones para terminar el turno se cumplen
    if (numeroTanques <= 0) {
        turnoActivo = false;  // Finalizar el turno si no hay tanques vivos
    }
    return !turnoActivo;
}

