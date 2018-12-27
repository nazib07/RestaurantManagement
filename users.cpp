#include "users.h"
#include "ui_users.h"

#include <QListWidget>

Users::Users(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);
}

Users::~Users()
{
    delete ui;
}

void Users::onAdminWindowUsersBtnClicked(QVector<UserRegiData*> allUsers)
{
    //////////////////////////////////////////////

    QWidget *widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    qDebug()<<allUsers.size();
    for(int i = 0; i<allUsers.size(); i++)
    {
        UserRow *userRow = new UserRow();
        userRow->setUser(allUsers.at(i));
        layout->addWidget(userRow);


        connect(userRow, SIGNAL(signal_userRemoved(QString)), this, SLOT(onUserRemoved(QString)));
        connect(userRow, SIGNAL(signal_userEdited(UserRegiData*)), this, SLOT(onUserEdited(UserRegiData*)));
        connect(userRow, SIGNAL(signal_userViewed(UserRegiData*)), this, SLOT(onUserViewed(UserRegiData*)));
        //         qDebug()<<"User Name: "<<allUsers.at(i)->getName();
    }

    widget->setLayout(layout);
    ui->scrollArea_Users->setWidget(widget);

//    this->setWindowModality(Qt::ApplicationModal);
//    this->show();
}

void Users::onUserRemoved(QString userName)
{
    emit signal_userRemoved(userName);
    this->close();
}

void Users::onUserEdited(UserRegiData *userData)
{
    emit signal_userEdited(userData);
    this->close();
}

void Users::onUserViewed(UserRegiData *userData)
{
    emit signal_userViewed(userData);
}

void Users::onUserRegiButtonSubmitted(UserRegiData *userData)
{
    emit signal_UserRegiSubmitted(userData);
    this->close();
}

void Users::on_btn_AddUser_clicked()
{
    UserRegistrationForm *user_regi = new UserRegistrationForm();
    connect(user_regi, SIGNAL(signal_UserRegiButtonSubmitted(UserRegiData*)), this, SLOT(onUserRegiButtonSubmitted(UserRegiData*)), Qt::UniqueConnection);
    user_regi->setWindowModality(Qt::ApplicationModal);
    user_regi->show();
}
