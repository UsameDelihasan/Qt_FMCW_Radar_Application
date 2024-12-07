/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *plot2;
    QCustomPlot *mixPlot;
    QCustomPlot *targetPlot2;
    QCustomPlot *targetPlot1;
    QSlider *slider;
    QLineEdit *range1Input;
    QLineEdit *range2Input;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *valueLabelBW;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1282, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        plot2 = new QCustomPlot(centralwidget);
        plot2->setObjectName("plot2");
        plot2->setGeometry(QRect(730, 280, 531, 171));
        mixPlot = new QCustomPlot(centralwidget);
        mixPlot->setObjectName("mixPlot");
        mixPlot->setGeometry(QRect(120, 280, 531, 171));
        targetPlot2 = new QCustomPlot(centralwidget);
        targetPlot2->setObjectName("targetPlot2");
        targetPlot2->setGeometry(QRect(730, 70, 531, 161));
        targetPlot1 = new QCustomPlot(centralwidget);
        targetPlot1->setObjectName("targetPlot1");
        targetPlot1->setGeometry(QRect(120, 70, 531, 161));
        slider = new QSlider(centralwidget);
        slider->setObjectName("slider");
        slider->setGeometry(QRect(220, 470, 511, 20));
        slider->setOrientation(Qt::Horizontal);
        range1Input = new QLineEdit(centralwidget);
        range1Input->setObjectName("range1Input");
        range1Input->setGeometry(QRect(220, 500, 111, 21));
        range2Input = new QLineEdit(centralwidget);
        range2Input->setObjectName("range2Input");
        range2Input->setGeometry(QRect(220, 530, 111, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 50, 191, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(920, 50, 171, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(270, 250, 201, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(950, 250, 81, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(120, 470, 71, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(120, 500, 71, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(120, 530, 71, 16));
        valueLabelBW = new QLabel(centralwidget);
        valueLabelBW->setObjectName("valueLabelBW");
        valueLabelBW->setGeometry(QRect(360, 500, 191, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1282, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        range1Input->setText(QString());
        range2Input->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Rx and Tx values of Target 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Rx and Tx values of Target 2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Mixed values of Target1 and Target 2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "FFT signal", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Bandwidth : ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Range 1 ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Range 2 :   ", nullptr));
        valueLabelBW->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
