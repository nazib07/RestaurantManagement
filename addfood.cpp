#include "addfood.h"
#include "ui_addfood.h"

addFood::addFood(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addFood)
{
    ui->setupUi(this);
}

addFood::~addFood()
{
    delete ui;
}

void addFood::setCatagoryList(QStringList list)
{
ui->combo_Catagory->addItems(list);
connect(ui->combo_Catagory, SIGNAL(activated(QString)), this, SLOT(onCatagoryActivated(QString)));

}

void addFood::on_btn_AddFood_clicked()
{
    Food* food = new Food();
    food->setName(ui->led_foodName->text());
    food->setPrice(ui->led_Price->text().toFloat());
    food->setCatagroy(this->catagory);

    emit signal_foodAdded(food);
    this->close();
}

void addFood::onCatagoryActivated(QString cat)
{
    this->catagory = cat;

}
