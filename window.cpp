//
// Created by yerik on 9/29/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "window.h"
#include "ui_gameui.h"


Window::Window(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

Window::~Window() {
    delete ui;
}
