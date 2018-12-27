#ifndef UPDATEBOY_H
#define UPDATEBOY_H

#include <QWidget>
#include "boys.h"
#include <QDebug>

namespace Ui {
class updateBoy;
}

class updateBoy : public QWidget
{
    Q_OBJECT

public:
    explicit updateBoy(QWidget *parent = 0);
    ~updateBoy();



    Boys *getPrev_boy() const;
    void setPrev_boy(Boys *value);

private:
    Ui::updateBoy *ui;
    Boys *prev_boy;
    QImage image;
    // QString prev_name,prev_address,prev_mobile,prev_photo;
signals:
    void  UpdateBoyButtonClicked(Boys*,Boys*);
private slots:
    void on_btn_EditBoy_clicked();
    void on_btn_browse_clicked();
};

#endif // UPDATEBOY_H
