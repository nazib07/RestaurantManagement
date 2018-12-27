#ifndef USERWISETRANSACTION_H
#define USERWISETRANSACTION_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class UserWiseTransaction;
}

class UserWiseTransaction : public QWidget
{
    Q_OBJECT

public:
    explicit UserWiseTransaction(QWidget *parent = 0);
    ~UserWiseTransaction();

private:
    Ui::UserWiseTransaction *ui;
public slots:
    void onChkAllUserStateChanged(int);
    void onSignalAdminPanelUserWiseButtonRecieved(QVector<QString>);
private slots:
    void on_btn_Submit_clicked();
signals:
    void signal_onUserSelectedForTransaction(QString);
};

#endif // USERWISETRANSACTION_H
