#include "formtempfooditem.h"
#include "ui_formtempfooditem.h"
#include "util.h"

void FormtempFoodItem::setName(QString name)
{
    ui->name->setText(name);
}

void FormtempFoodItem::setQuantity(QString qunt)
{
    ui->quantity->setText(qunt);
    //calcSubTotal();
}

void FormtempFoodItem::setPrice(QString price)
{
    ui->price->setText(price);
   // calcSubTotal();
}

int FormtempFoodItem::getQuantity()
{
    return ui->quantity->text().toInt();
}

int FormtempFoodItem::getChangedQuantity()
{
    return ui->lineEdit->text().toInt();
}

FormtempFoodItem::FormtempFoodItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormtempFoodItem)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0, 1000, this));

}

FormtempFoodItem::~FormtempFoodItem()
{
    delete ui;
}
Ui::FormtempFoodItem *FormtempFoodItem::getUi() const
{
    return ui;
}

void FormtempFoodItem::setUi(Ui::FormtempFoodItem *value)
{
    ui = value;
}

void FormtempFoodItem::setCheckBoxChecked()
{
    if(ui->lineEdit->isEnabled() == false)
    {

        ui->lineEdit->setEnabled(true);
        Util::alltempChangedRows.push_back(this);
    }
    else
    {
        ui->lineEdit->setEnabled(false);
        Util::alltempChangedRows.remove(Util::alltempChangedRows.indexOf(this));

    }
}
QListWidgetItem *FormtempFoodItem::getMyItem() const
{
    return myItem;
}

void FormtempFoodItem::setMyItem(QListWidgetItem *value)
{
    myItem = value;
}
Food *FormtempFoodItem::getMyFood() const
{
    return myFood;
}

void FormtempFoodItem::setMyFood(Food *value)
{
    myFood = value;
   // calcSubTotal();
}

void FormtempFoodItem::calcSubTotal()
{
    float subtotal = this->myFood->getPrice() * this->myFood->getQuantity();
    ui->subtotal->setText(QString::number(subtotal));
}








