#include "tablestatus.h"
#include "ui_tablestatus.h"

TableStatus::TableStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableStatus)
{
    ui->setupUi(this);
}

TableStatus::~TableStatus()
{
    delete ui;
}
QString TableStatus::getTableName() const
{
    return tableName;
}

void TableStatus::setTableName(const QString &value)
{
    tableName = value;
    ui->tableName->setText(tableName);
}
bool TableStatus::getTableStatus() const
{
    return tableStatus;
}

void TableStatus::setTableStatus(bool value)
{
   QPixmap led;
    tableStatus = value;
    QImage img;
    if(value == TableStatus::ON)
    {
        img =  QImage(":/led/green-led.png");
//        img = img.scaled(60, 60,Qt::KeepAspectRatio);
        led = QPixmap::fromImage(img);
    }
    if(value == TableStatus::OFF)
    {
         led = QPixmap::fromImage(QImage(":/led/red-led.png"));
    }
    ui->statusLed->setPixmap(led);
}


