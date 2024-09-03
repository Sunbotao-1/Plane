#ifndef QUERYCITY_H
#define QUERYCITY_H

#include <QDialog>
#include<citysql.h>
namespace Ui {
class QueryCity;
}

class QueryCity : public QDialog
{
    Q_OBJECT

public:
    explicit QueryCity(QWidget *parent = nullptr);
    ~QueryCity();
    friend class QueryCity;

    void updateTable();
private:
    Ui::QueryCity *ui;
    citySql* m_ptrCitySql;//负责进入sql和操作数据的指针
};

#endif // QUERYCITY_H
