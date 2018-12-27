#ifndef ORDER_H
#define ORDER_H

#include <QString>


class Order
{
public:
    Order();

    QString getItem() const;
    void setItem(const QString &value);

    QString getOrder_id() const;
    void setOrder_id(const QString &value);

    int getAmount() const;
    void setAmount(int value);

private:
    QString item;
    QString order_id;
    int amount;
};

#endif // ORDER_H
