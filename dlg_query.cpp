#include "dlg_query.h"
#include "ui_dlg_query.h"
#include "citysql.h"
double radium=0;
dlg_query::dlg_query(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dlg_query)
{
    ui->setupUi(this);


    //radium=getRadium();
}

dlg_query::~dlg_query()
{
    delete ui;
}

double dlg_query::getRadium()
{
    return ui->le_radius->text().toDouble();
}

void dlg_query::on_btn_sureRadium_clicked()
{
   // double Radium=ui->le_radius->text().toDouble();
    radium=ui->le_radius->text().toDouble();
    m_QueryCityResult.updateTable();
    m_QueryCityResult.exec();
}


void dlg_query::on_btn_cancelRadium_clicked()
{
    this->hide();
}

