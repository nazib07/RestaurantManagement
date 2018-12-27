#ifndef USERVIEW_H
#define USERVIEW_H

#include <QWidget>

namespace Ui {
class UserView;
}

class UserView : public QWidget
{
    Q_OBJECT

public:
    explicit UserView(QWidget *parent = 0);
    ~UserView();

    QString getName() const;
    void setName(const QString &value);

    QString getType() const;
    void setType(const QString &value);

    QString getAddress() const;
    void setAddress(const QString &value);

    QString getMobile() const;
    void setMobile(const QString &value);

    QString getPhoto() const;
    void setPhoto(const QString &value);

private:
    Ui::UserView *ui;
    QString name;
    QString type;
    QString address;
    QString mobile;
    QString photo;
};

#endif // USERVIEW_H
