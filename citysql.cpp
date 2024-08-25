#include "citysql.h"
#include<QMessageBox>

#include <QCoreApplication>
#include<QSqlQuery>
#include<QtDebug>
citySql::citySql(QObject *parent)
    : QObject{parent}
{

    init();

}

void citySql::init()//打开数据库???
{
    if(QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";

   m_db =QSqlDatabase::addDatabase("QSQLITE");//打开数据库????
   //auto str=QCoreApplication::applicationDirPath();
  // qDebug()<<str;//应用程序的输出目录.


    m_db.setDatabaseName("D:\\data.db");
    if(!m_db.open())
        qDebug()<<"db not open";
}
//quint32 citySql::getcity()
//{

//}

//bool citySql::addCity(CityInfo info)
//{
  //  QSqlQuery sql(m_db);
    // sql.exec("INSERT INTO city VALUES (1000, '南京', 10, 3);");

//}
