#include <QApplication>

#include "MainWindow.hpp"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    return a.exec();
}
