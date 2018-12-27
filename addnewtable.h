#ifndef ADDNEWTABLE_H
#define ADDNEWTABLE_H

#include <QWidget>

namespace Ui {
class AddNewTable;
}

class AddNewTable : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewTable(QWidget *parent = 0);
    ~AddNewTable();

private:
    Ui::AddNewTable *ui;
signals:
    void AddTableNewButtonClicked(QString);
private slots:
    void on_btn_AddTable_clicked();
};

#endif // ADDNEWTABLE_H
