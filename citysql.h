#ifndef CITYSQL_H
#define CITYSQL_H

#include <QObject>
#include <QSqlDatabase>
struct CityInfo
{
    int id;
    QString name;
    double PointX;
    double PointY;
};//城市信息

struct UserInfo
{
    QString username;
    QString password;
    QString aut;//权限
};//用户信息
struct PlaneInfo
{
    int id;
    QString name;
    double weight;
    double PointX;
    double PointY;
};

class citySql : public QObject
{
    Q_OBJECT
public:
    static citySql *ptrCitySql;//静态变量
    static citySql *getinstance()//实例化函数
    {
        if(nullptr == ptrCitySql)
        {
            ptrCitySql = new citySql;
        }
        return ptrCitySql;
    }
    explicit citySql(QObject *parent = nullptr);

    void init();//初始化
    //查询所有城市数量(同步接口)(主线程)
    quint32 getCityCnt();
    //查询第几页城市数据,页数从0开始
    QList<CityInfo> getPageCity(quint32 page,quint32 uiCnt);//参数一:页数,参数二:数量.;目的:获取某一页数据.
    //增加城市(一次加一个）
    bool addCity(CityInfo);
    //删除城市
    bool delCity(int id);
    //清空城市表
    void clearCityTable();
    //修改城市
    void UpdateCityInfo(CityInfo info);
    //查询所有用户
    QList<UserInfo> getAllUser();
    //查询用户名是否存在
    bool isExist(QString strUser);
    //更新用户信息
   bool updateUser(UserInfo info);
    //添加单个用户
    bool addUser(UserInfo info);

    //删除单个用户
    bool delUser(QString strUserName);

    QList<PlaneInfo> getPlane();
signals:

private:
    QSqlDatabase m_db;
};

#endif // CITYSQL_H
