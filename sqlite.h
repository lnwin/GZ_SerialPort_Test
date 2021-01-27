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

class Sqlite : public QObject
{
    Q_OBJECT
public:
    explicit Sqlite(QObject *parent = nullptr);
    void Dbint(Ui::MainWindow *u);
signals:



private:




};

#endif // SQLITE_H
