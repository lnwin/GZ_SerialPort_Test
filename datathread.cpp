﻿#include "datathread.h"
#include<QTime>
#include<QDebug>
QList<float> currentdata;
QByteArray Threadbuf;
qint64 ThreadDst;
QList<float> ListMaxMin;
float Max_1=0,Max_2=0,Max_3=0,Max_4=0,Max_5=0,Min_1=0,Min_2=0,Min_3=0,Min_4=0,Min_5=0;
DataThread::DataThread()
{

}

void DataThread::DataShow( QByteArray buf,qint64 DataStartTime)
{
    bool ok;
   // DataStartTime = ChangeDate2Number(buf);
    qreal y;
    qint64 AK =DataStartTime;

    for (int count =18;count<5408;count+=13)
    {

        switch (buf.mid(count,1).toHex().toInt(&ok,16))
        {

        case 1:

             y =  Hex3Dec(buf.mid(count+2,3).toHex());
             currentdata.append(y);
             MaxMin(y,Max_1,Min_1,1);
             DataStartTime+=30;
             y =  Hex3Dec(buf.mid(count+5,3).toHex());
             currentdata.append(y);
             MaxMin(y,Max_1,Min_1,1);
             DataStartTime+=30;
             break;

        case 2:

            y =  Hex3Dec(buf.mid(count+2,3).toHex());
            currentdata.append(y);
            MaxMin(y,Max_2,Min_2,2);
            DataStartTime+=30;
            y =  Hex3Dec(buf.mid(count+5,3).toHex());
            currentdata.append(y);
            MaxMin(y,Max_2,Min_2,2);
            DataStartTime+=30;//
            break;

        case 3:
            y =  Hex3Dec(buf.mid(count+2,3).toHex());
            currentdata.append(y);
            MaxMin(y,Max_3,Min_3,3);
            DataStartTime+=30;
            y =  Hex3Dec(buf.mid(count+5,3).toHex());
            currentdata.append(y);
            MaxMin(y,Max_3,Min_3,3);
            DataStartTime+=30;//
            break;

        case 4:
            y =  Hex3Dec(buf.mid(count+2,3).toHex());
            currentdata.append(y);
             MaxMin(y,Max_4,Min_4,4);
            DataStartTime+=30;
            y =  Hex3Dec(buf.mid(count+5,3).toHex());
            currentdata.append(y);
              MaxMin(y,Max_4,Min_4,4);
            DataStartTime+=30;
            break;

        case 5:
            y =  Hex3Dec(buf.mid(count+2,3).toHex());
            currentdata.append(y);
              MaxMin(y,Max_5,Min_5,5);
            DataStartTime+=30;
            y =  Hex3Dec(buf.mid(count+5,3).toHex());
            currentdata.append(y);
            MaxMin(y,Max_5,Min_5,5);
            DataStartTime+=30;
            if(currentdata.length()>829)
            {
               qDebug()<<"SENFDATA2m:"<<DataStartTime ;
               currentdata.append(ListMaxMin);
               senddata2M(AK,currentdata);
               currentdata.clear();
            }
            break;

        }
    }

}

float DataThread:: Hex3Dec(QString hex)
{
      bool ok;
      float finaldata;
      int a =hex.toInt(&ok,16);
      QString bin =QString::number(a,2);
      int datalength =bin.length();
      if(datalength%4==0)
      {
             for (int i=0;i<datalength;i++)
             {
                 if(bin[i]=="0")
                 {
                     bin[i]='1';
                 }
                 else
                 {
                     bin[i]='0';
                 }

             }

             finaldata = ((double)(-(bin.toInt(&ok,2)+1))/8388608)*2.2;
             return finaldata;
         }

         else
         {
             QString data =hex;
             finaldata =((double)data.toInt(&ok,16)/8388608)*2.2;
             return finaldata;

         }




}
void DataThread::reveivedDataFromM(QByteArray buf)
{
    Threadbuf =buf;
    ThreadDst =ChangeDate2Number(buf);
    qDebug()<<"received:"<<buf.length();
    qDebug()<<"received time:"<<ThreadDst;
   run();

}
qint64 DataThread:: ChangeDate2Number(QByteArray buf)
{
    bool ok;
    QList<int>datetime;
    datetime.append(buf.mid(5,2).toHex().toInt(&ok,16));
    datetime.append(buf.mid(7,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(8,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(9,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(10,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(11,1).toHex().toInt(&ok,16));
    datetime.append(buf.mid(12,1).toHex().toInt(&ok,16)+2000);
    QString ms = FixString(datetime[0]);
    QString s  = FixString(datetime[1]);
    QString mm = FixString(datetime[2]);
    QString hh = FixString(datetime[3]);
    QString dd = FixString(datetime[4]);
    QString MM = FixString(datetime[5]);
    QString YY = FixString(datetime[6]);
    QString YYMMddhhmmss =YY+"-"+MM+"-"+dd+" "+hh+":"+mm+":"+s;
    QDateTime time;
    time = QDateTime::fromString(YYMMddhhmmss,"yyyy-MM-dd hh:mm:ss");
    qint64 finaldate = time.toMSecsSinceEpoch()+datetime[0];

    datetime.clear();
    return finaldate;

}
QString DataThread::FixString(int a)
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

QList<float> MaxMin(float a,float max, float min,int N)
{

    if(a>max)
    {
       max=a;
       ListMaxMin[N-1]=max;
    }
    if(a<min)
    {
       min=a;
      ListMaxMin[N]=min;
    }
    return ListMaxMin;

}
void DataThread::run()
{

    DataShow(Threadbuf,ThreadDst);
    qDebug()<<"count over--------------------";
}

