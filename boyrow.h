#ifndef BOYROW_H
#define BOYROW_H

#include <QWidget>
#include "boys.h"

namespace Ui {
class BoyRow;
}

class BoyRow : public QWidget
{
    Q_OBJECT

public:
    explicit BoyRow(QWidget *parent = 0);
    ~BoyRow();
    void SetName(QString);
    void SetBoy(Boys*);

private slots:
    void on_btn_ViewBoy_clicked();

    void on_btn_EditBoy_clicked();

    void on_btn_RemoveBoy_clicked();

signals:
    void signal_boyRemoved(QString);
    void signal_boyEdited(Boys*);
    void signal_boyViewed(Boys*);

private:
    Ui::BoyRow *ui;
    Boys *boy;
};

#endif // BOYROW_H
