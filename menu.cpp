//
// Created by gabonm7 on 7/10/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Menu.h" resolved

#include "menu.h"
#include "ui_menuui.h"
#include "Game.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MenuInicial) {
    ui->setupUi(this);

    connect(ui->BtnStart, &QPushButton::clicked, this, &Menu::openGame);
}


void Menu::openGame() {
    Window *w = new Window();  // Crear una instancia de la ventana del juego
    w->show(); // Mostrar la ventana del juego
    this->close();
}




Menu::~Menu() {
    delete ui;
}
