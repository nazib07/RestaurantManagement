#include "addboy.h"
#include "ui_addboy.h"

#include <QFileDialog>

AddBoy::AddBoy(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::AddBoy)
{
    ui->setupUi(this);
}

AddBoy::~AddBoy()
{
    delete ui;
}

void AddBoy::on_btn_AddBoy_clicked()
{
    QString imagePath;
    Boys* boy = new Boys();
    boy->setName(ui->boy_name->text());
    boy->setAddress(ui->boy_address->text());
    boy->setMobile(ui->boy_mobile->text());
    if(!image.isNull() && ui->boy_name->text()!= NULL)

    {
        imagePath =QDir::currentPath()+QString("/BoyPhotos/")+ (ui->boy_name->text())+QString(".jpg");
        image.save(imagePath);
        boy->setPhoto(imagePath);
        emit signal_boyAdded(boy);

        this->close();
    }



}

void AddBoy::on_btn_browseImage_clicked()
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
        ui->lbl_image->setPixmap(QPixmap::fromImage(image));

    }
}
