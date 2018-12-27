#ifndef BOYVIEW_H
#define BOYVIEW_H

#include <QWidget>
#include "boys.h"

namespace Ui {
class boyView;
}

class boyView : public QWidget
{
    Q_OBJECT

public:
    explicit boyView(QWidget *parent = 0);
    ~boyView();
    void setBoy(Boys*);

private:
    Ui::boyView *ui;
};

#endif // BOYVIEW_H
