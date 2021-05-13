#include "mainwindow.h"

#include <QApplication>
#include <QLineEdit>
#include <QString>

#include <string>

using namespace std;

const extern int hw3_2_num1 = 3;
const extern int hw3_2_num2 = 7;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
//
