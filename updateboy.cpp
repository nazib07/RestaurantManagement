#include "updateboy.h"
#include "ui_updateboy.h"

#include <QFileDialog>

updateBoy::updateBoy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updateBoy)
{
    ui->setupUi(this);
}

updateBoy::~updateBoy()
{
    delete ui;
}
Boys *updateBoy::getPrev_boy() const
{
    return prev_boy;
}

void updateBoy::setPrev_boy(Boys *value)
{
    prev_boy = value;
    ui->led_address->setText(prev_boy->getAddress());
    ui->led_mobile->setText(prev_boy->getMobile());
    ui->led_name->setText(prev_boy->getName());
    ui->lb_showImage->setPixmap(QPixmap::fromImage(QImage(prev_boy->getPhoto())));

    qDebug()<<prev_boy->getPhoto();
}




void updateBoy::on_btn_EditBoy_clicked()
{
    Boys *newBoy = new Boys();
    newBoy->setName(ui->led_name->text());
    newBoy->setAddress(ui->led_address->text());
    newBoy->setMobile(ui->led_mobile->text());

    QString imagePath =QDir::currentPath()+QString("/BoyPhotos/")+ (ui->led_name->text())+QString(".jpg");
    image.save(imagePath);
    newBoy->setPhoto(imagePath);

    emit  UpdateBoyButtonClicked(prev_boy,newBoy);
    this->close();
}

void updateBoy::on_btn_browse_clicked()
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
        ui->lb_showImage->setPixmap(QPixmap::fromImage(image));

    }

}
