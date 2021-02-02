#include "sqlite.h"
QSqlQueryModel *model = new QSqlQueryModel;
 QSqlDatabase db;
Sqlite::Sqlite(QObject *parent) : QObject(parent)
{
 // Dbint(Ui::MainWindow *u);

}
typedef struct _testInfo //假定数据库存储内容
{
    QString UsreName;
    QString Time;
    QString Value;


}testInfo;


void Sqlite::Dbint(Ui::MainWindow *u)
{

    QString file = u->lineEdit->text();
    db = QSqlDatabase::addDatabase("QSQLITE","firstBase");
    db.setDatabaseName(file+"//DataBase.db");

    if(!db.open())
    {
        u->textEdit->append("Failed to open database!");
    }
    else
    {
         u->textEdit->append("Success to open database!");
    }

    QSqlQuery query(db);
     //用于存储sql语句
    QString sql;
     sql = "create table DCDATA_1(time text,value float)";
     //创建表是否成功
     (query.exec(sql));

      sql = "create table DCDATA_2(time text,value float)";
      //创建表是否成功
      query.exec(sql);

       sql = "create table DCDATA_3(time text,value float)";
       //创建表是否成功
       query.exec(sql);

        sql = "create table DCDATA_4(time text,value float)";
        //创建表是否成功
        query.exec(sql);

         sql = "create table DCDATA_5(time text,value float)";
         //创建表是否成功
         query.exec(sql);
           sql = "create table DZS_6(number text,value float)";
         //创建表是否成功
           query.exec(sql);


////-------------------------------------------------------------show


//     model->setQuery("select * from DCDATA", db);	//从给定的数据库db执行sql操作, db需预先制定并打开
//     model->setHeaderData(0, Qt::Horizontal, QStringLiteral("通道名称"));	//设置表头，如不设置则使用数据库中的默认表头
//     model->setHeaderData(1, Qt::Horizontal, QStringLiteral("时间"));
//     model->setHeaderData(2, Qt::Horizontal, QStringLiteral("数据"));



//        QVector<testInfo> infoVect; //testInfo向量，用于存储数据库查询到的数据

//        QSqlRecord recode = query.record();		//recode保存查询到一些内容信息，如表头、列数等等
//        int column = recode.count();			//获取读取结果的列数
//        QString s1 = recode.fieldName(0);	//获取第0列的列名
//        query.prepare("SELECT * FROM DCDATA");
//        query.exec();	//执行


//        while (query.next())
//        {
//            testInfo tmp;
//            tmp.UsreName = query.value("Name").toString();
//            tmp.Time = query.value("time").toString();
//            tmp.Value = query.value("value").toString();
//            infoVect.push_back(tmp);   //将查询到的内容存到testInfo向量中
//        }



////-------------------------------------------------------------biao

//        QTableView *view = new QTableView;	//定义视图，只能用于显示，不能修改数据库
//        view->setFixedSize(500, 650);
//        view->setModel(model);
//        QVBoxLayout *layout = u->database;
//        layout->addWidget(view);


}



void Sqlite::Write2Channl_1(qint64 time,float data)
{
  QSqlQuery query(db);
  QString Dtime = QDateTime::fromMSecsSinceEpoch(time).toString("yy-MM-dd-hh hh:mm:ss.zzz");
  QString Data = QString::number(data);
  query.exec(QString("insert into DCDATA_1 values('%1','%2')").arg(Dtime).arg(Data));
  //---------------------写入数据

}
void Sqlite::Write2Channl_2(qint64 time,float data)
{
    QSqlQuery query(db);
    QString Dtime = QDateTime::fromMSecsSinceEpoch(time).toString("yy-MM-dd-hh hh:mm:ss.zzz");
    QString Data = QString::number(data);
    query.exec(QString("insert into DCDATA_2 values('%1','%2')").arg(Dtime).arg(Data));
    //---------------------写入数据
}
void Sqlite::Write2Channl_3(qint64 time,float data)
{
    QSqlQuery query(db);
    QString Dtime = QDateTime::fromMSecsSinceEpoch(time).toString("yy-MM-dd-hh hh:mm:ss.zzz");
    QString Data = QString::number(data);
    query.exec(QString("insert into DCDATA_3 values('%1','%2')").arg(Dtime).arg(Data));
    //---------------------写入数据
}
void Sqlite::Write2Channl_4(qint64 time,float data)
{
    QSqlQuery query(db);
    QString Dtime = QDateTime::fromMSecsSinceEpoch(time).toString("yy-MM-dd-hh hh:mm:ss.zzz");
    QString Data = QString::number(data);
    query.exec(QString("insert into DCDATA_4 values('%1','%2')").arg(Dtime).arg(Data));

    //---------------------写入数据
}
void Sqlite::Write2Channl_5(qint64 time,float data)
{
    QSqlQuery query(db);
    QString Dtime = QDateTime::fromMSecsSinceEpoch(time).toString("yy-MM-dd-hh hh:mm:ss.zzz");
    QString Data = QString::number(data);
    query.exec(QString("insert into DCDATA_5 values('%1','%2')").arg(Dtime).arg(Data));
    //---------------------写入数据
}
void Sqlite::Write2Channl_6(float number,float data)
{
    QSqlQuery query(db);
    QString DNUMB = QString::number(number);
    QString Data = QString::number(data);
    query.exec(QString("insert into DZS_6 values('%1','%2')").arg(DNUMB).arg(Data));
    //---------------------写入数据
}

