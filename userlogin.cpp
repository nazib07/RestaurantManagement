#include "userlogin.h"
#include "ui_userlogin.h"

UserLogin::UserLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    db = util.ConnectDatabase(PATH_TO_DB);
}

UserLogin::~UserLogin()
{
    delete ui;
    db.close();
}

void UserLogin::on_btn_Login_clicked()
{
    int count = 0;
    QString userType = "";

    QString user = ui->led_userName->text();
    QString pass = ui->led_password->text();

    if(user == "" || pass == "") return;

    QSqlQuery q;
    q.prepare("SELECT *, COUNT(*) AS count FROM Users WHERE name = :user AND password = :pass");
    q.bindValue(":user", user);
    q.bindValue(":pass", pass);
    bool r = q.exec();


    if(r == true)
    {
        while(q.next())
        {
            count =  q.record().value("count").toInt();
            userType = q.record().value("type").toString();
        }
    }
    else
    {
        qDebug()<<"query false";
    }

    if(count > 0)
    {
        qDebug()<<"Login Success " <<userType;
        MainWindow *w = new MainWindow();
        connect(this, SIGNAL(signal_LoggedInUserType(QString, QString)), w, SLOT(onLoggedInUserTypeRecieved(QString, QString)));
        emit signal_LoggedInUserType(userType, user);
        w->show();
        this->close();


    }
    else
    {
        qDebug()<<"Login Failed";
    }
}
