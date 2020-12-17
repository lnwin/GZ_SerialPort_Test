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
    connect(this, SIGNAL(sendData2Thread(QByteArray)),Dthread,SLOT(reveivedDataFromM(QByteArray)));
    connect(Dthread,SIGNAL(senddata2M(QList<float>)),this,SLOT(updataSeries(QList<float>)));
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
   axisX->setFormat("MM-dd-HH:mm:ss");//
   axisX->setLabelsAngle(60);
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
    axisX->setLabelsAngle(60);
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
    axisX->setLabelsAngle(60);
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
    axisX->setLabelsAngle(60);
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
    axisX->setLabelsAngle(60);
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
}
void MainWindow::updataSeries(QList<float> data)
{

    qint64 timestart = data[0];
    int Dlength = data.length();
    for (int i = 1; i<Dlength; i++ )

    {
        series_1->append(timestart, data[i]);
        timestart+=30;
    }

    chart_1->axisX()->setMin(QDateTime::fromMSecsSinceEpoch(timestart).addMSecs(-6000));
    chart_1->axisX()->setMax(QDateTime::fromMSecsSinceEpoch(timestart).addMSecs(0));
    series_1->show();
    qDebug()<<QDateTime::fromMSecsSinceEpoch(DataStartTime);
    qDebug()<<DataStartTime;

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
      // ui->textEdit->append(buf.toHex());
       if(!DataStart)
       {
           for (int i=0;i<buf.length()-1;i++)
        {
           if((buf[i]=='\x88')&(buf[i+5]=='\x00'))
           {
               DataStart=true;
               DataStartIndex=i;
               AnalyzingData(buf);
               qDebug()<<"Datastart:"<<DataStartIndex;
               break;
           }
        }
       }
       else
       {
          AnalyzingData(buf);
       }


    }
    buf.clear();
}
QByteArray AllData;

void MainWindow::AnalyzingData( QByteArray buf)
{

    if(DataCount==0)
  {

    AllData.append(buf.remove(0,DataStartIndex));
    DataCount+=buf.length()-DataStartIndex+1;
    //DataStartTime = ChangeDate2Number(AllData);
   // qDebug()<<"DataStarTime:"<<DataStartTime;
  }
    else
    {
      AllData.append(buf);
      qDebug()<<"current lenght:"<<AllData.length();
     // DataCount+=buf.length();

    }

    if(AllData.length()>=5408)
    {

         AllData=AllData.remove(5408,AllData.length()-5408);
        //DataShow(AllData,DataStartTime);
         sendData2Thread(AllData);
         Dthread->run();
         qDebug()<<"final count:"<<AllData.length();
         qDebug()<<"final start:"<<QString::number(AllData[0],16) ;
         qDebug()<<"final end:"<<QString::number(AllData[AllData.length()-1],16);
         AllData.clear();
         DataStart=false;
         DataCount=0;
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

void MainWindow::on_FileReadButton_clicked()//读取文件数据
{

    int a = -1419521;
    float c = ((double)a/8388608)*2;

    qDebug("%.3f",c);


}
