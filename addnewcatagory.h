#ifndef ADDNEWCATAGORY_H
#define ADDNEWCATAGORY_H

#include <QWidget>

namespace Ui {
class AddNewCatagory;
}

class AddNewCatagory : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewCatagory(QWidget *parent = 0);
    ~AddNewCatagory();
    void SetName(QString);

private:
    Ui::AddNewCatagory *ui;
    QImage catagoryImage;

signals:
    void AddCatagoryNewButtonClicked(QString, QImage);

private slots:
    void on_btn_AddCatagory_clicked();
    void on_btn_BrowseImage_clicked();
};

#endif // ADDNEWCATAGORY_H
