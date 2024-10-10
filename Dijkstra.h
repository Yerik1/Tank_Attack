//
// Created by yerik on 10/10/24.
//


#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#define INF INT_MAX

class Dijkstra {
public:
    int minDistance(const std::vector<int> &dist, const std::vector<bool> &processed, int V);

    void printPath(const std::vector<int> &parent, int j);

    void dijkstra(const std::vector<std::vector<int>> &matriz, int src, int dest, int numColumnas);
};



#endif //DIJKSTRA_H
