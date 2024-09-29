//
// Created by yerik on 9/29/24.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Window : public QMainWindow {
Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;

private:
Ui::MainWindow *ui;
};


#endif //WINDOW_H
