#include "plane.h"
#include "ui_plane.h"
#include"citysql.h"

Plane::Plane(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Plane)
{
    ui->setupUi(this);

    m_ptrPlaneSql=citySql::getinstance();
    m_ptrPlaneSql->init();
    upDatePlaneTable();
}

Plane::~Plane()
{
    delete ui;
}

void Plane::on_btn_canclePlane_clicked()
{
    this->hide();
}

void Plane::upDatePlaneTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(1);
     ui->tableWidget->setRowCount(5);
    QStringList l ;
    l<<"编号"<<"名称"<<"重量"<<"横坐标"<<"纵坐标";
    ui->tableWidget->setVerticalHeaderLabels(l);
    //只选中行
    //ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // auto cnt = m_ptrCitySql->getCityCnt();
    // ui->lb_cnt->setText(QString("学生总数:%1").arg(cnt));
    QList<PlaneInfo>  lPlane =m_ptrPlaneSql->getPlane();


    ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::number(lPlane[0].id)));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem(lPlane[0].name));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem(QString::number(lPlane[0].weight)));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem(QString::number(lPlane[0].PointX)));
    ui->tableWidget->setItem(4,0,new QTableWidgetItem(QString::number(lPlane[0].PointY)));





}



