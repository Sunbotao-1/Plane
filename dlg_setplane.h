#ifndef DLG_SETPLANE_H
#define DLG_SETPLANE_H

#include <QDialog>
#include"citysql.h"

namespace Ui {
class dlg_setPlane;
}

class dlg_setPlane : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_setPlane(QWidget *parent = nullptr);
    ~dlg_setPlane();

    void setType(bool isadd,PlaneInfo info={});
private slots:
    void on_btn_ok_clicked();


    void on_btn_no_clicked();

private:
    Ui::dlg_setPlane *ui;
    bool m_isadd;
    PlaneInfo m_info;
};

#endif // DLG_SETPLANE_H
