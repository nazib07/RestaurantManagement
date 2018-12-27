#ifndef BOYS_H
#define BOYS_H
#include<QString>

class Boys
{
public:
    Boys();
    void setName(QString name);
    QString getName();
    void setAddress(QString address);
    QString getAddress();
    void setPhoto(QString photo);
    QString getPhoto();
    QString getMobile() const;
    void setMobile(const QString &value);

private:
    QString name;
    QString address;
    QString photo;
    QString mobile;

};

#endif // BOYS_H
