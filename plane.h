#ifndef PLANE_H
#define PLANE_H

#include <QDialog>
#include"citysql.h"
namespace Ui {
class Plane;
}

class Plane : public QDialog
{
    Q_OBJECT

public:
    explicit Plane(QWidget *parent = nullptr);
    ~Plane();

private slots:

    void on_btn_canclePlane_clicked();
private:
    void upDatePlaneTable();
private:
    Ui::Plane *ui;
    citySql* m_ptrPlaneSql;//负责进入sql和操作数据的指针
};

#endif // PLANE_H
