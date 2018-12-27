#include "boyview.h"
#include "ui_boyview.h"

boyView::boyView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::boyView)
{
    ui->setupUi(this);
}

boyView::~boyView()
{
    delete ui;
}

void boyView::setBoy(Boys *boy)
{
    ui->lbl_address->setText(boy->getAddress());
    ui->lbl_mobile->setText(boy->getMobile());
    ui->lbl_name->setText(boy->getName());
    ui->lbl_Photo->setPixmap(QPixmap::fromImage(QImage(boy->getPhoto())));
}
