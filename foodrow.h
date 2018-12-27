#ifndef FOODROW_H
#define FOODROW_H

#include <QWidget>
#include "food.h"

namespace Ui {
class FoodRow;
}

class FoodRow : public QWidget
{
    Q_OBJECT

public:
    explicit FoodRow(QWidget *parent = 0);
    ~FoodRow();
    void SetFood(Food*);

private:
    Ui::FoodRow *ui;
    Food* food;

signals:

    void signal_foodRemoved(QString);
    void signal_foodEdited(Food*);
private slots:
    void on_btn_Edit_clicked();
    void on_btn_Remove_clicked();
};

#endif // FOODROW_H
