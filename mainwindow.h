#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QScrollArea>
#include <iostream>
#include <QtSql>
#include <QTableView>
#include "adminwindow.h"
#include "util.h"
#include "catagory.h"
#include "food.h"
#include "order.h"
#include "tempfooditem.h"
#include "formtempfooditem.h"
#include "boys.h"
#include "tables.h"
#include "tablestatus.h"
#include "calculator.h"
#include "adminlogin.h"
#include "userlogin.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGridLayout* layout;
    QPushButton* allButton[100];
    AdminWindow* win;
    Util util;
    QSqlDatabase db;
    QVector<Catagory*> allCatagories;
    QVector<Food*> allCatagorizedFoods;
    QVector<QPushButton*> allCatagoryButtons;
    QVector<FormtempFoodItem*> alltempSelcetedRows;
    QVector<QPushButton*> allFoodButtons;
    QVector<Food*> allTempSelectedFood;
    QVector<Boys*> allBoys;
    QVector<Tables*> allTables;
    QStringList allBoysName;
    QStringList allTablesName;
    int nSlectedCatagory;
    QString selectedBoy;
    QString selectedTable;
    QListWidget *tempFoodList;
    QListWidget *tableStatusList;
    QString new_order_id ;
    QString current_order_id;
    QTableView *currentOrdersTable;
    QTableView *cancelOrdersTable;

    QString currentBoy;
    QString currentTable;
    QString cancel_id;
    bool cancelFlag;
    QLineEdit *discountInput;
    QLineEdit *payInput;
    int nDiscount;
    int nPaidAmount;

    QString total;
    QString change;

    QString operationalUser;


    QVector<TableStatus*> allTableStatus;
    QLineEdit *txtNote;
    QString notedText;

public:
    void resizeEvent(QResizeEvent * event);

    void getAllCatagories(QVector<Catagory*>& cat);
    void getAllCatagorizedFoods(QVector<Food*>& foods, QString catagory);

    void getFoodInfo(QString);
    void getAllBoys();
    void getAllTables();

    QPushButton* createCatagoryButton(Catagory*);
    QPushButton* createFoodButton(Food*);
    void addCatagoryButtonsToWidget(QScrollArea*);
    void addFoodButtonsToWidget(QScrollArea*);
    void insertQuery(Order*);
    void updateCalculationList(QString);
    void populateTempOrders();
    int listContains(QVector<Food*>,Food*);
    void showMessage(QString);
    void populateCurrentOrderFoodList();
    void loadEmptyWidget(QScrollArea*);

    void populateCancelOrderFoodList();

    void resetVariables();
    void ShowPayLabels();
    float getVat();
signals:
    void catagorySelected(QString);
    void foodSelected(QString);

public slots:
    void radioAdd();
    void onCatagoryButtonClicked();
    void onFoodButtonClicked();
    void onCatagorySelected(QString);
    void onFoodSelected(QString);
    void onTempFoodItemClicked(QListWidgetItem*);
    void onTempFoodItemDoubleClicked(QListWidgetItem*);
    void onTableActivated(QString);
    void onBoysActivated(QString);
    void onSelectionChanged ( const QItemSelection & selected, const QItemSelection & deselected );
    void selectionChanged( const QItemSelection & );
    void onTableViewDoubleClicked(QModelIndex);
    void onCancelOrderViewDoubleClicked(QModelIndex);
    void deselectWithoutCatagory(QString);
    bool isFoodAlreadyInsterted(QString);
    void onDiscouReturnPressed();
    void onPayInputReturnPressed();

    void onLoggedInUserTypeRecieved(QString, QString);
    void onNotedTextEntered();

private slots:
    void on_pushButton_21_clicked();
    void on_btn_NewOrder_clicked();

    void on_removeFromTempList_clicked();
    void on_btn_ToKitchen_clicked();
    void on_btn_CurrentOrder_clicked();
    void on_btn_CancelOrder_clicked();
    void on_viewTable_clicked();
    void on_discount_clicked();
    void on_btn_Pay_clicked();

    void on_btn_Calculator_clicked();
    void on_btn_Admin_clicked();
    void onAdminLogoutClicked();
    void on_btn_Exit_clicked();
    void on_btn_Note_clicked();
};

#endif // MAINWINDOW_H
