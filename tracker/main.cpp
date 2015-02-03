#include "mainwindow.h"
#include "screenshot.hpp"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//     MainWindow w;
//     w.show();

    Screenshot screenshot;
    // screenshot.print_color_pixel(50, 50);//coordone du pixel qu'on veut.
    screenshot.show();

    return a.exec();
}
