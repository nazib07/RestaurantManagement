#ifndef TABLESTATUS_H
#define TABLESTATUS_H

#include <QWidget>

namespace Ui {
class TableStatus;
}

class TableStatus : public QWidget
{
    Q_OBJECT

public:
    explicit TableStatus(QWidget *parent = 0);
    ~TableStatus();

    QString getTableName() const;
    void setTableName(const QString &value);

    bool getTableStatus() const;
    void setTableStatus(bool value);

    enum ENUM_TABLE_STATUS
    {
        ON= true,
        OFF = false
    };

private:
    Ui::TableStatus *ui;
    QString tableName;
    bool tableStatus;
};

#endif // TABLESTATUS_H
