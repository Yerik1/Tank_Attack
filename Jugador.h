//
// Created by gabonm7 on 22/10/24.
//
#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "Tanque.h"

class Jugador {
private:
    int numeroTanques;          // Número de tanques activos
    std::vector<Tanque*> tanques;  // Vector de punteros a tanques
    bool powerUpDobleTurno;     // PowerUp de doble turno activo
    bool powerUpPrecisionMov;   // PowerUp de precisión de movimiento activo
    bool powerUpPrecisionAtaque;// PowerUp de precisión de ataque activo
    bool powerUpPoderAtaque;    // PowerUp de poder de ataque activo
    bool turnoActivo;           // Indica si es el turno del jugador

public:
    // Constructor
    Jugador();

    // Getters
    int getNumeroTanques() const;
    bool isPowerUpDobleTurnoActivo() const;
    bool isPowerUpPrecisionMovActivo() const;
    bool isPowerUpPrecisionAtaqueActivo() const;
    bool isPowerUpPoderAtaqueActivo() const;
    bool isTurnoActivo() const;

    // Setters
    void setTurnoActivo(bool activo);
    void activarPowerUpDobleTurno();
    void desactivarPowerUpDobleTurno();
    void activarPowerUpPrecisionMov();
    void activarPowerUpPrecisionAtaque();
    void activarPowerUpPoderAtaque();
    void desactivarPowerUps();

    // Métodos para gestionar tanques
    void agregarTanque(Tanque* tanque);
    void eliminarTanque(Tanque* tanque);


    // Métodos para turnos
    bool verificarFinPartida();  // Verifica condiciones para finalizar turno
};

#endif // JUGADOR_H

