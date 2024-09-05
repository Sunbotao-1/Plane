#include "mainwindow.h"
#include <QApplication>
#include"citysql.h"
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   MainWindow w;

   citySql sql;//创建一个变量sql；


    return a.exec();
}
