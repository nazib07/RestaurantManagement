#ifndef UTIL_H
#define UTIL_H

#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include "formtempfooditem.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#define PATH_TO_DB "Restaurent.sql"

class Util
{
public:
    Util();
    QSqlDatabase ConnectDatabase(QString);
     static  QVector<FormtempFoodItem*> alltempChangedRows;
     static void Print(QString, int fontSize = 12);
};

#endif // UTIL_H
