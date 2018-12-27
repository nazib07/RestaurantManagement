#include "addnewtable.h"
#include "ui_addnewtable.h"

AddNewTable::AddNewTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewTable)
{
    ui->setupUi(this);
}

AddNewTable::~AddNewTable()
{
    delete ui;
}

void AddNewTable::on_btn_AddTable_clicked()
{
    emit AddTableNewButtonClicked(ui->led_tableName->text());
    this->close();
}
