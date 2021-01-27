#include "sqlite.h"

Sqlite::Sqlite(QObject *parent) : QObject(parent)
{
 // Dbint(Ui::MainWindow *u);

}
typedef struct _testInfo //假定数据库存储内容
{
    QString UsreName;
    QString Year;
    QString Value;


}testInfo;


void Sqlite::Dbint(Ui::MainWindow *u)
{




    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","firstBase");
    db.setDatabaseName(".//DataBase.db");


    if(!db.open())
    {
        qDebug()<<"Failed to open database:";
    }
    else
    {
        qDebug()<<"Success to open database";
    }

    QSqlQuery query(db);
     //用于存储sql语句
    QString sql;
     sql = "create table Target(Name,year,value)";
     //创建表是否成功
     if(!query.exec(sql))
     {
         qDebug()<<"Failed to create table:";
     }
     else
     {
         qDebug()<<"success to create";
     }

     query.exec("insert into Target values(1,'2d',200)");



//-------------------------------------------------------------show

     QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("select * from Target", db);	//从给定的数据库db执行sql操作, db需预先制定并打开
     model->setHeaderData(0, Qt::Horizontal, QStringLiteral("用户名"));	//设置表头，如不设置则使用数据库中的默认表头
     model->setHeaderData(1, Qt::Horizontal, QStringLiteral("IP地址"));
     model->setHeaderData(2, Qt::Horizontal, QStringLiteral("端口"));
     model->setHeaderData(3, Qt::Horizontal, QStringLiteral("密码"));
     model->setHeaderData(4, Qt::Horizontal, QStringLiteral("用户类型"));

     QVector<testInfo> infoVect; //testInfo向量，用于存储数据库查询到的数据

       QSqlRecord recode = query.record();		//recode保存查询到一些内容信息，如表头、列数等等
        int column = recode.count();			//获取读取结果的列数
        QString s1 = recode.fieldName(0);	//获取第0列的列名
        query.prepare("SELECT * FROM Target");
        query.exec();	//执行


        while (query.next())
        {
            testInfo tmp;
            tmp.UsreName = query.value("Name").toString();
            tmp.Year = query.value("year").toString();
            tmp.Value = query.value("value").toString();
            infoVect.push_back(tmp);   //将查询到的内容存到testInfo向量中
        }

        for (int i=0; i<infoVect.size(); i++)    //打印输出
        {
           // qDebug() << infoVect[i].UsreName << ":"	<< infoVect[i].Year << ":"	 << infoVect[i].Value << ":"     ;
            model->setData(model->index(1,i),infoVect[i].Year );

        }






//-------------------------------------------------------------biao

        QTableView *view = new QTableView;	//定义视图，只能用于显示，不能修改数据库
        view->setFixedSize(500, 650);
        view->setModel(model);
        QVBoxLayout *layout = u->database;
        layout->addWidget(view);


}


