#ifndef UPDATETABLE_H
#define UPDATETABLE_H

#include <QWidget>

namespace Ui {
class updateTable;
}

class updateTable : public QWidget
{
    Q_OBJECT

public:
    explicit updateTable(QWidget *parent = 0);
    ~updateTable();
    void setPrevName(QString);

private:
    Ui::updateTable *ui;
    QString prev_name;
signals:
    void UpdateTableButtonClicked(QString, QString);
private slots:
    void on_btn_EditTable_clicked();
};

#endif // UPDATETABLE_H
