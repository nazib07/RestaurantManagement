#include "foodrow.h"
#include "ui_foodrow.h"

FoodRow::FoodRow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FoodRow)
{
    ui->setupUi(this);
}

FoodRow::~FoodRow()
{
    delete ui;
}

void FoodRow::SetFood(Food *food)
{
    ui->lbl_name->setText(food->getName());
    ui->lbl_catagory->setText(food->getCatagroy());
    ui->Price->setText(QString::number(food->getPrice()));
    this->food = food;
}

void FoodRow::on_btn_Edit_clicked()
{
    emit signal_foodEdited(this->food);
}

void FoodRow::on_btn_Remove_clicked()
{
    emit signal_foodRemoved(this->food->getName());
}
