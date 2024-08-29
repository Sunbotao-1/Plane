#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<citysql.h>
#include <QMainWindow>
#include"page_login.h"
#include<dlg_addcity.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_exit_clicked();

    void on_btn_simulation_clicked();

    void on_btn_search_clicked();

    void on_btn_add_clicked();

    void on_btn_clear_clicked();


    void on_btn_del_clicked();

    void on_btn_update_clicked();

private:
    void updateTable();
private:
    Ui::MainWindow *ui;//主界面指针
    Page_Login m_dlgLogin;//登录界面
    citySql* m_ptrCitySql;//负责进入sql和操作数据的指针
    QStringList m_lNames;//用来存储城市名称的字符串组
    Dlg_AddCity m_dlgAddCity;
};
#endif // MAINWINDOW_H
