//
// Created by gabonm7 on 22/10/24.
//
#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "Tanque.h"
#include "PowerUps.h"
#include <queue>

class Jugador {
private:
    int numeroTanques;          // Número de tanques activos
    std::vector<Tanque*> tanques;  // Vector de punteros a tanques
    std::queue<PowerUps> colaPowerUps;
    bool powerUpDobleTurno;     // PowerUp de doble turno activo
    bool powerUpPrecisionMov;   // PowerUp de precisión de movimiento activo
    bool powerUpPrecisionAtaque;// PowerUp de precisión de ataque activo
    bool powerUpPoderAtaque;    // PowerUp de poder de ataque activo
    bool turnoActivo;           // Indica si es el turno del jugador
    QLabel *Imagen;
    bool enMovimiento;

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
    QLabel *getImagen() const;
    std::queue<PowerUps> getColaPowerUps() const;
    bool getEnMovimiento() const;

    // Setters
    void setTurnoActivo(bool activo);
    void activarPowerUpDobleTurno();
    void desactivarPowerUpDobleTurno();
    void activarPowerUpPrecisionMov();
    void activarPowerUpPrecisionAtaque();
    void activarPowerUpPoderAtaque();
    void desactivarPowerUps();

    void desactivarPowerUpPresicionMovimiento();

    void desactivarPowerUpPresicionAtaque();

    void desactivarPowerUpPoderAtaque();

    void setImagen(QLabel *imagen);
    void setEnMovimiento (bool movimiento);

    // Métodos para gestionar tanques
    void agregarTanque(Tanque* tanque);
    void eliminarTanque(Tanque* tanque);


    // Métodos para turnos
    bool verificarFinPartida();  // Verifica condiciones para finalizar turno

    // Métodos para power-ups
    void agregarPowerUp(const PowerUps& powerUp);  // Añadir un power-up a la cola
    PowerUps usarPowerUp();                        // Usar el siguiente power-up en la cola
    bool hayPowerUps() const;

    PowerUps returnTop();
};

#endif // JUGADOR_H

