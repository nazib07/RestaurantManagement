#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QWidget>
#include "adminwindow.h"
#define userName "admin"
#define password "admin"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = 0);
    ~AdminLogin();


private slots:
    void on_btn_Login_clicked();
    void onAdminLogoutClicked();

private:
    Ui::AdminLogin *ui;
signals:
    void signal_AdminLogouted();

};

#endif // ADMINLOGIN_H
