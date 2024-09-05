#ifndef PASSWORDSQL_H
#define PASSWORDSQL_H

#include <QObject>

class passwordSQL : public QObject
{
    Q_OBJECT
public:
    explicit passwordSQL(QObject *parent = nullptr);

signals:
};

#endif // PASSWORDSQL_H
//判断用户名是否在数据库里
//判断密码是否正确
