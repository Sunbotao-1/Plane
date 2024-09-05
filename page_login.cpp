#include "page_login.h"
#include "ui_page_login.h"
#include<QSqlQueryModel>
#include<QMessageBox>
Page_Login::Page_Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page_Login),m_ptrUsernameSql(nullptr)
{
    ui->setupUi(this);
    m_ptrUsernameSql=citySql::getinstance();
    m_ptrUsernameSql->init();
}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::on_btn_login_clicked() //登陆页面数据库查找用户名和密码
{
    QList<UserInfo> l=m_ptrUsernameSql->getAllUser();
    int i;
    for(i=0;i<l.size();i++)
    {
        if((ui->le_user->text()==l[i].username)&&(ui->le_password->text()==l[i].password))
        {
             emit sendLoginSuccess();
            break;
        }

    }

    if(i==l.size())
    {
         QMessageBox::information(nullptr,"提示","账号或密码错误");
    }
    //失败就提示
    //成功进去主页面
   // else
   //      exit(0);

}


void Page_Login::on_pushButton_2_clicked()
{
    exit(0);//退出页面的代码
}


void Page_Login::on_btn_exit_clicked()
{
    exit(0);
}

