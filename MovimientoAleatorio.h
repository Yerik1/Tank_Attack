//
// Created by yerik on 10/12/24.
//

#ifndef MOVIMIENTOALEATORIO_H
#define MOVIMIENTOALEATORIO_H



#include <vector>
#include <iostream>
#include <cstdlib>   // Para std::rand y std::srand
#include <ctime>     // Para inicializar la semilla de aleatoriedad
#include <cmath>     // Para cálculos de distancia
#include <algorithm>

class MovimientoAleatorio {
public:
    MovimientoAleatorio();  // Constructor para inicializar la semilla aleatoria
    std::vector<std::pair<int, int>> moverTanque(
        const std::vector<std::vector<bool>>& matriz,
        int srcX, int srcY, int destX, int destY, int radio);

    std::vector<std::pair<int, int>> moverBala(const std::vector<std::vector<double>> &matriz, int ancho, int srcX, int srcY,
                                               int destX,
                                               int destY);

private:
    std::vector<std::pair<int, int>> lineaVista(const std::vector<std::vector<bool>>& matriz,
                    int srcX, int srcY, int destX, int destY);
    std::pair<int, int> generarPosicionAleatoria(int srcX, int srcY, int radio, const std::vector<std::vector<bool>>& matriz);
};



#endif //MOVIMIENTOALEATORIO_H
