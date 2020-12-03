#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtCharts/QChart"
#include "QChartView"
#include "QLineSeries"
#include "QValueAxis"
#include "QList"
#include "QDebug"
QT_CHARTS_USE_NAMESPACE
QChart *chart_1;
QChart *chart_2;
QChart *chart_3;
QChart *chart_4;
QChart *chart_5;
QLineSeries *series_1;
QLineSeries *series_2;
QLineSeries *series_3;
QLineSeries *series_4;
QLineSeries *series_5;
int maxSize = 5000;
QList<float> currentdata;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chart1();
    chart2();
    chart3();
    chart4();
    chart5();
    //        QPalette pal = qApp->palette();
    //        pal.setColor(QPalette::Window, QRgb(0x121218));
    //        pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    //        qApp->setPalette(pal);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chart1()
{
   chart_1 =new QChart;

   QChartView *chartView = new QChartView(chart_1);
//    v.setRubberBand(QChartView::HorizontalRubberBand);
   chartView->setRubberBand(QChartView::RectangleRubberBand);
//    chartView->setRubberBand();

   series_1 = new QLineSeries;
   chart_1->addSeries(series_1);


   series_1->append(0,0);
   series_1->append(1,4);
   series_1->append(2,7);

   series_1->setUseOpenGL(true);//openGl 加速
   qDebug()<<series_1->useOpenGL();

   QValueAxis *axisX = new QValueAxis;
   axisX->setRange(0,series_1->count()-1);
   axisX->setLabelFormat("%g");
   axisX->setTitleText("Count");

   QValueAxis *axisY = new QValueAxis;
   axisY->setRange(-10,10);
   axisY->setTitleText("axisY");

   chart_1->setAxisX(axisX,series_1);
   chart_1->setAxisY(axisY,series_1);
   chart_1->legend()->hide();
   chart_1->setTitle("magnetic_1");

   QVBoxLayout *layout = ui->verticalLayout;
   layout->addWidget(chartView);

}
void MainWindow::chart2()
{
    chart_2 =new QChart;

    QChartView *chartView = new QChartView(chart_2);
 //    v.setRubberBand(QChartView::HorizontalRubberBand);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
 //    chartView->setRubberBand();

    series_2 = new QLineSeries;
    chart_2->addSeries(series_2);

    for(int i=0;i<maxSize;++i){
       series_2->append(i,0);
    }
    series_2->setUseOpenGL(true);//openGl 加速
    qDebug()<<series_2->useOpenGL();

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,maxSize);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Count");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-10,10);
    axisY->setTitleText("axisY");

    chart_2->setAxisX(axisX,series_2);
    chart_2->setAxisY(axisY,series_2);
    chart_2->legend()->hide();
    chart_2->setTitle("magnetic_2");

    QVBoxLayout *layout = ui->verticalLayout_2;
    layout->addWidget(chartView);

}
void MainWindow::chart3()
{

    chart_3 =new QChart;

    QChartView *chartView = new QChartView(chart_3);
 //    v.setRubberBand(QChartView::HorizontalRubberBand);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
 //    chartView->setRubberBand();

    series_3 = new QLineSeries;
    chart_3->addSeries(series_3);

    for(int i=0;i<maxSize;++i){
       series_3->append(i,0);
    }
    series_3->setUseOpenGL(true);//openGl 加速
    qDebug()<<series_3->useOpenGL();

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,maxSize);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Count");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-10,10);
    axisY->setTitleText("axisY");

    chart_3->setAxisX(axisX,series_3);
    chart_3->setAxisY(axisY,series_3);
    chart_3->legend()->hide();
    chart_3->setTitle("magnetic_3");

    QVBoxLayout *layout = ui->verticalLayout_3;
    layout->addWidget(chartView);
}
void MainWindow::chart4()
{

    chart_4 =new QChart;

    QChartView *chartView = new QChartView(chart_4);
 //    v.setRubberBand(QChartView::HorizontalRubberBand);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
 //    chartView->setRubberBand();

    series_4 = new QLineSeries;
    chart_4->addSeries(series_4);

    for(int i=0;i<maxSize;++i){
       series_4->append(i,0);
    }
    series_4->setUseOpenGL(true);//openGl 加速
    qDebug()<<series_4->useOpenGL();

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,maxSize);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Count");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-10,10);
    axisY->setTitleText("axisY");

    chart_4->setAxisX(axisX,series_4);
    chart_4->setAxisY(axisY,series_4);
    chart_4->legend()->hide();
    chart_4->setTitle("electric_1");

    QVBoxLayout *layout = ui->verticalLayout_4;
    layout->addWidget(chartView);
}
void MainWindow::chart5()
{

    chart_5 =new QChart;

    QChartView *chartView = new QChartView(chart_5);
 //    v.setRubberBand(QChartView::HorizontalRubberBand);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
 //    chartView->setRubberBand();

    series_5 = new QLineSeries;
    chart_5->addSeries(series_5);

    for(int i=0;i<maxSize;++i){
       series_5->append(i,0);
    }
    series_5->setUseOpenGL(true);//openGl 加速
    qDebug()<<series_5->useOpenGL();

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,maxSize);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Count");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-10,10);
    axisY->setTitleText("axisY");

    chart_5->setAxisX(axisX,series_5);
    chart_5->setAxisY(axisY,series_5);
    chart_5->legend()->hide();
    chart_5->setTitle("electric_2");
    QVBoxLayout *layout = ui->verticalLayout_5;
    layout->addWidget(chartView);
}
void MainWindow::updataSeries(QList<float> data)
{

    if (series_1->count() >10)
        {
            series_1->removePoints(0, 1);
            series_1->append(series_1->count()-1,data[0]);

        }
    series_1->append(series_1->count()-1,data[0]);
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,series_1->count()-2);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Count");
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-10,10);
    axisY->setTitleText("axisY");

    chart_1->setAxisX(axisX,series_1);
    chart_1->setAxisY(axisY,series_1);
    chart_1->legend()->hide();
    chart_1->setTitle("magnetic_1");
    qDebug()<<series_1->at(0);




}

void MainWindow::on_SerialButton_clicked()//串口开关
{

}

void MainWindow::on_SelectFileButton_clicked()//选取文件
{

}

void MainWindow::on_FileReadButton_clicked()//读取文件数据
{
     currentdata.append(7);
     updataSeries(currentdata);
     currentdata.clear();

}
