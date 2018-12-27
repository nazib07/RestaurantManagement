#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "addnewcatagory.h"
#include "foodcatagory.h"
#include <QGridLayout>
#include <QListWidget>
#include <QVector>
#include <QDebug>
#include "util.h"
#include "updatefoodcatagory.h"
#include "addnewtable.h"
#include "updatetable.h"
#include "diningtables.h"
#include "addboy.h"
#include "boyrow.h"
#include "updateboy.h"
#include "boyview.h"
#include "foodrow.h"
#include "updatefood.h"
#include "addfood.h"
#include "qcustomplot.h"
#include "userregistrationform.h"
#include "users.h"
#include "userregidata.h"
#include "userview.h"
#include "useredit.h"
#include "userwisetransaction.h"


namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

private slots:
    void on_btn_AddFoodCatagory_clicked();

    void on_btn_AddTable_clicked();

    void on_btn_AddBoy_clicked();

    void on_btn_AddFood_clicked();

    void on_btn_ViewDetailTransaction_clicked();

    void on_btn_AdminLogout_clicked();

    void on_btn_Users_clicked();

    void on_btn_UserWiseTransaction_clicked();

    void on_btn_EditVat_clicked();

    void on_btn_FoodTransaction_clicked();

private:
    Ui::AdminWindow *ui;
    AddNewCatagory* addCatagory;
    static AdminWindow *instance;
    int rowCount;
    QVector<FoodCatagory*> foodCatagories;
    Util util;

    QListWidget *listWidget;
    QListWidget* listCatagory;
    QListWidget* listTable;
    QListWidget* listBoy;
    QListWidget* listFood;
    QTableView *transactionTable;
    QTableView *transactionDetail;
    QDateTime fromDateTime;
    QDateTime toDateTime;

    bool isUserEditBtnClicked;
    bool isUserDeleted;
    QString userSelectedForTransaction;
    QString vat;
    QLineEdit *vatInput;


public:
     void addFoodCatagory(QString catagoryName, QImage imageName);

     static  AdminWindow* getInstance();
     void populateCatagoryList();
     void populateTableList();
     void populateBoyList();
     void populateFoodList();

     void addCustomPlot(QCustomPlot *customPlot);
     void loadEmptyWidget(QScrollArea *);
     float getVat();


public slots:
     void onAddCatagoryNewButtonClicked(QString, QImage);
     void onListFoodCatagoryItemClicked(QListWidgetItem*);
     void onFoodCatagoryRemoved(QString);
     void onFoodCatagoryEdited(QString);
     void onUpdateCatagoryButtonClicked(QString, QString);
     void onAddTableNewButtonClicked(QString);
     void onTableRemoved(QString);
     void onTableEdited(QString);
     void onUpdateTableButtonClicked(QString, QString);
     void onBoyAddedSignalRecieved(Boys*);


     void onBoyRemoved(QString);
     void onBoyEdited(Boys*);
     void onBoyViewed(Boys*);
     void onUpdateBoyButtonClicked(Boys*, Boys*);

     void onFoodRemoved(QString);
     void onFoodEdited(Food*);
     void onUpdateFoodButtonClicked(Food*, Food*);
     void onFoodAddedSignalRecieved(Food*);
     void onTransactionTableDoubleClicked(QModelIndex);
     void onDateTimeFromChanged(QDateTime);
     void onDateTimeToChanged(QDateTime);


     void onUserRemoved(QString);
     void onUserEdited(UserRegiData*);
     void onUserViewed(UserRegiData*);

     void onUserRegiSubmitted(UserRegiData*);
     void onUserEditButtonClicked(UserRegiData*,UserRegiData*);
     void onUserEditFormDestroyed();
     void onUserSelectedForTransactionRecieved(QString);
     void onVatReturnPressed();

signals:
     void signal_AdminLogout();
     void signal_AdminPanelUsersBtnClicked(QVector<UserRegiData*>);
     void signal_AdminPanelUserWiseTransButtonClicked(QVector<QString>);

};

#endif // ADMINWINDOW_H
