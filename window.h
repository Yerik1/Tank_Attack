//
// Created by yerik on 9/29/24.
//
#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Window : public QMainWindow {
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;

    void cellPressed(int row, int column);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    bool dragging;  // Variable para controlar si se está arrastrando el mouse
    int lastSelectedRow;
    int lastSelectedColumn;
};

#endif // WINDOW_H

