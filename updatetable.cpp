#include "updatetable.h"
#include "ui_updatetable.h"

updateTable::updateTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updateTable)
{
    ui->setupUi(this);
}

updateTable::~updateTable()
{
    delete ui;
}

void updateTable::setPrevName(QString name)
{
    prev_name = name;
    ui->led_EditTable->setText(name);
}

void updateTable::on_btn_EditTable_clicked()
{
    emit UpdateTableButtonClicked(prev_name, ui->led_EditTable->text());
    this->close();
}
