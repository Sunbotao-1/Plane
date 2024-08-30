#include "plane.h"
#include "ui_plane.h"

Plane::Plane(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Plane)
{
    ui->setupUi(this);
}

Plane::~Plane()
{
    delete ui;
}

void Plane::on_btn_cancle1_clicked()
{
    this->hide();
}

