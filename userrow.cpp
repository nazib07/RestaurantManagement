#include "userrow.h"
#include "ui_userrow.h"

UserRow::UserRow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserRow)
{
    ui->setupUi(this);
}

UserRow::~UserRow()
{
    delete ui;
}
UserRegiData *UserRow::getUser() const
{
    return user;
}

void UserRow::setUser(UserRegiData *value)
{

    user = value;
    ui->lbl_name->setText(user->getName());
}



void UserRow::on_btn_View_clicked()
{
    emit signal_userViewed(this->getUser());
}


void UserRow::on_btn_Edit_clicked()
{
    emit signal_userEdited(this->getUser());
}

void UserRow::on_btn_Remove_clicked()
{
    emit signal_userRemoved(this->getUser()->getName());
}
