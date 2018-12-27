#include "updatefood.h"
#include "ui_updatefood.h"

UpdateFood::UpdateFood(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdateFood)
{
    ui->setupUi(this);

}

UpdateFood::~UpdateFood()
{
    delete ui;
}

void UpdateFood::setPrevFood(Food *food)
{
    this->prev_food = food;
    ui->led_name->setText(food->getName());
    ui->led_price->setText(QString::number(food->getPrice()));
    ui->combo_catagoryList->setCurrentText(food->getCatagroy());
}

void UpdateFood::setCatagoryList(QStringList list)
{
    ui->combo_catagoryList->addItems(list);
    connect(ui->combo_catagoryList, SIGNAL(activated(QString)), this, SLOT(onCatagoryActivated(QString)));

}

void UpdateFood::on_btn_EditFood_clicked()
{
    Food *newFood = new Food();
    newFood->setName(ui->led_name->text());
    newFood->setCatagroy(this->Catagory);
    newFood->setPrice(ui->led_price->text().toFloat());

    emit UpdateFoodButtonClicked( prev_food,newFood);
    this->close();
}

void UpdateFood::onCatagoryActivated(QString cat)
{
this->Catagory = cat;
}
