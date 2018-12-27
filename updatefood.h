#ifndef UPDATEFOOD_H
#define UPDATEFOOD_H

#include <QWidget>
#include "food.h"


namespace Ui {
class UpdateFood;
}

class UpdateFood : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateFood(QWidget *parent = 0);
    ~UpdateFood();
    void setPrevFood(Food*);
    void setCatagoryList(QStringList);

private:
    Ui::UpdateFood *ui;
    Food* prev_food;
    QString Catagory;

signals:
    void UpdateFoodButtonClicked(Food*, Food*);
private slots:
    void on_btn_EditFood_clicked();
public slots:
    void onCatagoryActivated(QString);
};

#endif // UPDATEFOOD_H
