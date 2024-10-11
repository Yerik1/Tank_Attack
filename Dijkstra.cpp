//
// Created by yerik on 10/10/24.
//

#include "Dijkstra.h"
#define INF INT_MAX

#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX

// Función para obtener el camino reconstruido desde el nodo fuente hasta el destino
void Dijkstra::printPath(const std::vector<int>& parent, int j) {
    if (parent[j] == -1) {
        return;  // Caso base: hemos llegado al nodo fuente
    }

    printPath(parent, parent[j]);  // Recorremos recursivamente hasta el nodo fuente
    std::cout << j << " ";  // Imprimimos el nodo en el camino
}

std::vector<std::pair<int, int>> Dijkstra::dijkstra(const std::vector<std::vector<double>>& matriz, int src, int dest, int numColumnas) {
    int numNodos = matriz.size();

    // Inicialización
    std::vector<double> dist(numNodos, INT_MAX); // Usar infinito para distancias no alcanzables
    std::vector<int> parent(numNodos, -1);
    std::vector<bool> visited(numNodos, false);
    dist[src] = 0.0;

    // Cola de prioridad (min-heap), ahora usando double para las distancias
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    pq.push({0.0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < numNodos; ++v) {
            if (matriz[u][v] > 0 && !visited[v]) {
                double nuevaDist = dist[u] + matriz[u][v];
                if (nuevaDist < dist[v]) {
                    dist[v] = nuevaDist;
                    parent[v] = u;
                    pq.push({dist[v], v}); // Usar la nueva distancia como clave en la cola de prioridad
                }
            }
        }
    }

    // Convertir nodos de origen y destino a coordenadas
    int srcX = src / numColumnas;
    int srcY = src % numColumnas;
    int destX = dest / numColumnas;
    int destY = dest % numColumnas;

    // Imprimir la distancia y el camino
    if (dist[dest] == INT_MAX) {
        std::cout << "No hay camino desde la casilla (" << srcX << ", " << srcY << ")"
                  << " a la casilla (" << destX << ", " << destY << ")" << std::endl;
    } else {
        std::cout << "Distancia mínima desde la casilla (" << srcX << ", " << srcY << ")"
                  << " a la casilla (" << destX << ", " << destY << ") es " << dist[dest] << std::endl;
        std::cout << "Camino (coordenadas): ";

        // Reconstruir el camino desde el destino al origen
        std::vector<std::pair<int, int>> camino;
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
        return camino;
    }

}


