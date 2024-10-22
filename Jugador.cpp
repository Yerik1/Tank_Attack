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

QLabel *Jugador::getImagen() const { return Imagen; }

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

void Jugador::setImagen(QLabel *imagen) {this->Imagen = imagen; }


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

// Métodos para power-ups
void Jugador::agregarPowerUp(const PowerUps& powerUp) {
    colaPowerUps.push(powerUp);
}

PowerUps Jugador::usarPowerUp() {
    if (!colaPowerUps.empty()) {
        PowerUps powerUpActual = colaPowerUps.front();
        colaPowerUps.pop();  // Elimina el power-up de la cola

        // Activar el power-up correspondiente según su nombre
        std::string nombrePowerUp = powerUpActual.getNombre();

        if (nombrePowerUp == "Doble Turno") {
            powerUpDobleTurno = true;  // Activar doble turno
        }
        else if (nombrePowerUp == "Precisión Movimiento") {
            powerUpPrecisionMov = true;  // Activar precisión de movimiento
        }
        else if (nombrePowerUp == "Precisión Ataque") {
            powerUpPrecisionAtaque = true;  // Activar precisión de ataque
        }
        else if (nombrePowerUp == "Poder Ataque") {
            powerUpPoderAtaque = true;  // Activar poder de ataque
        }

        return powerUpActual;
    }

    return PowerUps();  // Retorna un power-up vacío si la cola está vacía
}

bool Jugador::hayPowerUps() const {
    return !colaPowerUps.empty();
}

PowerUps Jugador::returnTop() {
    return colaPowerUps.front();
}

