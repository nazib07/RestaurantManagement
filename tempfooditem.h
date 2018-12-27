#ifndef TEMPFOODITEM_H
#define TEMPFOODITEM_H

#include "food.h"
class tempFoodItem
{
private:
    Food food;
    int quantity;
public:
    tempFoodItem();
    Food getFood() const;
    void setFood(const Food &value);
    int getQuantity() const;
    void setQuantity(int value);
};

#endif // TEMPFOODITEM_H
