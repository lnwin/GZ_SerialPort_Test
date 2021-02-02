#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include<datathread.h>
#include <sqlite.h>
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
    void on_SerialButton_clicked();
    void on_SelectFileButton_clicked();

    void updataSeries(qint64 time,QList<float> data);

    void on_SerialButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QSerialPort *serial_2;
    DataThread  *Dthread  ;
    Sqlite *sql;
    void write2dqlite(QList<float>,qint64 Dtime);
    void chart1();
    void chart2();
    void chart3();
    void chart4();
    void chart5();
    void chart6();
    void formint();
    void searchport();
    void ReadData();
    void ReadData_2();
    void AnalyzingData( QByteArray buf);
     void AnalyzingData_2( QByteArray buf);
    //void DataShow(QByteArray buf,qint64 datastart);
   // qint64 ChangeDate2Number(QByteArray buf);
 void Delay_MSec(unsigned int );
   // float Hex3Dec(QString hex);
signals:

    void sendData2Thread(QByteArray buf);
};
#endif // MAINWINDOW_H
