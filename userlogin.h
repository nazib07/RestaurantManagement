#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>
#include <QDebug>
#include "util.h"
#include "mainwindow.h"

namespace Ui {
class UserLogin;
}

class UserLogin : public QWidget
{
    Q_OBJECT

public:
    explicit UserLogin(QWidget *parent = 0);
    ~UserLogin();

private slots:
    void on_btn_Login_clicked();

private:
    Ui::UserLogin *ui;
    Util util;
    QSqlDatabase db;
signals:
    void  signal_LoggedInUserType(QString, QString);
};

#endif // USERLOGIN_H
