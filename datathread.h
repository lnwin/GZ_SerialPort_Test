#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QObject>
#include <QThread>

class DataThread:public QThread
{
    Q_OBJECT
public:
    DataThread();

    void DataShow(QByteArray buf,qint64 DataStartTime);
    float Hex3Dec(QString hex);
    qint64 ChangeDate2Number(QByteArray buf);
    void run() ;
    QString FixString(int);
signals:
     void senddata2M(qint64 time,QList<float> data);
public slots:

    void reveivedDataFromM(QByteArray buf);
private:
    float listMax(QList<float>, int, int);


};

#endif // DATATHREAD_H
