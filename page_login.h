#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>

namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login(QWidget *parent = nullptr);
    ~Page_Login();

private slots:
    void on_btn_login_clicked();
    void on_pushButton_2_clicked();
signals:
    void sendLoginSuccess();//成功登录后的显示
private:
    Ui::Page_Login *ui;
};

#endif // PAGE_LOGIN_H
