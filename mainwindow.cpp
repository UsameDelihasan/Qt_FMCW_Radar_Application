#include "mainwindow.h"
#include "fftw3.h"
#include "ui_mainwindow.h"
#include <complex>
#include <iostream>

#include <QDebug>
#include <QScrollBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("FFT");

    ui->slider->setRange(1,10);
    ui->slider->setValue(5);



    QObject::connect(ui->slider, &QSlider::valueChanged, [=]() {
        processAndDisplayData(ui->plot2, ui->slider, ui->range1Input, ui->range2Input,ui->valueLabelBW);
    });

    QObject::connect(ui->range1Input, &QLineEdit::editingFinished, [=]() {
        processAndDisplayData(ui->plot2, ui->slider, ui->range1Input, ui->range2Input,ui->valueLabelBW);
    });

    QObject::connect(ui->range2Input, &QLineEdit::editingFinished, [=]() {
        processAndDisplayData(ui->plot2, ui->slider, ui->range1Input, ui->range2Input,ui->valueLabelBW);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::processAndDisplayData(QCustomPlot *customPlot, QSlider *slider, QLineEdit *range1Input, QLineEdit *range2Input, QLabel *valueLabel)
{

    QMainWindow mainWindow;





    double Range_max = 200;
    double c = 3e8;
    double R1 = ui->range1Input->text().toDouble();
    double R2 = ui->range2Input->text().toDouble();

    double Tsweep = 5.5;
    int Nr = 1024;

    double RR = R2 - R1;
    std::cout << "Range resolution: " << RR << " m\n";
    std::cout << "Minimum required bandwidth for distinguishability: " << c / (2 * RR) << " Hz\n";



    double B = ui->slider->value()*10e6;

    QString valueText = QString::number(ui->slider->value()*10);
    valueLabel->setText("Bandwidth Value: " + valueText + "MHz");



    double range_res = c / (2 * B);
    double Tchirp = Tsweep * (2 * Range_max / c);
    double slope = B / Tchirp;
    double fc = 77e9;


    QVector<double> Rx1(Nr);
    QVector<double> Tx1(Nr);
    QVector<double> Rx2(Nr);
    QVector<double> Tx2(Nr);
    QVector<double> Mix1(Nr);
    QVector<double> Mix2(Nr);
    QVector<double> Mix(Nr);

    QVector<double> t(Nr);
    for (int i = 0; i < Nr; ++i) {
        t[i] = i * Tchirp / Nr;
    }

    std::vector<double> FFT_single_side_mix(Nr / 2 - 1, 0.0);
    std::vector<double> range_values(Nr / 2 - 1, 0.0);

    for (int i = 0; i < Nr; ++i) {
        double td1 = 2 * R1 / c;
        double td2 = 2 * R2 / c;

         Tx1[i] = cos(2 * M_PI * (fc * t[i] + slope * t[i] * t[i] / 2));
         Rx1[i] = cos(2 * M_PI * (fc * (t[i] - td1) + slope * (t[i] - td1) * (t[i] - td1) / 2));

         Tx2[i] = cos(2 * M_PI * (fc * t[i] + slope * t[i] * t[i] / 2));
         Rx2[i] = cos(2 * M_PI * (fc * (t[i] - td2) + slope * (t[i] - td2) * (t[i] - td2) / 2));


         Mix1[i] = Tx1[i] * Rx1[i];
         Mix2[i] = Tx2[i] * Rx2[i];

         Mix[i] = Mix1[i] + Mix2[i];

    }



    std::vector<std::complex<double>> FFT_mix(Nr);
    for (int i = 0; i < Nr; ++i) {
        FFT_mix[i] = std::complex<double>(Mix[i], 0);
    }

    // FFT hesaplamaları
    fftw_complex* in = reinterpret_cast<fftw_complex*>(FFT_mix.data());
    fftw_complex* out = reinterpret_cast<fftw_complex*>(FFT_mix.data());

    fftw_plan plan = fftw_plan_dft_1d(Nr, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    for (int i = 0; i < Nr / 2 - 1; ++i) {
        FFT_single_side_mix[i] = std::abs(std::complex<double>(out[i][0], out[i][1]));
        range_values[i] = i * range_res;
    }

    // Rest of the plotting and visualization code

    for (int i = 0; i < Range_max; ++i) {
        std::cout << "Range: " << range_values[i] << " m, FFT Value: " << FFT_single_side_mix[i] << std::endl;
    }



    QVector<double> xData, yData;
    for (int i = 0; i < Range_max; ++i) {
        xData.append(range_values[i]);
        yData.append(FFT_single_side_mix[i]);
    }



    QVector<double> aa = {1, 2, 3, 4};
    QVector<double> b = {4, 5, 3, 2};

    // Target1 verileri çizgi grafiği olarak ekler (mavi renk)
    ui->targetPlot1->addGraph();
    ui->targetPlot1->graph(0)->setData(t, Rx1);
    ui->targetPlot1->graph(0)->setPen(QPen(Qt::red));
    ui->targetPlot1->xAxis->setLabel("Time");
    ui->targetPlot1->yAxis->setLabel("Amplitude");


    ui->targetPlot1->addGraph();
    ui->targetPlot1->graph(1)->setData(t, Tx1);
    ui->targetPlot1->graph(1)->setPen(QPen(Qt::blue));
    ui->targetPlot1->xAxis->setRange(0, Range_max); // X ekseni aralığı
    ui->targetPlot1->yAxis->setRange(0, 1);

    ui->targetPlot1->rescaleAxes();
    ui->targetPlot1->replot();

    // Target2 verileri çizgi grafiği olarak ekler (mavi renk)
    ui->targetPlot2->addGraph();
    ui->targetPlot2->graph(0)->setData(t, Rx2);
    ui->targetPlot2->graph(0)->setPen(QPen(Qt::red));
    ui->targetPlot2->xAxis->setLabel("Time");
    ui->targetPlot2->yAxis->setLabel("Amplitude");

    ui->targetPlot2->addGraph();
    ui->targetPlot2->graph(1)->setData(t, Tx2);
    ui->targetPlot2->graph(1)->setPen(QPen(Qt::blue));
    ui->targetPlot2->xAxis->setRange(0, Range_max); // X ekseni aralığı
    ui->targetPlot2->yAxis->setRange(0, 1);

    ui->targetPlot2->rescaleAxes();
    ui->targetPlot2->replot();

    // mix verisi çizgi grafiği olarak ekler (mavi renk)
    ui->mixPlot->addGraph();
    ui->mixPlot->graph(0)->setData(t, Mix);
    ui->mixPlot->graph(0)->setPen(QPen(Qt::darkGreen));
    ui->mixPlot->xAxis->setLabel("Time");
    ui->mixPlot->yAxis->setLabel("Amplitude");
    ui->mixPlot->xAxis->setRange(0, Range_max); // X ekseni aralığı
    ui->mixPlot->yAxis->setRange(0, 1);

    ui->mixPlot->rescaleAxes();
    ui->mixPlot->replot();



    // FFT sonrası range grafiği
    ui->plot2->addGraph();
    ui->plot2->graph(0)->setData(xData, yData);
    ui->plot2->xAxis->setLabel("Range (m)");
    ui->plot2->yAxis->setLabel("FFT Value");
    ui->plot2->xAxis->setRange(0, Range_max); // X ekseni aralığı
    ui->plot2->yAxis->setRange(0, 1); // Y ekseni aralığı

    ui->plot2->rescaleAxes();
    ui->plot2->replot();

}
