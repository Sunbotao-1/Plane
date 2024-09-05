#ifndef DLG_ADDCITY_H
#define DLG_ADDCITY_H

#include <QDialog>
#include"citysql.h"
namespace Ui {
class Dlg_AddCity;
}

class Dlg_AddCity : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_AddCity(QWidget *parent = nullptr);
    ~Dlg_AddCity();

    void setType(bool isAdd,CityInfo info={});
private slots:

    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dlg_AddCity *ui;
    bool m_isAdd;
    CityInfo m_info;
};

#endif // DLG_ADDCITY_H
