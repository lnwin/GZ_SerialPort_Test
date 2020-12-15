#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

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

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    void chart1();
    void chart2();
    void chart3();
    void chart4();
    void chart5();
    void updataSeries(QList<float> data);
    void searchport();
    void ReadData();
    void AnalyzingData( QByteArray buf);
    void DataShow(QByteArray buf);
    qint64 ChangeDate2Number(QByteArray buf);
    QString FixString(int);
    float Hex3Dec(QString hex);

};
#endif // MAINWINDOW_H
