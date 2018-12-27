#ifndef FOOD_H
#define FOOD_H
#include <QString>
#include <QPixmap>


class Food
{
public:
    Food();
    int getId() const;
    void setId(int value);
    bool operator==( const Food &other);
    QString getName() const;
    void setName(const QString &value);

    QString getCatagroy() const;
    void setCatagroy(QString value);

    QPixmap getImage() const;
    void setImage(const QPixmap &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getQuantity(){
        return quantity;
    }
    void setQuantity(int newQuan ){
        quantity = newQuan;
    }
    void addQuantity(int add){
        quantity += add;
    }
    void setPrice(float p)
    {
        Price = p;
    }
    float getPrice()
    {
        return Price;
    }

private:
    int Id;
    int quantity;
    QString Name;
    QString Catagroy;
    QPixmap Image;
    QString Description;
    float Price;
   // FormtempFoodItem *myForm;

public:
    enum FOOD_DB_NAMES
    {
        ID = 0,
        NAME,
        CATAGORY,
        PRICE,
        IMAGE_PATH,
        DESCRIPTION,

        ALL_FOOD_DB_NAMES

    };


   // FormtempFoodItem *getMyForm() const;
   // void setMyForm(FormtempFoodItem *value);
};



#endif // FOOD_H
