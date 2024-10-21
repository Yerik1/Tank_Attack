//
// Created by yerik on 10/14/24.
//

#include "AStar.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

#define INF INT_MAX

// Estructura para representar un nodo en la cola de prioridad
struct Nodo {
    int id;           // Índice del nodo
    double g;         // Costo desde el inicio hasta este nodo
    double f;         // Costo total estimado (g + heurística)
    Nodo(int id, double g, double f) : id(id), g(g), f(f) {}

    // Sobrecarga del operador para usar Nodo en la cola de prioridad
    bool operator>(const Nodo& otro) const {
        return f > otro.f;
    }
};

// Función heurística: Distancia Manhattan entre dos nodos
double heuristica(int src, int dest, int numColumnas) {
    int srcX = src / numColumnas, srcY = src % numColumnas;
    int destX = dest / numColumnas, destY = dest % numColumnas;
    return std::abs(srcX - destX) + std::abs(srcY - destY);
}

std::vector<std::pair<int, int>> AStar::aStar(const std::vector<std::vector<double>>& matriz, int src, int dest, int numColumnas) {
    int numNodos = matriz.size();
    std::vector<double> g(numNodos, INF);  // Costo desde el inicio hasta cada nodo
    std::vector<int> parent(numNodos, -1); // Para reconstruir el camino
    std::vector<bool> visited(numNodos, false);

    g[src] = 0.0;

    // Cola de prioridad (min-heap) basada en el costo total estimado (f)
    std::priority_queue<Nodo, std::vector<Nodo>, std::greater<Nodo>> pq;
    pq.emplace(src, 0.0, heuristica(src, dest, numColumnas));

    while (!pq.empty()) {
        Nodo actual = pq.top();
        pq.pop();

        int u = actual.id;
        if (visited[u]) continue;
        visited[u] = true;

        if (u == dest) break;  // Si llegamos al destino, terminamos

        for (int v = 0; v < numNodos; ++v) {
            if (matriz[u][v] > 0 && !visited[v]) {
                double nuevoG = g[u] + matriz[u][v];
                if (nuevoG < g[v]) {
                    g[v] = nuevoG;
                    double f = nuevoG + heuristica(v, dest, numColumnas);
                    parent[v] = u;
                    pq.emplace(v, nuevoG, f);
                }
            }
        }
    }

    std::vector<std::pair<int, int>> camino;
    if (g[dest] == INF) {
        std::cout << "No hay camino desde (" << src / numColumnas << ", " << src % numColumnas << ")"
                  << " a (" << dest / numColumnas << ", " << dest % numColumnas << ")" << std::endl;
    } else {
        std::cout << "Distancia mínima desde (" << src / numColumnas << ", " << src % numColumnas << ")"
                  << " a (" << dest / numColumnas << ", " << dest % numColumnas << ") es " << g[dest] << std::endl;
        std::cout << "Camino (coordenadas): ";

        // Reconstruir el camino desde el destino al origen
        for (int v = dest; v != -1; v = parent[v]) {
            camino.emplace_back(v / numColumnas, v % numColumnas);
        }

        // Imprimir el camino en orden correcto
        for (auto it = camino.rbegin(); it != camino.rend(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << std::endl;
    }
    return camino;
}
