#include "boyrow.h"
#include "ui_boyrow.h"

BoyRow::BoyRow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoyRow)
{
    ui->setupUi(this);
}

BoyRow::~BoyRow()
{
    delete ui;
}

void BoyRow::SetName(QString name)
{
    ui->lbl_boyName->setText(name);
}

void BoyRow::SetBoy(Boys *boy)
{
    this->boy = boy;
    ui->lbl_boyName->setText(boy->getName());
}

void BoyRow::on_btn_ViewBoy_clicked()
{
    emit signal_boyViewed(boy);
}

void BoyRow::on_btn_EditBoy_clicked()
{
    emit signal_boyEdited(boy);
}

void BoyRow::on_btn_RemoveBoy_clicked()
{
    emit signal_boyRemoved(ui->lbl_boyName->text());
}
