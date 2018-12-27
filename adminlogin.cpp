#include "adminlogin.h"
#include "ui_adminlogin.h"

AdminLogin::AdminLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}



void AdminLogin::on_btn_Login_clicked()
{
    QString user = ui->admin_User->text();
    QString pass = ui->admin_Pass->text();

    if(user == userName && pass == password)
    {

        AdminWindow* win = new AdminWindow();
        win->setWindowModality(Qt::ApplicationModal);
        connect(win, SIGNAL(signal_AdminLogout()), this, SLOT(onAdminLogoutClicked()));
        this->close();
        win->show();
    }
}

void AdminLogin::onAdminLogoutClicked()
{
    emit signal_AdminLogouted();
}
