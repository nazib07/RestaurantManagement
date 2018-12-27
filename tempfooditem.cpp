#include "tempfooditem.h"


Food tempFoodItem::getFood() const
{
    return food;
}

void tempFoodItem::setFood(const Food &value)
{
    food = value;
}

int tempFoodItem::getQuantity() const
{
    return quantity;
}

void tempFoodItem::setQuantity(int value)
{
    quantity = value;
}
tempFoodItem::tempFoodItem()
{

}
