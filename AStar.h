//
// Created by yerik on 10/14/24.
//

#ifndef ASTAR_H
#define ASTAR_H
#include <iosfwd>
#include <vector>


class AStar {
public:
    std::vector<std::pair<int, int>> aStar(const std::vector<std::vector<double>> &matriz, int src, int dest,
                                           int numColumnas);
};



#endif //ASTAR_H
