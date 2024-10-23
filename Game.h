//
// Created by yerik on 9/29/24.
//
#ifndef WINDOW_H
#define WINDOW_H


#include "ui_gameui.h"
#include "Tanque.h"
#include "Bala.h"
#include <QMouseEvent>
#include "Grafo.h"
#include "Dijkstra.h"
#include "BFS.h"
#include "MovimientoAleatorio.h"
#include "AStar.h"
#include <QDebug>
#include <QPixmap>
#include <QRandomGenerator>
#include <QMainWindow>
#include <QTimer>
#include "Jugador.h"
#include "PowerUps.h"
#include <chrono>
#include <cstdlib>
#include <thread>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Window : public QMainWindow {
    Q_OBJECT

public:
    Grafo grafo=Grafo(20,40);
    Dijkstra objDijkstra=Dijkstra();
    BFS objBFS=BFS();
    AStar objAStar=AStar();
    MovimientoAleatorio mAleatorio = MovimientoAleatorio();
    Tanque Rojo1=Tanque(1,2,2,7,7);
    Tanque Rojo2=Tanque(2,2,2,9,7);
    Tanque Azul1=Tanque(3,1,4,12,7);
    Tanque Azul2=Tanque(4,1,4,14,7);
    Tanque Amarillo1=Tanque(5,2,2,7,32);
    Tanque Amarillo2=Tanque(6,2,2,9,32);
    Tanque Celeste1=Tanque(7,1,4,12,32);
    Tanque Celeste2=Tanque(8,1,4,14,32);
    Tanque Defecto=Tanque(0,0,0,0,0);
    Tanque* SelectedTank= &Defecto;
    Jugador Jugador1 = Jugador();
    Jugador Jugador2 = Jugador();



    explicit Window(QWidget *parent = nullptr);
    ~Window() override;
    void cellPressed(int row, int column, const QString& action);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void generarPowerUps(Jugador *jugador1, Jugador *jugador2);

    PowerUps generarPowerUpAleatorio();

    void actualizarPowerUpWidget(Jugador *jugador, const PowerUps &powerUp);

    void keyReleaseEvent(QKeyEvent *event) override;

    void setupEventFilter();

    bool eventFilter(QObject *obj, QEvent *event);

    void generateMapBorder();

    void generateRandomObstacles();

    void limpiarTablero();

    int iniciarMovimiento(const std::vector<std::pair<int, int>> &movimientos);

    int movimientoBala(const std::vector<std::pair<int, int>> &movimientos, int id, int dmg);

    void marcarCeldaComoBlanca(int x, int y);

    void limpiarCeldasVisitadas();

private:
    Ui::MainWindow *ui;
    bool dragging;  // Variable para controlar si se está arrastrando el mouse
    int lastSelectedRow;
    int lastSelectedColumn;
};

#endif // WINDOW_H

