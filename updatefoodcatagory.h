#ifndef UPDATEFOODCATAGORY_H
#define UPDATEFOODCATAGORY_H

#include <QWidget>

namespace Ui {
class UpdateFoodCatagory;
}

class UpdateFoodCatagory : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateFoodCatagory(QWidget *parent = 0);
    void setPrevName(QString);
    ~UpdateFoodCatagory();

private:
    Ui::UpdateFoodCatagory *ui;
    QString prev_name;

signals:
    void UpdateCatagoryButtonClicked(QString, QString);
private slots:
    void on_btn_EditCatagory_clicked();
};

#endif // UPDATEFOODCATAGORY_H
