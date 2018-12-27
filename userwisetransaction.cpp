#include "userwisetransaction.h"
#include "ui_userwisetransaction.h"

UserWiseTransaction::UserWiseTransaction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWiseTransaction)
{
    ui->setupUi(this);
    connect(ui->chk_AllUser, SIGNAL(stateChanged(int)), this, SLOT(onChkAllUserStateChanged(int)));
}

UserWiseTransaction::~UserWiseTransaction()
{
    delete ui;
}

void UserWiseTransaction::onChkAllUserStateChanged(int state)
{
    if(state == 0)
    {
        ui->combo_SelectUser->setEnabled(true);
    }
    else
    {
        ui->combo_SelectUser->setEnabled(false);
    }
    //   qDebug()<<state;
}

void UserWiseTransaction::onSignalAdminPanelUserWiseButtonRecieved(QVector<QString> allUserName)
{
    for(int i=0; i<allUserName.size(); i++)
    {
        ui->combo_SelectUser->addItem(allUserName.at(i));
    }
}

void UserWiseTransaction::on_btn_Submit_clicked()
{
    QString selectedUser = "ALL";

    if(!ui->chk_AllUser->isChecked())
    {
        selectedUser = ui->combo_SelectUser->currentText();
    }

    emit signal_onUserSelectedForTransaction(selectedUser);
    this->close();
}
