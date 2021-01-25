﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtCharts/QChart"
#include "QChartView"
#include "QLineSeries"
#include "QValueAxis"
#include "QList"
#include "QDebug"
#include <QDateTimeAxis>
#include"QDateTime"
#include <QFileDialog>
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
int MessageHead=0;
bool DataStart =false;
int DataCount=0;
int DataStartIndex=0;
qint64 DataStartTime;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial =  new QSerialPort;
    Dthread = new DataThread;
    chart1();
    chart2();
    chart3();
    chart4();
    chart5();
    searchport();
    formint();
    connect(this, SIGNAL(sendData2Thread(QByteArray)),Dthread,SLOT(reveivedDataFromM(QByteArray)));
    connect(Dthread,SIGNAL(senddata2M(qint64,QList<float>)),this,SLOT(updataSeries(qint64,QList<float>)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::formint()
{
    QPalette texpal = ui->textEdit->palette();
    texpal.setBrush(QPalette::Base, Qt::black);
    texpal.setColor(QPalette::Text, Qt::green);
    ui->textEdit->setPalette(texpal);
    QPalette pal = window()->palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    window()->setPalette(pal);


}
void MainWindow::chart1()
{
   chart_1 =new QChart;

   QChartView *chartView = new QChartView(chart_1);
   chartView->setRubberBand(QChartView::RectangleRubberBand);
   chartView->setRenderHint(QPainter::Antialiasing);
   series_1 = new QLineSeries;

   chart_1->addSeries(series_1);
   series_1->setUseOpenGL(true);//openGl 加速
   qDebug()<<series_1->useOpenGL();

   QDateTime now  = QDateTime::currentDateTime();
   QDateTimeAxis  *axisX = new QDateTimeAxis;
   axisX->setFormat("MM-dd-HH:mm:ss");//
  // axisX->setLabelsAngle(60);
   axisX->setRange(now.addMSecs(-100*maxSize),now);

   QValueAxis *axisY = new QValueAxis;
   axisY->setRange(-5,5);
   axisY->setTitleText("axisY");

   chart_1->legend()->hide();
   chart_1->setTitle("magnetic_1");
   chart_1->addAxis(axisY, Qt::AlignLeft);
   chart_1->addAxis(axisX, Qt::AlignBottom);
   QVBoxLayout *layout = ui->verticalLayout;
   layout->addWidget(chartView);
   series_1->attachAxis(axisY);// 此二句一定要放在 this->chart()->addAxis 语句之后，不然
   series_1->attachAxis(axisX);// 没有曲线显示
   chart_1->setTheme(QChart::ChartThemeDark);


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
    series_2->setUseOpenGL(true);//openGl 加速
    qDebug()<<series_2->useOpenGL();

    QDateTime now  = QDateTime::currentDateTime();
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MM-dd-HH:mm:ss");//
   // axisX->setLabelsAngle(60);
    axisX->setRange(now.addMSecs(-100*maxSize),now);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-5,5);
    axisY->setTitleText("axisY");

    chart_2->setAxisX(axisX,series_2);
    chart_2->setAxisY(axisY,series_2);
    chart_2->legend()->hide();
    chart_2->setTitle("magnetic_2");

    QVBoxLayout *layout = ui->verticalLayout_2;
    layout->addWidget(chartView);
    chart_2->setTheme(QChart::ChartThemeDark);
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
    series_3->setUseOpenGL(true);//openGl 加速
    qDebug()<<series_3->useOpenGL();

    QDateTime now  = QDateTime::currentDateTime();
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MM-dd-HH:mm:ss");//
   // axisX->setLabelsAngle(60);
    axisX->setRange(now.addMSecs(-100*maxSize),now);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-5,5);
    axisY->setTitleText("axisY");

    chart_3->setAxisX(axisX,series_3);
    chart_3->setAxisY(axisY,series_3);
    chart_3->legend()->hide();
    chart_3->setTitle("magnetic_3");

    QVBoxLayout *layout = ui->verticalLayout_3;
    layout->addWidget(chartView);
     chart_3->setTheme(QChart::ChartThemeDark);
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



    series_4->setUseOpenGL(true);//openGl 加速
    qDebug()<<series_4->useOpenGL();

    QDateTime now  = QDateTime::currentDateTime();
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MM-dd-HH:mm:ss");//
   // axisX->setLabelsAngle(60);
    axisX->setRange(now.addMSecs(-100*maxSize),now);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-5,5);
    axisY->setTitleText("V");

    chart_4->setAxisX(axisX,series_4);
    chart_4->setAxisY(axisY,series_4);
    chart_4->legend()->hide();
    chart_4->setTitle("electric_1");

    QVBoxLayout *layout = ui->verticalLayout_4;
    layout->addWidget(chartView);
     chart_4->setTheme(QChart::ChartThemeDark);
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


    series_5->setUseOpenGL(true);//openGl 加速
    qDebug()<<series_5->useOpenGL();

    QDateTime now  = QDateTime::currentDateTime();
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MM-dd-HH:mm:ss");//
    //axisX->setLabelsAngle(60);
    axisX->setRange(now.addMSecs(-100*maxSize),now);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-5,5);
    axisY->setTitleText("V");

    chart_5->setAxisX(axisX,series_5);
    chart_5->setAxisY(axisY,series_5);
    chart_5->legend()->hide();
    chart_5->setTitle("electric_2");
    QVBoxLayout *layout = ui->verticalLayout_5;
    layout->addWidget(chartView);
    chart_5->setTheme(QChart::ChartThemeDark);
}

void MainWindow::updataSeries(qint64 time,QList<float> data)
{
    qint64 timestart;
    series_1->clear();
    series_2->clear();
    series_3->clear();
    series_4->clear();
    series_5->clear();
    timestart = time;
    int Dlength = data.length();
    //int count=0;

    ui->textEdit->append( "Data Starttime:"+QString::number(timestart));
    for (int i = 0; i<Dlength; i++ )

    {
        if(0<i&&i<166)
        {
        series_1->append(timestart, data[i]);
        //series_1->append(i,data[i]);
        timestart+=30;    
        ui->channel_1->setText(QString::number( data[i]));

        }

        else if (166<=i&&i<332)
        {
            series_2->append(timestart, data[i]);
            timestart+=30;        
            ui->channel_2->setText(QString::number( data[i]));
        }
        else if (332<=i&&i<498)
        {
            series_3->append(timestart, data[i]);
            timestart+=30;
            ui->channel_3->setText(QString::number( data[i]));
        }
        else if (498<=i&&i<664)
        {
            series_4->append(timestart, data[i]);
            timestart+=30;
            ui->channel_4->setText(QString::number( data[i]));
        }
        else if (664<=i&&i<830)
        {
            series_5->append(timestart, data[i]);
            timestart+=30;
            ui->channel_5->setText(QString::number( data[i]));
        }
         else
        {
            ui->textEdit->append("Max_1:"+ QString::number(data[i]));
            ui->textEdit->append("Min_1:"+ QString::number(data[i+1]));
            ui->textEdit->append("Max_2:"+ QString::number(data[i+2]));
            ui->textEdit->append("Min_2:"+ QString::number(data[i+3]));
            ui->textEdit->append("Max_3:"+ QString::number(data[i+4]));
            ui->textEdit->append("Min_3:"+ QString::number(data[i+5]));
            ui->textEdit->append("Max_4:"+ QString::number(data[i+6]));
            ui->textEdit->append("Min_4:"+ QString::number(data[i+7]));
            ui->textEdit->append("Max_5:"+ QString::number(data[i+8]));
            ui->textEdit->append("Min_5:"+ QString::number(data[i+9]));
            i+=10;
        }

       // count =i;
    }
    ui->textEdit->append( "Data Endtime:"+QString::number(timestart));
    QDateTime statT =QDateTime::fromMSecsSinceEpoch(timestart);
    chart_1->axisX()->setMin(statT.addMSecs(-25920));
    chart_1->axisX()->setMax(statT.addMSecs(-19920));

    chart_2->axisX()->setMin(statT.addMSecs(-20940));
    chart_2->axisX()->setMax(statT.addMSecs(-14940));

    chart_3->axisX()->setMin(statT.addMSecs(-15960));
    chart_3->axisX()->setMax(statT.addMSecs(-9960));

    chart_4->axisX()->setMin(statT.addMSecs(-10980));
    chart_4->axisX()->setMax(statT.addMSecs(-4980));

    chart_5->axisX()->setMin(statT.addMSecs(-6000));
    chart_5->axisX()->setMax(statT);

    series_1->show();
    series_2->show();
    series_3->show();
    series_4->show();
    series_5->show();
    qDebug()<<"END time "<<timestart;


}
void MainWindow::searchport()
{
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->portcomboBox->addItem(serial.portName());
            serial.close();

        }
    }
}
QByteArray Transbuf;
QString firstlenght;
void MainWindow::ReadData()
{
    QByteArray buf;
    buf = serial->readAll();
    Transbuf += buf;
       if(!buf.isEmpty())
    {
      // ui->textEdit->append(buf.toHex());

       if(!DataStart)
       {
           for (int i=0;i<Transbuf.length()-1;i++)

           if((Transbuf[i]=='\x88')&(Transbuf[i+5]=='\x01')&(Transbuf[i+6]=='\x01'))
           {
               DataStart=true;
               DataStartIndex=i;
//               qDebug()<<"Transbuf1:"<<Transbuf.toHex();
               Transbuf.remove(0,DataStartIndex-13);
              // AnalyzingData(Transbuf);
//               qDebug()<<"FirstLenght"<<Transbuf.length();
//               qDebug()<<"Datastart:"<<DataStartIndex;

//               qDebug()<<"TransbufMoved:"<<Transbuf.toHex();
               break;



        }
       }
       else
       {
          // qDebug()<<"AppendLenght:"<<Transbuf.length();
           if(Transbuf.length()>=5048)
           {
              AnalyzingData(Transbuf);

           }
       }


    }

    buf.clear();
}
QByteArray AllData;
void MainWindow::AnalyzingData(QByteArray buf)
{

      AllData=buf;
      if(AllData.length()>=5408)
      {

         AllData=AllData.remove(5408,AllData.length()-5408);
         sendData2Thread(AllData);
        // Dthread->run();
//         qDebug()<<"final count:"<<AllData.length();
//         qDebug()<<"final start:"<<QString::number(AllData[0],16);
//         qDebug()<<"final end:"<<QString::number(AllData[AllData.length()-1],16);
//        // qDebug()<<"Transbuf2:"<<Transbuf.toHex();
         AllData.clear();
         DataStart=false;
         DataCount=0;
         Transbuf.remove(0,5408);
    }

}

void MainWindow::on_SerialButton_clicked()//串口开关
{

        if(!serial->isOpen())
        {
        serial->setPortName(ui->portcomboBox->currentText());//设置串口名
        serial->open(QIODevice::ReadWrite);//以读写方式打开串口
        serial->setBaudRate(QSerialPort::Baud115200);//波特率
        serial->setDataBits(QSerialPort::Data8);//数据位
        serial->setParity(QSerialPort::NoParity);//校验位
        serial->setStopBits(QSerialPort::OneStop);//停止位
        QObject::connect(serial,&QSerialPort::readyRead,this,&MainWindow::ReadData);
        ui->textEdit->append("SerialPort Opened");
        ui->SerialButton->setText("Close Port");

        }
        else
        {
           serial->close();
           ui->SerialButton->setText("Open Port");
           ui->textEdit->append("SerialPort Closed");
        }
}

void MainWindow::on_SelectFileButton_clicked()//选取文件
{
    QString  srcDirPath = QFileDialog::getOpenFileName( this, "open the data file", "/");
    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
        ui->lineEdit->setText(srcDirPath) ;

    }
}
int a =0;
int b=1;
void MainWindow::on_FileReadButton_clicked()//读取文件数据
{


}
void MainWindow::Delay_MSec(unsigned int msec)//-----------------------------------------延时函数
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < _Timer )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
