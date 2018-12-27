#include "userview.h"
#include "ui_userview.h"

UserView::UserView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserView)
{
    ui->setupUi(this);
}

UserView::~UserView()
{
    delete ui;
}
QString UserView::getName() const
{
    return name;
}

void UserView::setName(const QString &value)
{
    name = value;
    ui->lbl_name->setText(name);
}
QString UserView::getType() const
{
    return type;
}

void UserView::setType(const QString &value)
{
    type = value;
    ui->lbl_type->setText(type);
}
QString UserView::getAddress() const
{
    return address;
}

void UserView::setAddress(const QString &value)
{
    address = value;
    ui->lbl_Address->setText(address);
}
QString UserView::getMobile() const
{
    return mobile;
}

void UserView::setMobile(const QString &value)
{
    mobile = value;
    ui->lbl_mobile->setText(mobile);
}
QString UserView::getPhoto() const
{
    return photo;
}

void UserView::setPhoto(const QString &value)
{
    photo = value;
    QImage image;

    image = QImage(photo);
    image = image.scaled(100, 100,Qt::KeepAspectRatio);
    ui->lbl_photo->setPixmap(QPixmap::fromImage(image));
}





