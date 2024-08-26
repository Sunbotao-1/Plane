#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_dlgLogin.show();
    auto f=[&](){
        this->show();
    };
    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,f);//登录成功自动跳到主页面
    ui->treeWidget->setColumnCount(1);//主页面左边的tree设置一行
        QStringList l;
    l<<"学生信息管理系统";
        QTreeWidgetItem *pf=new QTreeWidgetItem(ui->treeWidget,l);//创造主干也就是第一行
       ui->treeWidget->addTopLevelItem(pf);//给第一行命名

    l.clear();
        l<<"学生管理";
    QTreeWidgetItem *p1=new QTreeWidgetItem(pf,l);//给一个分支命名
    l.clear();
    l<<"管理员管理";
        QTreeWidgetItem *p2=new QTreeWidgetItem(pf,l);//给第二个分支命名

    pf->addChild(p1);
    pf->addChild(p2);//把p1与p2成为主干的分支

    ui->treeWidget->expandAll();//默认主干打开
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_exit_clicked()
{
    exit(0);//主页面的退出
}

