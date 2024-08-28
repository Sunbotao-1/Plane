#include "page_login.h"
#include "ui_page_login.h"

Page_Login::Page_Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page_Login)
{
    ui->setupUi(this);
}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::on_btn_login_clicked() //登陆页面数据库查找用户名和密码
{
    //失败就提示
    //成功进去主页面
    emit sendLoginSuccess();
}


void Page_Login::on_pushButton_2_clicked()
{
    exit(0);//退出页面的代码
}


void Page_Login::on_btn_exit_clicked()
{
    exit(0);
}

