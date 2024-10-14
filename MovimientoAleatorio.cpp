//
// Created by yerik on 10/12/24.
//

#include "MovimientoAleatorio.h"

// Constructor para inicializar la semilla aleatoria
MovimientoAleatorio::MovimientoAleatorio() {
    std::srand(std::time(0));  // Inicializar la semilla aleatoria
}

// Función para verificar y registrar todas las casillas en línea de vista
std::vector<std::pair<int, int>> MovimientoAleatorio::lineaVista(
    const std::vector<std::vector<bool>>& matriz, int srcX, int srcY, int destX, int destY) {

    std::vector<std::pair<int, int>> camino;  // Guardará las casillas del camino
    int dx = std::abs(destX - srcX);
    int dy = std::abs(destY - srcY);
    int sx = (srcX < destX) ? 1 : -1;
    int sy = (srcY < destY) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        // Solo agregar casillas que no tengan obstáculos (matriz[srcX][srcY] == false)
        if (!matriz[srcX][srcY]) { // Cambiado para que incluya solo casillas sin obstáculos
            camino.push_back({srcX, srcY});  // Agregar la casilla actual al camino
        }

        // Verificar si llegamos al destino
        if (srcX == destX && srcY == destY) {
            break;
        }

        // Si encontramos un obstáculo (true en la matriz), detenemos la exploración
        if (matriz[srcX][srcY] == true) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; srcX += sx; }
        if (e2 < dx) { err += dx; srcY += sy; }
    }

    return camino;
}

// Generar una posición aleatoria dentro de un radio dado
std::pair<int, int> MovimientoAleatorio::generarPosicionAleatoria(
    int srcX, int srcY, int radio, const std::vector<std::vector<bool>>& matriz) {

    int nuevaX, nuevaY;
    do {
        // Generar dos números aleatorios dentro del rango -radio a +radio
        int offsetX = (std::rand() % (2 * radio + 1)) - radio;
        int offsetY = (std::rand() % (2 * radio + 1)) - radio;

        std::cout << "randCoords " << offsetX << " " << offsetY << std::endl;

        nuevaX = srcX + offsetX;
        nuevaY = srcY + offsetY;
        std::cout << "nuevaX: " << nuevaX << std::endl;
        std::cout << "nuevaY: " << nuevaY << std::endl;

        // Asegurarse de que la nueva posición esté dentro de los límites
    } while ((nuevaX < 0 || nuevaX >= matriz.size() ||
              nuevaY < 0 || nuevaY >= matriz[0].size()) ||
             (matriz[nuevaX][nuevaY] == true) ||
             (nuevaX == srcX && nuevaY == srcY)); // Repetir si hay un obstáculo o es la misma posición

    return {nuevaX, nuevaY};
}

// Función principal que mueve el tanque
std::vector<std::pair<int, int>> MovimientoAleatorio::moverTanque(
    const std::vector<std::vector<bool>>& matriz, int srcX, int srcY,
    int destX, int destY, int radio) {

    std::vector<std::pair<int, int>> camino;
    if(matriz[destX][destY] == false) {
        // Primer intento de línea de vista desde la posición inicial
        auto primerIntento = lineaVista(matriz, srcX, srcY, destX, destY);
        camino.insert(camino.end(), primerIntento.begin(), primerIntento.end());

        // Si no se llegó al destino, generar posición aleatoria
        if (primerIntento.empty() || (primerIntento.back() != std::make_pair(destX, destY))) {
            // Obtener la última posición del primer intento
            auto [ultimoX, ultimoY] = primerIntento.back();

            std::pair<int, int> nuevaPos;

            // Generar posiciones aleatorias hasta encontrar una válida
            do {
                nuevaPos = generarPosicionAleatoria(ultimoX, ultimoY, radio, matriz);
            } while (matriz[nuevaPos.first][nuevaPos.second] || nuevaPos == std::make_pair(srcX, srcY));

            camino.push_back(nuevaPos);  // Agregar la posición aleatoria válida

            // Imprimir la posición aleatoria generada
            std::cout << "Posición aleatoria generada: (" << nuevaPos.first << ", " << nuevaPos.second << ")" << std::endl;

            // Segundo intento desde la nueva posición aleatoria
            auto segundoIntento = lineaVista(matriz, nuevaPos.first, nuevaPos.second, destX, destY);
            camino.insert(camino.end(), segundoIntento.begin(), segundoIntento.end());
        }

        // Invertir el camino para que esté en orden correcto (inicio a fin)
        std::reverse(camino.begin(), camino.end());

        // Imprimir el camino después de invertirlo
        std::cout << "Camino: ";
        for (auto it = camino.rbegin(); it != camino.rend(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << std::endl;

    }

    return camino;
}

