#ifndef SQLITE_H
#define SQLITE_H
#include <QVBoxLayout>
#include <QObject>
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QTableView>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include "ui_mainwindow.h"
#include"QDateTime"

class Sqlite : public QObject
{
    Q_OBJECT
public:
    explicit Sqlite(QObject *parent = nullptr);
    void Dbint(Ui::MainWindow *u);
    void Write2Channl_1(qint64,float);
    void Write2Channl_2(qint64,float);
    void Write2Channl_3(qint64,float);
    void Write2Channl_4(qint64,float);
    void Write2Channl_5(qint64,float);
    void Write2Channl_6(float,float);
signals:



private:




};

#endif // SQLITE_H
