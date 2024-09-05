#ifndef DLG_QUERY_H
#define DLG_QUERY_H

#include <QDialog>
#include<querycity.h>
extern double radium;
namespace Ui {
class dlg_query;
}

class dlg_query : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_query(QWidget *parent = nullptr);
    ~dlg_query();
    double getRadium();
private slots:
    void on_btn_sureRadium_clicked();

    void on_btn_cancelRadium_clicked();

private:
    Ui::dlg_query *ui;
    QueryCity m_QueryCityResult;
};

#endif // DLG_QUERY_H
