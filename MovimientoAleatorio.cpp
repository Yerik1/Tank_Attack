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
    const std::vector<std::vector<double>>& matrizAdyacencia, int srcX, int srcY, int destX, int destY) {
    std::vector<std::pair<int, int>> camino;  // Guardará las casillas del camino
    int dx = std::abs(destX - srcX);
    int dy = std::abs(destY - srcY);
    int sx = (srcX < destX) ? 1 : -1;
    int sy = (srcY < destY) ? 1 : -1;
    int err = dx - dy;
    int nextX=srcX;
    int nextY=srcY;



    while (true) {

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; nextX = srcX + sx; }
        if (e2 < dx) { err += dx; nextY = srcY + sy; }

        // Comprobar si hay camino usando la matriz de adyacencia
        int actualIndex = srcX * 40 + srcY;
        int siguienteIndex = nextX * 40 + nextY;

        // Solo agregar casillas que tengan una ruta en la matriz de adyacencia
        if (matrizAdyacencia[actualIndex][siguienteIndex] >= 0 ) {  // Verificar si hay ruta
            camino.push_back({srcX, srcY});  // Agregar la casilla actual al camino
        }

        // Verificar si llegamos al destino
        if (srcX == destX && srcY == destY) {
            break;
        }

        // Si encontramos un bloqueo (0 en la matriz de adyacencia), detenemos la exploración
        if (matrizAdyacencia[actualIndex][siguienteIndex] == 0) {
            break;
        }

        srcX = nextX;
        srcY = nextY;
    }

    return camino;
}


// Generar una posición aleatoria dentro de un radio dado
std::pair<int, int> MovimientoAleatorio::generarPosicionAleatoria(
    int srcX, int srcY, int radio, const std::vector<std::vector<double>>& matrizAdyacencia) {

    int nuevaX, nuevaY;
    bool obstaculo;
    do {
        // Generar dos números aleatorios dentro del rango -radio a +radio
        int offsetX = (std::rand() % (2 * radio + 1)) - radio;
        int offsetY = (std::rand() % (2 * radio + 1)) - radio;

        std::cout << "randCoords " << offsetX << " " << offsetY << std::endl;

        nuevaX = srcX + offsetX;
        nuevaY = srcY + offsetY;
        std::cout << "nuevaX: " << nuevaX << std::endl;
        std::cout << "nuevaY: " << nuevaY << std::endl;

        int newIndex = nuevaX * 40 + nuevaY;

        obstaculo = true;
        for (int i = 0; i <= 800; i++) {
            if (matrizAdyacencia[newIndex][i] == 1) {
                obstaculo = false;
                break;
            }
        }


        // Asegurarse de que la nueva posición esté dentro de los límites y tenga ruta accesible en la matriz de adyacencia
    } while ((nuevaX < 0 || nuevaX >= matrizAdyacencia.size() ||
              nuevaY < 0 || nuevaY >= matrizAdyacencia[0].size()) ||
             (obstaculo) ||  // Verificar si no hay ruta disponible
             (nuevaX == srcX && nuevaY == srcY)); // Repetir si la posición es bloqueada o es la misma posición

    return {nuevaX, nuevaY};
}


// Función principal que mueve el tanque
std::vector<std::pair<int, int>> MovimientoAleatorio::moverTanque(
    const std::vector<std::vector<double>>& matrizAdyacencia, int srcX, int srcY,
    int destX, int destY, int radio) {

    // Comprobar si hay camino usando la matriz de adyacencia
    int finalIndex = destX * 40 + destY;

    bool obstaculo = true;
    for (int i = 0; i <= 800; i++) {
        if (matrizAdyacencia[finalIndex][i] == 1) {
            obstaculo = false;
            break;
        }
    }



    std::vector<std::pair<int, int>> camino;
    if (!obstaculo) {  // Verificar si el destino es accesible en la matriz de adyacencia
        // Primer intento de línea de vista desde la posición inicial
        auto primerIntento = lineaVista(matrizAdyacencia, srcX, srcY, destX, destY);
        camino.insert(camino.end(), primerIntento.begin(), primerIntento.end());

        // Si no se llegó al destino, generar posición aleatoria
        if (primerIntento.empty() || (primerIntento.back() != std::make_pair(destX, destY))) {
            // Obtener la última posición del primer intento
            auto [ultimoX, ultimoY] = primerIntento.back();

            std::pair<int, int> nuevaPos;

            // Generar posiciones aleatorias hasta encontrar una válida

            nuevaPos = generarPosicionAleatoria(ultimoX, ultimoY, radio, matrizAdyacencia);


            camino.push_back(nuevaPos);  // Agregar la posición aleatoria válida

            // Imprimir la posición aleatoria generada
            std::cout << "Posición aleatoria generada: (" << nuevaPos.first << ", " << nuevaPos.second << ")" << std::endl;

            // Segundo intento desde la nueva posición aleatoria
            auto segundoIntento = lineaVista(matrizAdyacencia, nuevaPos.first, nuevaPos.second, destX, destY);
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


std::vector<std::pair<int, int>> MovimientoAleatorio::moverBala(
    const std::vector<std::vector<double>>& matrizAdyacencia,
    int ancho, int srcX, int srcY, int destX, int destY) {

    std::vector<std::pair<int, int>> camino;  // Guardará las casillas del camino
    int dx = std::abs(destX - srcX);
    int dy = std::abs(destY - srcY);
    int sx = (srcX < destX) ? 1 : -1;  // Direccion de movimiento en X
    int sy = (srcY < destY) ? 1 : -1;  // Direccion de movimiento en Y
    int err = dx - dy;
    bool moveX= false;
    bool moveY = false;


    int rebotes = 0;  // Contador de rebotes

    while (rebotes <= 3) {
        // Agregamos la posición actual al camino
        if(srcX!=0 && srcY!=0) {
            camino.push_back({srcX, srcY});
        }

        int nextX=srcX;
        int nextY=srcY;

        // Movimiento normal usando Bresenham si hay conexión válida
        int e2 = 2 * err;
        if (e2 > -dy) {
            nextX = srcX+sx;
        }
        if (e2 < dx) {
            nextY = srcY+sy;
        }

        // Comprobar límites
        if (nextX < 0 || nextX >= matrizAdyacencia.size() || nextY < 0 || nextY >= matrizAdyacencia[0].size()) {
            break;  // Si el siguiente paso está fuera de límites, terminamos
        }

        // Comprobar si hay camino usando la matriz de adyacencia
        int actualIndex = srcX * ancho + srcY;
        int siguienteIndex = nextX * ancho + nextY;

        // Si no hay conexión hacia el siguiente paso, intentamos un rebote
        if (matrizAdyacencia[actualIndex][siguienteIndex] == 0) {
            ++rebotes;
            std::cout << "rebote: " << nextY << ", "<< nextX << std::endl;

            // Invertimos la dirección en el eje correspondiente
            if (!moveY) {  // Preferimos el movimiento en X
                sx *= -1;  // Cambiamos dirección horizontal
            } else if (!moveX) {
                sy *= -1;  // Cambiamos dirección vertical
            }else {
                std::cout << "entro aqui"<< std::endl;
                if (matrizAdyacencia[(srcX) * ancho + srcY][(srcX+sx*-1) * ancho + srcY+sy] == 0) {
                    sy*=-1;
                }else{
                    sx*=-1;
                }
            moveX = false;
            moveY = false;
            }
        } else {
            // Movimiento normal usando Bresenham si hay conexión válida
            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                srcX += sx;
                moveX = true;
            }
            if (e2 < dx) {
                err += dx;
                srcY += sy;
                moveY = true;
            }
        }
    }

    std::reverse(camino.begin(), camino.end());

    // Imprimir el camino después de invertirlo
    std::cout << "Camino: ";
    for (auto it = camino.rbegin(); it != camino.rend(); ++it) {
        std::cout << "(" << it->second << ", " << it->first << ") ";
    }
    std::cout << std::endl;

    return camino;
}




