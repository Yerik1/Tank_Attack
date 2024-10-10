//
// Created by yerik on 9/29/24.
//
#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "Grafo.h"
#include "Dijkstra.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Window : public QMainWindow {
    Q_OBJECT

public:
    Grafo grafo=Grafo(20,40);
    Dijkstra objDijkstra=Dijkstra();

    explicit Window(QWidget *parent = nullptr);
    ~Window() override;
    void cellPressed(int row, int column, const QString& action);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void generateMapBorder();

    void generateRandomObstacles();

private:
    Ui::MainWindow *ui;
    bool dragging;  // Variable para controlar si se está arrastrando el mouse
    int lastSelectedRow;
    int lastSelectedColumn;
};

#endif // WINDOW_H

