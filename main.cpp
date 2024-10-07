//
// Created by yerik on 9/29/24.
//

#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();
    return a.exec();
}