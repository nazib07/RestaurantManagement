#ifndef USERS_H
#define USERS_H

#include <QWidget>
#include "userregidata.h"
#include <QDebug>
#include <QVector>
#include "userrow.h"
#include "userregistrationform.h"


namespace Ui {
class Users;
}

class Users : public QWidget
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = 0);
    ~Users();

private:
    Ui::Users *ui;
public slots:
    void onAdminWindowUsersBtnClicked(QVector<UserRegiData*>);


    void onUserRemoved(QString);
    void onUserEdited(UserRegiData*);
    void onUserViewed(UserRegiData*);

    void onUserRegiButtonSubmitted(UserRegiData*);


signals:
    void signal_userRemoved(QString);
    void signal_userEdited(UserRegiData*);
    void signal_userViewed(UserRegiData*);
    void signal_UserRegiSubmitted(UserRegiData*);



private slots:
    void on_btn_AddUser_clicked();
};

#endif // USERS_H
