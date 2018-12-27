#include "util.h"

Util::Util()
{


}
QVector<FormtempFoodItem*> Util::alltempChangedRows;
QSqlDatabase Util::ConnectDatabase(QString Path_to_DB)
{
   QSqlDatabase  myDB;
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile;
    checkFile.setFile(Path_to_DB);

    if(checkFile.isFile())
    {
        if(myDB.open())
        {
            qDebug()<<"connected to DB File";

        }
    }
    else
    {
         qDebug()<<"Not connected to DB File";
    }


    return myDB;
}

void Util::Print(QString text, int fontSize)
{
    QPrinter printer;
   // printer.setPaperSize(QSizeF(2, 200000), QPrinter::Inch);
   // printer.setPageSizeMM(QSizeF(2, 500));
   // printer.setPrinterName("Posiflex PP6900 Partial Cut v3.01");
    printer.setFullPage(true);

    QPainter painter ;

    painter.begin(&printer);

    QFont font("Courier", fontSize, QFont::Normal);
    painter.setFont(font);
    painter.drawText(20, 0, 800, 99999999, Qt::AlignLeft|Qt::AlignTop, text);
    painter.end();


}
