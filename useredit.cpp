#include "useredit.h"
#include "ui_useredit.h"

#include <QFileDialog>

UserEdit::UserEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserEdit)
{
    ui->setupUi(this);
}

UserEdit::~UserEdit()
{
    delete ui;
}




void UserEdit::on_btn_Browse_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Images"), "C:/", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty())
    {
        image = QImage(fileName);
        image = image.scaled(100, 100,Qt::KeepAspectRatio);
        ui->lbl_photo->setPixmap(QPixmap::fromImage(image));

    }
}

void UserEdit::on_btn_Edit_clicked()
{
    UserRegiData *userData = new UserRegiData();
    userData->setName(ui->led_Name->text());
    userData->setAddress(ui->led_Address->text());
    userData->setMobile(ui->led_Mobile->text());
    userData->setPass(ui->led_Pass->text());
    userData->setType(ui->comboBox->currentText());

    QString imagePath =QDir::currentPath()+QString("/UserPhotos/")+ (ui->led_Name->text())+QString(".jpg");
    image.save(imagePath);
    userData->setPhoto(imagePath);

    emit  UserEditButtonClicked(this->userData,userData);
    this->close();

}
UserRegiData *UserEdit::getUserData() const
{
    return userData;
}

void UserEdit::setUserData(UserRegiData *value)
{
    userData = value;

    ui->led_Name->setText(userData->getName());
    ui->led_Address->setText(userData->getAddress());
    ui->led_Mobile->setText(userData->getMobile());
    ui->led_Pass->setText(userData->getPass());

    QString imagePath = userData->getPhoto();

    QImage image;

    image = QImage(imagePath);
    image = image.scaled(100, 100,Qt::KeepAspectRatio);
    ui->lbl_photo->setPixmap(QPixmap::fromImage(image));

}

void UserEdit::closeEvent(QCloseEvent *event)
{
    emit onCloseEvent();

}

