#include "querycity.h"
#include "ui_querycity.h"
#include"citysql.h"
#include"dlg_query.h"


QueryCity::QueryCity(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueryCity)
{
    ui->setupUi(this);
    m_ptrCitySql=citySql::getinstance();
    m_ptrCitySql->init();
    updateTable();//先后顺序有问题
}

QueryCity::~QueryCity()
{
    delete ui;
}
void QueryCity::updateTable()
{
   //  dlg_query d(this);
   // // double radium=d.getRadium();//这个函数导致程序崩溃
   //  qDebug()<<radium;
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l ;
    l<<"序号"<<"id"<<"名称"<<"横坐标"<<"纵坐标";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    //只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = m_ptrCitySql->getQueryCityCnt(radium);//待改
    ui->lb_quertCnt->setText(QString("城市总数:%1").arg(cnt));
    QList<CityInfo>  lCities = m_ptrCitySql->getPageQueryCity(0,cnt,radium);//有问题


    ui->tableWidget->setRowCount(cnt);
    for(int i =0;i<lCities.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));//???i变lCities[i].id
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(lCities[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lCities[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(lCities[i].PointX)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lCities[i].PointY)));
    }
}
