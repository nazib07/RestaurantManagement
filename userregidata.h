#include <QString>

#ifndef USERREGIDATA_H
#define USERREGIDATA_H

class UserRegiData
{
public:
    UserRegiData();
    QString getName() const;
    void setName(const QString &value);

    QString getPass() const;
    void setPass(const QString &value);

    QString getType() const;
    void setType(const QString &value);

    QString getMobile() const;
    void setMobile(const QString &value);

    QString getAddress() const;
    void setAddress(const QString &value);

    QString getPhoto() const;
    void setPhoto(const QString &value);

private:
    QString name;
    QString pass;
    QString type;
    QString mobile;
    QString address;
    QString photo;
};

#endif // USERREGIDATA_H
