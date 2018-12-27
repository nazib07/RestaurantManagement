#ifndef DININGTABLES_H
#define DININGTABLES_H

#include <QWidget>

namespace Ui {
class DiningTables;
}

class DiningTables : public QWidget
{
    Q_OBJECT

public:
    explicit DiningTables(QWidget *parent = 0);
    ~DiningTables();
    void SetName(QString);

private:
    Ui::DiningTables *ui;

signals:
    void signal_tableRemoved(QString);
    void signal_tableEdited(QString);
private slots:
    void on_btn_RemoveTable_clicked();
    void on_btn_EditTable_clicked();
};

#endif // DININGTABLES_H
