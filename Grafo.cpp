//
// Created by yerik on 10/7/24.
//

#include "Grafo.h"

#include <stack>

Grafo::Grafo(int n, int m) : N(n), M(m) {
    // Inicializar matriz de adyacencia
    matriz.resize(N * M, std::vector<double>(N * M, 0));
    obstaculos.resize(N, std::vector<bool>(M, false)); // No hay obstáculos inicialmente

    // Crear conexiones entre posiciones adyacentes y diagonales
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int pos = i * M + j;
            // Conectar con la posición de arriba
            if (i > 0 && !obstaculos[i-1][j]) matriz[pos][(i - 1) * M + j] = 1;
            // Conectar con la posición de abajo
            if (i < N - 1 && !obstaculos[i+1][j]) matriz[pos][(i + 1) * M + j] = 1;
            // Conectar con la posición de la izquierda
            if (j > 0 && !obstaculos[i][j-1]) matriz[pos][i * M + (j - 1)] = 1;
            // Conectar con la posición de la derecha
            if (j < M - 1 && !obstaculos[i][j+1]) matriz[pos][i * M + (j + 1)] = 1;

            // Conectar con las posiciones diagonales
            // Arriba a la izquierda
            if (i > 0 && j > 0 && !obstaculos[i-1][j] && !obstaculos[i][j-1])
                matriz[pos][(i - 1) * M + (j - 1)] = 1.5;
            // Arriba a la derecha
            if (i > 0 && j < M - 1 && !obstaculos[i-1][j] && !obstaculos[i][j+1])
                matriz[pos][(i - 1) * M + (j + 1)] = 1.5;
            // Abajo a la izquierda
            if (i < N - 1 && j > 0 && !obstaculos[i+1][j] && !obstaculos[i][j-1])
                matriz[pos][(i + 1) * M + (j - 1)] = 1.5;
            // Abajo a la derecha
            if (i < N - 1 && j < M - 1 && !obstaculos[i+1][j] && !obstaculos[i][j+1])
                matriz[pos][(i + 1) * M + (j + 1)] = 1.5;
        }
    }
}

// Función para agregar un obstáculo en una posición específica
void Grafo::agregarObstaculo(int fila, int col) {
    obstaculos[fila][col] = true;
    actualizarMatriz(fila, col);
}

void Grafo::actualizarMatriz(int fila, int col) {
    int pos = fila * M + col;

    // Poner en 0 las conexiones hacia las 8 direcciones (eliminar todas las conexiones alrededor del obstáculo)
    // Arriba
    if (fila > 0) matriz[pos][(fila - 1) * M + col] = matriz[(fila - 1) * M + col][pos] = 0;
    // Abajo
    if (fila < N - 1) matriz[pos][(fila + 1) * M + col] = matriz[(fila + 1) * M + col][pos] = 0;
    // Izquierda
    if (col > 0) matriz[pos][fila * M + (col - 1)] = matriz[fila * M + (col - 1)][pos] = 0;
    // Derecha
    if (col < M - 1) matriz[pos][fila * M + (col + 1)] = matriz[fila * M + (col + 1)][pos] = 0;
    // Arriba a la izquierda
    if (fila > 0 && col > 0) matriz[pos][(fila - 1) * M + (col - 1)] = matriz[(fila - 1) * M + (col - 1)][pos] = 0;
    // Arriba a la derecha
    if (fila > 0 && col < M - 1) matriz[pos][(fila - 1) * M + (col + 1)] = matriz[(fila - 1) * M + (col + 1)][pos] = 0;
    // Abajo a la izquierda
    if (fila < N - 1 && col > 0) matriz[pos][(fila + 1) * M + (col - 1)] = matriz[(fila + 1) * M + (col - 1)][pos] = 0;
    // Abajo a la derecha
    if (fila < N - 1 && col < M - 1) matriz[pos][(fila + 1) * M + (col + 1)] = matriz[(fila + 1) * M + (col + 1)][pos] = 0;

    if (fila > 0) {
        int pos_arriba = (fila - 1) * M + col;
        // Arriba a la izquierda: verificar si la casilla de la izquierda (fila-1, col-1) debe mantenerse
        if (col > 0 ) {
            matriz[pos_arriba][(fila) * M + (col - 1)] = matriz[(fila) * M + (col - 1)][pos_arriba] = 0;
        }
        // Arriba a la derecha: verificar si la casilla de la derecha (fila-1, col+1) debe mantenerse
        if (col < M - 1 ) {
            matriz[pos_arriba][(fila) * M + (col + 1)] = matriz[(fila) * M + (col + 1)][pos_arriba] = 0;
        }
    }

    // Casilla abajo (fila+1, col)
    if (fila < N - 1) {
        int pos_abajo = (fila + 1) * M + col;
        // Abajo a la izquierda: verificar si la casilla de la izquierda (fila+1, col-1) debe mantenerse
        if (col > 0 ) {
            matriz[pos_abajo][(fila) * M + (col - 1)] = matriz[(fila) * M + (col - 1)][pos_abajo] = 0;
        }
        // Abajo a la derecha: verificar si la casilla de la derecha (fila+1, col+1) debe mantenerse
        if (col < M - 1 ) {
            matriz[pos_abajo][(fila) * M + (col + 1)] = matriz[(fila) * M + (col + 1)][pos_abajo] = 0;
        }
    }

    // Casilla izquierda (fila, col-1)
    if (col > 0) {
        int pos_izquierda = fila * M + (col - 1);
        // Arriba a la izquierda: verificar si la casilla de arriba (fila-1, col-1) debe mantenerse
        if (fila > 0 ) {
            matriz[pos_izquierda][(fila - 1) * M + (col)] = matriz[(fila - 1) * M + (col)][pos_izquierda] = 0;
        }
        // Abajo a la izquierda: verificar si la casilla de abajo (fila+1, col-1) debe mantenerse
        if (fila < N - 1 ) {
            matriz[pos_izquierda][(fila + 1) * M + (col)] = matriz[(fila + 1) * M + (col)][pos_izquierda] = 0;
        }
    }

    // Casilla derecha (fila, col+1)
    if (col < M - 1) {
        int pos_derecha = fila * M + (col + 1);
        // Arriba a la derecha: verificar si la casilla de arriba (fila-1, col+1) debe mantenerse
        if (fila > 0 ) {
            matriz[pos_derecha][(fila - 1) * M + (col )] = matriz[(fila ) * M + (col + 1)][pos_derecha] = 0;
        }
        // Abajo a la derecha: verificar si la casilla de abajo (fila+1, col+1) debe mantenerse
        if (fila < N - 1 ) {
            matriz[pos_derecha][(fila + 1) * M + (col )] = matriz[(fila ) * M + (col + 1)][pos_derecha] = 0;
        }
    }
}



// Mostrar la matriz de adyacencia
void Grafo::mostrarMatriz() {
    for (int i = 0; i < N * M; ++i) {
        // Obtener las coordenadas (fila, columna) de la casilla i
        int fila_i = i / M;
        int col_i = i % M;

        std::cout << "La casilla (" << fila_i << "," << col_i << ") está conectada con: ";
        bool tieneConexion = false;

        for (int j = 0; j < N * M; ++j) {
            if (matriz[i][j] >= 1) {
                // Obtener las coordenadas (fila, columna) de la casilla j
                int fila_j = j / M;
                int col_j = j % M;
                std::cout << "(" << fila_j << "," << col_j << ") "; // Mostrar las coordenadas de la casilla conectada
                tieneConexion = true;
            }
        }
        if (!tieneConexion) {
            std::cout << "ninguna";
        }
        std::cout << std::endl;
    }
}

#include <queue>
#include <vector>

bool Grafo::esConectado() {
    // Número total de celdas en el tablero
    int totalCeldas = N * M;
    std::vector<bool> visitado(totalCeldas, false);  // Control de celdas visitadas

    // Buscar la primera celda libre (sin obstáculo) para iniciar la búsqueda
    int inicio = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!obstaculos[i][j]) {  // Encontrar una celda accesible
                inicio = i * M + j;
                break;
            }
        }
        if (inicio != -1) break;
    }

    if (inicio == -1) return false;  // No hay celdas libres (caso borde)

    // BFS desde la celda inicial
    std::queue<int> cola;
    cola.push(inicio);
    visitado[inicio] = true;

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        // Revisar todas las celdas conectadas desde 'actual'
        for (int vecino = 0; vecino < totalCeldas; ++vecino) {
            if (matriz[actual][vecino] >= 1 && !visitado[vecino]) {  // Hay conexión y no ha sido visitada
                cola.push(vecino);
                visitado[vecino] = true;
            }
        }
    }

    // Verificar si todas las celdas libres fueron visitadas
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!obstaculos[i][j] && !visitado[i * M + j]) {
                return false;  // Hay una celda accesible no conectada
            }
        }
    }

    return true;  // Todas las celdas libres están conectadas
}


void Grafo::resetObstaculos() {
    for (int i = 1; i < N-1; ++i) {
        for (int j = 1; j < M-1; ++j) {
            obstaculos[i][j] = false;
            actualizarMatriz(i,j);
        }
    }

}

std::vector<std::vector<double>> Grafo::getMatriz() const {
    return matriz;
}
std::vector<std::vector<bool>> Grafo::getObstaculos() const {
    return obstaculos;
}
