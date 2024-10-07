//
// Created by gabonm7 on 7/10/24.
//

#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

#include "ui_menuui.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MenuInicial; }
QT_END_NAMESPACE

class Menu : public QMainWindow {
Q_OBJECT

public:

    void openGame ();
    explicit Menu(QWidget *parent = nullptr);
    ~Menu() override;

private:
    Ui::MenuInicial *ui{};
};


#endif //MENU_H
