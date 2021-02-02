#include "datathread.h"
#include<QTime>
#include<QDebug>
QList<float> currentdata;
QByteArray Threadbuf;
qint64 ThreadDst;
float Max_1,Max_2,Max_3,Max_4,Max_5,Min_1,Min_2,Min_3,Min_4,Min_5;
bool First_1=true;
bool First_2=true;
bool First_3=true;
bool First_4=true;
bool First_5=true;
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
             if(First_1)
             {
                 Max_1=y;
                 Min_1=y;
                 First_1=false;
             }
             currentdata.append(y);
             Max_1 = Max(y,Max_1);
             Min_1 = Min(y,Min_1);
           //  DataStartTime+=31.25;
             y =  Hex3Dec(buf.mid(count+5,3).toHex());
             currentdata.append(y);
             Max_1 = Max(y,Max_1);
             Min_1 = Min(y,Min_1);
         //    DataStartTime+=31.25;
             break;

        case 2:

            y =  Hex3Dec(buf.mid(count+2,3).toHex());
            if(First_2)
            {
                Max_2=y;
                Min_2=y;
                First_2=false;
            }
            currentdata.append(y);
            Max_2 = Max(y,Max_2);
            Min_2 = Min(y,Min_2);
          //  DataStartTime+=31.25;
            y =  Hex3Dec(buf.mid(count+5,3).toHex());
            currentdata.append(y);
            Max_2 = Max(y,Max_2);
            Min_2 = Min(y,Min_2);
          //  DataStartTime+=31.25;//
            break;

        case 3:
            y =  Hex3Dec(buf.mid(count+2,3).toHex());
            if(First_3)
            {
                Max_3=y;
                Min_3=y;
                First_3=false;
            }
            currentdata.append(y);
            Max_3 = Max(y,Max_3);
            Min_3 = Min(y,Min_3);
         //   DataStartTime+=31.25;
            y =  Hex3Dec(buf.mid(count+5,3).toHex());
            currentdata.append(y);
            Max_3 = Max(y,Max_3);
            Min_3 = Min(y,Min_3);
          //  DataStartTime+=31.25;//
            break;

        case 4:
            y =  Hex3Dec(buf.mid(count+2,3).toHex());
            if(First_4)
            {
                Max_4=y;
                Min_4=y;
                First_4=false;
            }
            currentdata.append(y);
            Max_4 = Max(y,Max_4);
            Min_4 = Min(y,Min_4);
          //  DataStartTime+=31.25;
            y =  Hex3Dec(buf.mid(count+5,3).toHex());
            currentdata.append(y);
            Max_4 = Max(y,Max_4);
            Min_4 = Min(y,Min_4);
           // DataStartTime+=31.25;
            break;

        case 5:
            y =  Hex3Dec(buf.mid(count+2,3).toHex());
            if(First_5)
            {
                Max_5=y;
                Min_5=y;
                First_5=false;
            }
            currentdata.append(y);
            Max_5 = Max(y,Max_5);
            Min_5 = Min(y,Min_5);
        //    DataStartTime+=31.25;
            y =  Hex3Dec(buf.mid(count+5,3).toHex());
            currentdata.append(y);
            Max_5 = Max(y,Max_5);
            Min_5 = Min(y,Min_5);
          //  DataStartTime+=31.25;
            if(currentdata.length()>829)
            {
               qDebug()<<"Send2m:"<<DataStartTime ;
               currentdata.append(Max_1);
                currentdata.append(Min_1);
                 currentdata.append(Max_2);
                  currentdata.append(Min_2);
                   currentdata.append(Max_3);
                    currentdata.append(Min_3);
                     currentdata.append(Max_4);
                      currentdata.append(Min_4);
                       currentdata.append(Max_5);
                        currentdata.append(Min_5);
               senddata2M(AK,currentdata);
               currentdata.clear();
            }
            break;

        }
    }
//First_1=true;
//First_2=true;
//First_3=true;
//First_4=true;
//First_5=true;

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
float DataThread:: Max(qreal a,float max)
{

    if(a>max)
    {
       max=a;

    }
   return max;

}
float DataThread:: Min(qreal a,float min)
{

    if(a<min)
    {
       min=a;

    }
   return min;

}
void DataThread::run()
{

    DataShow(Threadbuf,ThreadDst);
    qDebug()<<"count over--------------------";
}

