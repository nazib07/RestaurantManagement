#ifndef FORMTEMPFOODITEM_H
#define FORMTEMPFOODITEM_H

#include <QWidget>
#include <QString>
#include <tempfooditem.h>
#include <QListWidgetItem>

namespace Ui {
class FormtempFoodItem;

}

class FormtempFoodItem : public QWidget
{
    Q_OBJECT

public:
    void setName(QString);
    void setQuantity(QString);
    void setPrice(QString);
    int getQuantity();
    int getChangedQuantity();
    explicit FormtempFoodItem(QWidget *parent = 0);
    ~FormtempFoodItem();


    Ui::FormtempFoodItem *getUi() const;
    void setUi(Ui::FormtempFoodItem *value);

    void setCheckBoxChecked();



    QListWidgetItem *getMyItem() const;
    void setMyItem(QListWidgetItem *value);

    Food *getMyFood() const;
    void setMyFood(Food *value);

    void calcSubTotal();

private:
    Ui::FormtempFoodItem *ui;
    QListWidgetItem *myItem;
    Food *myFood;


};

#endif // FORMTEMPFOODITEM_H
