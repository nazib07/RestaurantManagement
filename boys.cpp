#include "boys.h"

Boys::Boys()
{
}

void Boys::setName(QString name)
{
    this->name = name;
}

QString Boys::getName()
{
    return this->name;
}

void Boys::setAddress(QString address)
{
    this->address = address;
}

QString Boys::getAddress()
{
    return this->address;
}

void Boys::setPhoto(QString photo)
{
    this->photo = photo;
}

QString Boys::getPhoto()
{
    return this->photo;
}
QString Boys::getMobile() const
{
    return mobile;
}

void Boys::setMobile(const QString &value)
{
    mobile = value;
}

