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

    void printPath(const std::vector<int> &parent, int j);

    std::vector<std::pair<int, int>> dijkstra(const std::vector<std::vector<double>> &matriz, int src, int dest, int numColumnas);
};



#endif //DIJKSTRA_H
