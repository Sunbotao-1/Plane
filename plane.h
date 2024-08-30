#ifndef PLANE_H
#define PLANE_H

#include <QDialog>

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
    void on_btn_cancle1_clicked();

private:
    Ui::Plane *ui;
};

#endif // PLANE_H
