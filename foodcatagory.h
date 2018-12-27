#ifndef FOODCATAGORY_H
#define FOODCATAGORY_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class FoodCatagory;
}

class FoodCatagory : public QWidget
{
    Q_OBJECT

public:
    explicit FoodCatagory(QWidget *parent = 0);
    ~FoodCatagory();

private:
    Ui::FoodCatagory *ui;
    QString name;

public:
    void SetCatagory(QString);
    void SetImage(QImage);
    void SetName(QString);
    QString GetName();
private slots:
    void on_btn_Remove_clicked();
    void on_btn_Edit_clicked();

signals:
    void signal_foodCataoryRemoved(QString);
    void signal_foodCataoryEdited(QString);
};

#endif // FOODCATAGORY_H
