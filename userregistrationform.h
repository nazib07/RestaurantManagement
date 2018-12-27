#ifndef USERREGISTRATIONFORM_H
#define USERREGISTRATIONFORM_H

#include <QWidget>
#include "userregidata.h"

namespace Ui {
class UserRegistrationForm;
}

class UserRegistrationForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserRegistrationForm(QWidget *parent = 0);
    ~UserRegistrationForm();




private slots:
    void on_btn_Browse_clicked();

    void on_btn_Submit_clicked();

private:
    Ui::UserRegistrationForm *ui;
    QImage image;
    UserRegiData *userData;

signals:
    void signal_UserRegiButtonSubmitted(UserRegiData*);


};

#endif // USERREGISTRATIONFORM_H
