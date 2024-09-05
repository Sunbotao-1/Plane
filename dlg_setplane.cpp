#include "dlg_setplane.h"
#include "ui_dlg_setplane.h"
#include"citysql.h"
#include<QMessageBox>
dlg_setPlane::dlg_setPlane(QWidget *parent):
    QDialog(parent),
    ui(new Ui::dlg_setPlane)
{
    ui->setupUi(this);
}

dlg_setPlane::~dlg_setPlane()
{
    delete ui;
}

void dlg_setPlane::setType(bool isadd,PlaneInfo info)
{
    m_isadd=isadd;
    m_info=info;
    ui->le_pid->setText(QString::number(info.id));
    ui->le_pname->setText(info.name);
    ui->le_pweight->setText(QString::number(info.weight));
    ui->le_px->setText(QString::number(info.PointX));
    ui->le_py->setText(QString::number(info.PointY));
}

void dlg_setPlane::on_btn_ok_clicked()
{
    PlaneInfo info;
    auto ptr=citySql::getinstance();
    info.id=ui->le_pid->text().toUInt();
    info.name=ui->le_pname->text();
    info.weight=ui->le_pweight->text().toDouble();
    info.PointX=ui->le_px->text().toDouble();
    info.PointY=ui->le_py->text().toDouble();
    if(m_isadd)
    {
        ptr->addPlane(info);
    }
    else
    {
        //info.id=m_info.id;
        ptr->UpdatePlaneInfo(info);
    }
    QMessageBox::information(nullptr,"信息","修改成功");
    this->hide();
}

void dlg_setPlane::on_btn_no_clicked()
{
      this->hide();
}

