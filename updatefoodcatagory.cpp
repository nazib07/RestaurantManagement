#include "updatefoodcatagory.h"
#include "ui_updatefoodcatagory.h"

UpdateFoodCatagory::UpdateFoodCatagory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdateFoodCatagory)
{
    ui->setupUi(this);
}

void UpdateFoodCatagory::setPrevName(QString name)
{
    prev_name = name;
    ui->led_catagoryName->setText(name);
}

UpdateFoodCatagory::~UpdateFoodCatagory()
{
    delete ui;
}

void UpdateFoodCatagory::on_btn_EditCatagory_clicked()
{

    emit UpdateCatagoryButtonClicked(prev_name, ui->led_catagoryName->text());
    this->close();
}
