//
// Created by yerik on 10/12/24.
//

#include "BFS.h"



// Implementación de BFS para encontrar el camino más corto en una matriz de adyacencia
std::vector<std::pair<int, int>> BFS::bfs(const std::vector<std::vector<double>>& matriz, int src, int dest, int numColumnas) {
    int numNodos = matriz.size();

    // Inicialización
    std::vector<int> dist(numNodos, INT_MAX);  // Usar infinito como distancia inicial
    std::vector<int> parent(numNodos, -1);  // Para reconstruir el camino
    std::vector<bool> visited(numNodos, false);  // Para marcar los nodos visitados

    std::queue<int> q;  // Cola para BFS
    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    // Bucle principal de BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Explorar los nodos vecinos
        for (int v = 0; v < numNodos; ++v) {
            if (matriz[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);  // Agregar nodo a la cola

                if (v == dest) {
                    break;  // Salir si encontramos el destino
                }
            }
        }
    }

    // Convertir nodos a coordenadas
    int srcX = src / numColumnas;
    int srcY = src % numColumnas;
    int destX = dest / numColumnas;
    int destY = dest % numColumnas;
    std::vector<std::pair<int, int>> camino;

    // Imprimir la distancia y el camino
    if (dist[dest] == INT_MAX) {
        std::cout << "No hay camino desde la casilla (" << srcX << ", " << srcY << ")"
                  << " a la casilla (" << destX << ", " << destY << ")" << std::endl;
    } else {
        std::cout << "Distancia mínima desde la casilla (" << srcX << ", " << srcY << ")"
                  << " a la casilla (" << destX << ", " << destY << ") es " << dist[dest] << std::endl;
        std::cout << "Camino (coordenadas): ";

        // Reconstruir el camino desde el destino al origen
        for (int v = dest; v != -1; v = parent[v]) {
            int x = v / numColumnas;
            int y = v % numColumnas;
            camino.push_back({x, y});
        }

        // Imprimir el camino en orden correcto (desde origen a destino)
        for (auto it = camino.rbegin(); it != camino.rend(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << std::endl;
    }
    return camino;
}
