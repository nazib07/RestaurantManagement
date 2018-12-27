#include "diningtables.h"
#include "ui_diningtables.h"

DiningTables::DiningTables(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiningTables)
{
    ui->setupUi(this);
}

DiningTables::~DiningTables()
{
    delete ui;
}

void DiningTables::SetName(QString name)
{
    ui->tableName->setText(name);
}

void DiningTables::on_btn_RemoveTable_clicked()
{
    this->close();
    emit signal_tableRemoved(ui->tableName->text());
}

void DiningTables::on_btn_EditTable_clicked()
{
    emit signal_tableEdited(ui->tableName->text());
}
