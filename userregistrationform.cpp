#include "userregistrationform.h"
#include "ui_userregistrationform.h"

#include <QFileDialog>

UserRegistrationForm::UserRegistrationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserRegistrationForm)
{
    ui->setupUi(this);
}

UserRegistrationForm::~UserRegistrationForm()
{
    delete ui;
}




void UserRegistrationForm::on_btn_Browse_clicked()
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

void UserRegistrationForm::on_btn_Submit_clicked()
{
    userData = new UserRegiData();

    userData->setName(ui->led_name->text());
    userData->setPass(ui->led_pass->text());
    userData->setMobile(ui->led_mobile->text());
    userData->setAddress(ui->led_address->text());
    userData->setType(ui->combo_type->currentText());

    QString imagePath =QDir::currentPath()+QString("/UserPhotos/")+ (ui->led_name->text())+QString(".jpg");
    image.save(imagePath);
    userData->setPhoto(imagePath);

    emit signal_UserRegiButtonSubmitted(userData);
    this->close();

}
