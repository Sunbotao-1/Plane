#include "dlg_addcity.h"
#include "ui_dlg_addcity.h"
#include<fstream>
#include<QMessageBox>
#include<QDateTime>
Dlg_AddCity::Dlg_AddCity(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_AddCity)
{
    ui->setupUi(this);
}

Dlg_AddCity::~Dlg_AddCity()
{
    delete ui;
}

void Dlg_AddCity::setType(bool isAdd,CityInfo info)
{
    m_isAdd=isAdd;
    m_info=info;
    ui->le_id->setText(QString::number(info.id));
    ui->le_name->setText(info.name);
    ui->le_X->setText(QString::number(info.PointX));
    ui->le_Y->setText(QString::number(info.PointY));
}

void Dlg_AddCity::on_btn_save_clicked()
{
    CityInfo info;
    auto ptr=citySql::getinstance();
    info.id=ui->le_id->text().toUInt();
    info.name=ui->le_name->text();
    info.PointX=ui->le_X->text().toDouble();
    info.PointY=ui->le_Y->text().toDouble();

    if(m_isAdd)
    {
        ptr->addCity(info);
        std::ofstream f;
        f.open("log.txt",std::ios_base::app);
        int id=ui->le_id->text().toUInt();
        std::string name=ui->le_name->text().toStdString();
        double x=ui->le_X->text().toDouble();
        double y=ui->le_Y->text().toDouble();
        f<<"addcity:"<<std::endl<<id<<'\t'<<name<<'\t'<<x<<'\t'<<y<<std::endl;

        QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
        QString str = dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间
        std::string str2=str.toStdString();
        f<<str2<<std::endl;
        f.close();
    }
    else
    {

        ptr->UpdateCityInfo(info);

        std::ofstream f;
        f.open("log.txt",std::ios_base::app);
        int id=ui->le_id->text().toUInt();
        std::string name=ui->le_name->text().toStdString();
        double x=ui->le_X->text().toDouble();
        double y=ui->le_Y->text().toDouble();
        f<<id<<'\t'<<name<<'\t'<<x<<'\t'<<y<<std::endl;

        QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
        QString str = dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间
        std::string str2=str.toStdString();
        f<<str2<<std::endl;
        f.close();
    }

    QMessageBox::information(nullptr,"信息","存储成功");
    this->hide();
}


void Dlg_AddCity::on_btn_cancel_clicked()
{
    this->hide();
}

