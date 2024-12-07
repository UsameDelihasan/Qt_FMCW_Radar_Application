    #include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <fftw3.h>
#include <fstream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    MainWindow w;
    w.show();
    return a.exec();
}
