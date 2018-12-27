#ifndef ADDBOY_H
#define ADDBOY_H

#include <QWidget>
#include "boys.h"

namespace Ui {
class AddBoy;
}

class AddBoy : public QWidget
{
    Q_OBJECT

public:
    explicit AddBoy(QWidget *parent = 0);
    ~AddBoy();

private:
    Ui::AddBoy *ui;

    QImage image;

signals:
    void signal_boyAdded(Boys*);
private slots:
    void on_btn_AddBoy_clicked();
    void on_btn_browseImage_clicked();
};

#endif // ADDBOY_H
