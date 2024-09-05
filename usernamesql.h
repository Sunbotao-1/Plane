#ifndef USERNAMESQL_H
#define USERNAMESQL_H

#include <QObject>
#include <QSqlDatabase>
struct UserInfo
{
    QString username;
    QString password;
    QString aut;//权限
};//用户信息
class usernameSql : public QObject
{
    Q_OBJECT
public:
    explicit usernameSql(QObject *parent = nullptr);

signals:

private
};

#endif // USERNAMESQL_H
