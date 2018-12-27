#include "order.h"

Order::Order()
{
}
QString Order::getItem() const
{
    return item;
}

void Order::setItem(const QString &value)
{
    item = value;
}
QString Order::getOrder_id() const
{
    return order_id;
}

void Order::setOrder_id(const QString &value)
{
    order_id = value;
}
int Order::getAmount() const
{
    return amount;
}

void Order::setAmount(int value)
{
    amount = value;
}



