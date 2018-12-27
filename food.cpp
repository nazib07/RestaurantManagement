#include "food.h"

Food::Food():quantity(1)
{
}
int Food::getId() const
{
    return Id;
}

void Food::setId(int value)
{
    Id = value;
}

bool Food::operator==(const Food &other)
{
    return ( (this->getName() == other.getName()) && (this->getCatagroy() == other.getCatagroy()) );
}

QString Food::getName() const
{
    return Name;
}

void Food::setName(const QString &value)
{
    Name = value;
}
QString Food::getCatagroy() const
{
    return Catagroy;
}

void Food::setCatagroy(QString value)
{
    Catagroy = value;
}
QPixmap Food::getImage() const
{
    return Image;
}

void Food::setImage(const QPixmap &value)
{
    Image = value;
}
QString Food::getDescription() const
{
    return Description;
}

void Food::setDescription(const QString &value)
{
    Description = value;
}
//FormtempFoodItem *Food::getMyForm() const
//{
//    return myForm;
//}

//void Food::setMyForm(FormtempFoodItem *value)
//{
//    myForm = value;
//}






