#include "foodcatagory.h"
#include "ui_foodcatagory.h"

FoodCatagory::FoodCatagory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FoodCatagory)
{
    ui->setupUi(this);
}

FoodCatagory::~FoodCatagory()
{
    delete ui;
}

void FoodCatagory::SetCatagory(QString str)
{
    ui->lbl_Catagory->setText(str);
}

void FoodCatagory::SetImage(QImage img)
{
    //  ui->lbl_ImageName->setPixmap(QPixmap::fromImage(img));
}

void FoodCatagory::SetName(QString str)
{
    this->name = str;
    ui->lbl_Catagory->setText(str);
}

QString FoodCatagory::GetName()
{
    return this->name;
}


void FoodCatagory::on_btn_Remove_clicked()
{

    qDebug()<<"remove button Clicked"<<GetName();
    emit signal_foodCataoryRemoved(GetName());
}

void FoodCatagory::on_btn_Edit_clicked()
{
     qDebug()<<"Edit button Clicked"<<GetName();
     emit signal_foodCataoryEdited(GetName());
     this->close();
}
