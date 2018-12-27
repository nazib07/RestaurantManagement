#ifndef USERROW_H
#define USERROW_H

#include <QWidget>
#include <userregidata.h>

namespace Ui {
class UserRow;
}

class UserRow : public QWidget
{
    Q_OBJECT

public:
    explicit UserRow(QWidget *parent = 0);
    ~UserRow();



    UserRegiData *getUser() const;
    void setUser(UserRegiData *value);

private:
    Ui::UserRow *ui;
    UserRegiData *user;

signals:

    void signal_userRemoved(QString);
    void signal_userEdited(UserRegiData*);
    void signal_userViewed(UserRegiData*);

private slots:
    void on_btn_View_clicked();
    void on_btn_Edit_clicked();
    void on_btn_Remove_clicked();
};

#endif // USERROW_H
