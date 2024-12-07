#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcustomplot.h"
#include <QMainWindow>
#include <QtWidgets>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void processAndDisplayData(QCustomPlot *customPlot, QSlider *slider, QLineEdit *range1Input, QLineEdit *range2Input, QLabel *valueLabel);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
