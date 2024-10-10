//
// Created by yerik on 10/7/24.
//

#ifndef GRAFO_H
#define GRAFO_H



#include <vector>
#include <iostream>

class Grafo {
public:
    Grafo(int n, int m);
    void agregarObstaculo(int fila, int col);

    void actualizarMatriz(int fila, int col);

    void mostrarMatriz();

    std::vector<std::vector<int>> getMatriz() const;

private:
    int N, M;
    std::vector<std::vector<int>> matriz;
    std::vector<std::vector<bool>> obstaculos;
};



#endif //GRAFO_H
