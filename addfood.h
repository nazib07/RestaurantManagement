#ifndef ADDFOOD_H
#define ADDFOOD_H

#include <QWidget>
#include "food.h"

namespace Ui {
class addFood;
}

class addFood : public QWidget
{
    Q_OBJECT

public:
    explicit addFood(QWidget *parent = 0);
    ~addFood();
    void setCatagoryList(QStringList);

private:
    Ui::addFood *ui;
    QString catagory;
signals:
    void signal_foodAdded(Food*);
private slots:
    void on_btn_AddFood_clicked();
    void onCatagoryActivated(QString);
};

#endif // ADDFOOD_H
