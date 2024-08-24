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
