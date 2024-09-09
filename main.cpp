#include "mainwindow.h"
#include"page_login.h"
#include <QApplication>
#include"citysql.h"
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   MainWindow w;

   citySql sql;

    return a.exec();
}
