#include "catagory.h"

Catagory::Catagory()
{
}
QString Catagory::getCatagoryDescription() const
{
    return catagoryDescription;
}

void Catagory::setCatagoryDescription(const QString &value)
{
    catagoryDescription = value;
}
QPixmap Catagory::getCatagoryImage() const
{
    return catagoryImage;
}

void Catagory::setCatagoryImage(const QPixmap &value)
{
    catagoryImage = value;
}
QString Catagory::getCatagoryName() const
{
    return catagoryName;
}

void Catagory::setCatagoryName(const QString &value)
{
    catagoryName = value;
}
int Catagory::getId() const
{
    return id;
}

void Catagory::
setId(int value)
{
    id = value;
}




