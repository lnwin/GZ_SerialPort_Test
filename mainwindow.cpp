#include "mainwindow.h"
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
QList<float> currentdata;
qreal DataStartTime;
bool DataStart =false;
int DataCount=0;
int DataStartIndex=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial =  new QSerialPort;
    chart1();
    chart2();
    chart3();
    chart4();
    chart5();
    searchport();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chart1()
{
   chart_1 =new QChart;

   QChartView *chartView = new QChartView(chart_1);
   chartView->setRubberBand(QChartView::RectangleRubberBand);

   series_1 = new QLineSeries;
   chart_1->addSeries(series_1);
   series_1->setUseOpenGL(true);//openGl 加速
   qDebug()<<series_1->useOpenGL();

   QDateTime now  = QDateTime::currentDateTime();


   QDateTimeAxis  *axisX = new QDateTimeAxis;
   axisX->setFormat("HH:mm:ss");//
   axisX->setLabelsAngle(60);
   axisX->setRange(now.addMSecs(-100*maxSize),now);

   QValueAxis *axisY = new QValueAxis;
   axisY->setRange(-10,10);
   axisY->setTitleText("axisY");


   chart_1->legend()->hide();
   chart_1->setTitle("magnetic_1");
   chart_1->addAxis(axisY, Qt::AlignLeft);
   chart_1->addAxis(axisX, Qt::AlignBottom);
   QVBoxLayout *layout = ui->verticalLayout;
   layout->addWidget(chartView);

   series_1->attachAxis(axisY);// 此二句一定要放在 this->chart()->addAxis 语句之后，不然
   series_1->attachAxis(axisX);// 没有曲线显示

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

    QDateTime x1=QDateTime::currentDateTime();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    qreal y =qrand()%9;//随机生成0到9的随机数
    chart_1->axisX()->setMin(QDateTime::currentDateTime().addSecs(-60*1));
    chart_1->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
    qDebug()<<x1.currentMSecsSinceEpoch();
    series_1->append(x1.toMSecsSinceEpoch(), y);
    series_1->show();
    int a = '\xff'-'\x18'+1;
    qDebug()<<a;

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
void MainWindow::ReadData()
{
    QByteArray buf;
    buf = serial->readAll();

       if(!buf.isEmpty())
    {
       ui->textEdit->append(buf.toHex());
       if(!DataStart)
       {
           for (int i=0;i<buf.length()-1;i++)
        {
           if((buf[i]=='\x88')&(buf[i+5]=='\x00'))
           {
               DataStart=true;
               DataStartIndex=i;
               analyzingData(buf);
               qDebug()<<"Datastart:"<<DataStartIndex;
           }
        }
       }
       else
       {
          analyzingData(buf);
       }


    }
    buf.clear();
}
QString MainWindow::fixstring(int a)
 {
     if(a<10)
     {
         QString s  = "0"+QString::number(a);
         return s;
     }
     else
     {
          QString s  = QString::number(a);
          return s;
     }

 };
QByteArray AllData;
void MainWindow::analyzingData( QByteArray buf)
{

    if(DataCount==0)
  {

    AllData.append(buf.remove(0,DataStartIndex));
    DataCount+=buf.length()-DataStartIndex+1;
    DataStartTime = ChangeDate2Number(AllData);

  }
    else
    {
      AllData.append(buf);
      qDebug()<<"current lenght:"<<AllData.length();
      DataCount+=buf.length();

    }

    if(DataCount>=2808)
    {

         AllData=AllData.remove(2808,AllData.length()-2808);
         DataShow(AllData);
         qDebug()<<"final count:"<<AllData.length();
         qDebug()<<"final start:"<<QString::number(AllData[0],16) ;
         qDebug()<<"final end:"<<QString::number(AllData[AllData.length()-1],16);
         AllData.clear();
         DataStart=false;
         DataCount=0;
    }

}
void MainWindow::DataShow( QByteArray buf)
{

    uchar* alldata = (uchar*)buf.data();//转为数字
    int ssa = alldata[0];




}
qint64 MainWindow:: ChangeDate2Number(QByteArray buf)
{
    bool ok;
    QList<int>datetime;
    datetime.append(buf.mid(6,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(7,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(8,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(9,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(10,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(11,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(12,1).toHex().toInt(&ok,16)+2000);
    QString s  = fixstring(datetime[1]);
    QString mm = fixstring(datetime[2]);
    QString hh = fixstring(datetime[3]);
    QString dd = fixstring(datetime[4]);
    QString MM = fixstring(datetime[5]);
    QString YY = fixstring(datetime[6]);
    QString YYMMddhhmmss =YY+"-"+MM+"-"+dd+" "+hh+":"+mm+":"+s;
    QDateTime time;
    time = QDateTime::fromString(YYMMddhhmmss,"yyyy-MM-dd hh:mm:ss");
    qint64 finaldate = time.toMSecsSinceEpoch()+datetime[0];
    qDebug()<<finaldate;
    return finaldate;
    datetime.clear();
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

void MainWindow::on_FileReadButton_clicked()//读取文件数据
{
     currentdata.append(7);
     updataSeries(currentdata);
     currentdata.clear();

}
