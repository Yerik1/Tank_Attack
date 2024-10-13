//
// Created by yerik on 10/12/24.
//

#ifndef BFS_H
#define BFS_H



#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class BFS {
public:
    void printPath(const std::vector<int>& parent, int j);
    std::vector<std::pair<int, int>> bfs(const std::vector<std::vector<double>>& matriz, int src, int dest, int numColumnas);
};



#endif //BFS_H
