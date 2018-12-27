#ifndef CATAGORY_H
#define CATAGORY_H
#include <QString>
#include <QPixmap>

class Catagory
{
public:
    Catagory();
    QString getCatagoryDescription() const;
    void setCatagoryDescription(const QString &value);

    QPixmap getCatagoryImage() const;
    void setCatagoryImage(const QPixmap &value);

    QString getCatagoryName() const;
    void setCatagoryName(const QString &value);

    int getId() const;
    void setId(int value);

private:
    int id;
    QString catagoryName;
    QPixmap catagoryImage;
    QString catagoryDescription;
public:
    enum Catagory_DB_Names
    {
        ID = 0,
        NAME,
        IMAGE_PATH,
        DESCRIPTION,

        ALL_DB_NAMES
    };
};

#endif // CATAGORY_H
