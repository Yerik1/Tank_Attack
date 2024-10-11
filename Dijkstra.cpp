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

void Dijkstra::dijkstra(const std::vector<std::vector<double>>& matriz, int src, int dest, int numColumnas) {
    int numNodos = matriz.size();

    // Inicialización
    std::vector<int> dist(numNodos, INT_MAX);
    std::vector<int> parent(numNodos, -1);
    std::vector<bool> visited(numNodos, false);
    dist[src] = 0;

    // Cola de prioridad (min-heap)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < numNodos; ++v) {
            if (matriz[u][v] > 0 && !visited[v]) {
                int nuevaDist = dist[u] + matriz[u][v];
                if (nuevaDist < dist[v]) {
                    dist[v] = nuevaDist;
                    parent[v] = u;
                    pq.push({dist[v], v});
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

        for (int v = dest; v != -1; v = parent[v]) {
            int x = v / numColumnas;
            int y = v % numColumnas;
            std::cout << "(" << x << ", " << y << ") ";
        }
        std::cout << std::endl;
    }
}

