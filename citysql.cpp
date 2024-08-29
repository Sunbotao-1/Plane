#include "citysql.h"
#include<QMessageBox>

#include <QCoreApplication>
#include<QSqlQuery>
#include<QtDebug>
citySql* citySql::ptrCitySql=nullptr;
citySql::citySql(QObject *parent)
    : QObject{parent}
{

    //init();防止调用多次

    // CityInfo c;
    // c.name="北京";
    // for(int i=0;i<10;i++)
    // {
    //         addCity(c);
    // }//试运行添加功能
    // getCityCnt();
    // getPageCity(2,3);//运行查找第几页第几个的功能
    //delCity(1003);//试运行删除功能
    // CityInfo c;
    // c.id=1004;
    // c.name="上海";
    // UpdateCityInfo(c);//试运行更改数据功能



       // UserInfo info;
       // info.username = "xiaoyu";
       // info.password = "123456";
       // info.aut = "admin";

       // addUser(info);
       // addUser(info);
       // auto l=getAllUser();
       // qDebug()<<isExist("xiaoyu");
       // info.password = "666";
       // updateUser(info);
       //delUser("xiaoyu");
}

void citySql::init()//打开数据库???
{
    if(QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";

    m_db =QSqlDatabase::addDatabase("QSQLITE");//打开数据库????
//#if
   // auto str=QCoreApplication::applicationDirPath()+"data.db";
         //qDebug()<<str;//应用程序的输出目录.
//#endif



    m_db.setDatabaseName("D:\\data.db");//文件的位置？
    if(!m_db.open())
        qDebug()<<"db not open";
}
quint32 citySql::getCityCnt()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from city");
    quint32 uiCnt=0;
    while(sql.next())
    {
        uiCnt=sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<CityInfo> citySql::getPageCity(quint32 page, quint32 uiCnt)
{
    QList<CityInfo> l;

    QSqlQuery sql(m_db);
    QString strsql=QString("select * from city order by id limit %1 offset %2;"
                             ).arg(uiCnt).arg(page*uiCnt);//页数×数量
    sql.exec(strsql);
    CityInfo info;
    while(sql.next())
    {
        info.id=sql.value(0).toUInt();
        info.name=sql.value(1).toString();
        info.PointX=sql.value(2).toDouble();
        info.PointY=sql.value(3).toDouble();
        l.push_back(info);
    }
    return l;
}

bool citySql::addCity(CityInfo info)
{
  QSqlQuery sql(m_db);
  QString strSql =QString("insert into city values(%1,'%2',%3,%4)").
                   arg(info.id).
                   arg(info.name).
                   arg(info.PointX).
                   arg(info.PointY);
 return sql.exec(strSql);

}

bool citySql::delCity(int id)
{

    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from city where id = %1").arg(id));

}

void citySql::clearCityTable()
{
    QSqlQuery sql(m_db);
    sql.exec("delete from city");
}

void citySql::UpdateCityInfo(CityInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql =QString("update city set name = '%1',PointX=%2,PointY=%3 where id=%4;").
                     arg(info.name).
                     arg(info.PointX).
                     arg(info.PointY).arg(info.id);
     sql.exec(strSql);
}

QList<UserInfo> citySql::getAllUser()
{
    QList<UserInfo> l;

    QSqlQuery sql(m_db);
    sql.exec("select * from username");
    UserInfo info;
    while(sql.next())
    {
        info.username=sql.value(0).toString();
        info.password=sql.value(1).toString();
        info.aut=sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}

bool citySql::isExist(QString strUser)
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select *from username where username='%1'").arg(strUser));
    return sql.next();//判断是否存在???
}

bool citySql::updateUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql= QString("update username set password='%1',auth='%2' where username='%3'").
                     arg(info.password).
                     arg(info.aut).arg(info.username);

    bool ret =   sql.exec(strSql);
    // QSqlError e =  sql.lastError();
    // if(e.isValid())
    // {
    //     qDebug()<<e.text();
    // }
    return ret;
}

bool citySql::addUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql= QString("insert into username  values ('%1', '%2', '%3')").
                     arg(info.username).
                     arg(info.password).
                     arg(info.aut);
    return sql.exec(strSql);
}

bool citySql::delUser(QString strUserName)
{
    QSqlQuery sql(m_db);
   return sql.exec(QString("delete from username where username='%1'").arg(strUserName));
}
