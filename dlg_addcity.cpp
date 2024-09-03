#include "dlg_addcity.h"
#include "ui_dlg_addcity.h"

#include<QMessageBox>
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
    }
    else
    {

        ptr->UpdateCityInfo(info);
    }

    QMessageBox::information(nullptr,"信息","存储成功");
    this->hide();
}


void Dlg_AddCity::on_btn_cancel_clicked()
{
    this->hide();
}

