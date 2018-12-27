#ifndef USEREDIT_H
#define USEREDIT_H

#include <QWidget>
#include "userregidata.h"

namespace Ui {
class UserEdit;
}

class UserEdit : public QWidget
{
    Q_OBJECT

public:
    explicit UserEdit(QWidget *parent = 0);
    ~UserEdit();


    UserRegiData *getUserData() const;
    void setUserData(UserRegiData *value);

protected:
    void closeEvent(QCloseEvent * event);

private slots:
    void on_btn_Browse_clicked();

    void on_btn_Edit_clicked();

private:
    Ui::UserEdit *ui;
    QImage image;

    UserRegiData *userData;

signals:
    void UserEditButtonClicked(UserRegiData*,UserRegiData*);
    void onCloseEvent();


};

#endif // USEREDIT_H
