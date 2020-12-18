﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include<datathread.h>
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

    void on_FileReadButton_clicked();
    void updataSeries(QList<float> data);
private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    DataThread  *Dthread  ;
    void chart1();
    void chart2();
    void chart3();
    void chart4();
    void chart5();
    void formint();
    void searchport();
    void ReadData();
    void AnalyzingData( QByteArray buf);
    //void DataShow(QByteArray buf,qint64 datastart);
   // qint64 ChangeDate2Number(QByteArray buf);

   // float Hex3Dec(QString hex);
signals:

    void sendData2Thread(QByteArray buf);
};
#endif // MAINWINDOW_H
