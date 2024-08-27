#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRandomGenerator>//64???
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrCitySql(nullptr)
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

    m_ptrCitySql=citySql::getinstance();
    if(m_ptrCitySql)
        m_ptrCitySql->init();//数据库初始化????
    m_lNames<<"山西";
    m_lNames<<"山东";
    m_lNames<<"河北";
    m_lNames<<"河南";

    auto cnt=m_ptrCitySql->getCityCnt();
    QList<CityInfo> lCities=m_ptrCitySql->getPageCity(0,cnt);


    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<lCities.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(lCities[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(lCities[i].PointX)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(lCities[i].PointY)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_exit_clicked()
{
    exit(0);//主页面的退出
}


void MainWindow::on_btn_simulation_clicked()
{

    QRandomGenerator x,y;
    x.seed(0);
    y.seed(0);
    for(int i=0;i<m_lNames.size();i++)
    {
        auto px=x.bounded(7.10);
        auto py=y.bounded(1,8);
        CityInfo info;
        info.name=m_lNames[i];
        info.PointX=px;
        info.PointY=py;
        m_ptrCitySql->addCity(info);
    }
}

