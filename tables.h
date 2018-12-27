#ifndef TABLES_H
#define TABLES_H
#include <QString>

class Tables
{
public:
    Tables();
    void setName(QString name){
    this->name = name;
    }

    QString getName()
    {
        return this->name;
    }

    void setType(QString type)
    {
        this->type = type;
    }

    QString getType()
    {
        return this->type;
    }
private:
    QString name;
    QString type;
};

#endif // TABLES_H
