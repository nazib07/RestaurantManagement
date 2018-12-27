#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QScrollArea>
#include <QGridLayout>
#include <QMessageBox>
#include <QTableWidget>
#include <QLineEdit>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    selectedBoy(""),
    selectedTable(""),
    current_order_id(""),
    currentBoy(""),
    currentTable(""),
    cancel_id(""),
    cancelFlag(false),
    nDiscount(0),
    nPaidAmount(0),
    total("TOTAL: \t\t\t0"),
    change("CHANGE: \t\t\0"),
    operationalUser(""),
    notedText(""),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = util.ConnectDatabase(PATH_TO_DB);


    getAllCatagories(allCatagories);
    addCatagoryButtonsToWidget(ui->scrollArea_DetailMainWindow_2);

    getAllBoys();
    getAllTables();

    ui->lbl_TotalHeader->setText("");
    win = new AdminWindow();
}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    //qDebug()<<"on Resize";

    //    win->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //    win->setMaximumWidth( ui->scrollArea_DetailMainWindow->geometry().width());
    //    win->setMaximumHeight( ui->scrollArea_DetailMainWindow->geometry().height());

    //    ui->scrollArea_DetailMainWindow->setWidget(win);

}

void MainWindow::getAllCatagories(QVector<Catagory *> &cat)
{

    QSqlQuery sql;
    QSqlRecord record;
    bool result = sql.exec("SELECT * FROM Catagories");

    if(result == true)
    {
        while(sql.next())
        {
            QPixmap* pix = new QPixmap();// this is dummy next time it has to be changed
            Catagory* newCatagory = new Catagory();
            record = sql.record();

            int id = record.value(Catagory::ID).toInt();
            QString name = record.value(Catagory::NAME).toString();
            QString image_path = record.value(Catagory::IMAGE_PATH).toString();
            QString description = record.value(Catagory::DESCRIPTION).toString();

            newCatagory->setId(id);
            newCatagory->setCatagoryName(name);
            newCatagory->setCatagoryImage(*pix);
            newCatagory->setCatagoryDescription(description);

            cat.push_back(newCatagory);

            //         delete newCatagory;


            //qDebug()<<"Name: "<<name;
        }
    }

}

void MainWindow::getAllCatagorizedFoods(QVector<Food *> &foods, QString catagory)
{

    QVector<Food*> empty;
    foods = empty;
    QSqlQuery sql;
    QSqlRecord record;
    // bool result = sql.exec("SELECT UserName, Password FROM Foods WHERE Catagory = \'" + catagory +"\'");
    bool result = sql.exec("SELECT * FROM Foods WHERE Catagory = \'" + catagory + "\'");

    if(result == true)
    {
        while(sql.next())
        {
            QPixmap* pix = new QPixmap();// this is dummy next time it has to be changed
            Food* newFood = new Food();
            record = sql.record();

            int id = record.value(Food::ID).toInt();
            QString name = record.value(Food::NAME).toString();
            QString image_path = record.value(Food::IMAGE_PATH).toString();
            QString description = record.value(Food::DESCRIPTION).toString();
            float price = record.value(Food::PRICE).toFloat();

            newFood->setId(id);
            newFood->setName(name);
            newFood->setPrice(price);
            newFood->setImage(*pix);
            newFood->setCatagroy(catagory);
            newFood->setDescription(description);

            foods.push_back(newFood);

            //         delete newCatagory;


            qDebug()<<"Name: "<<name;
        }
    }

}

void MainWindow::getFoodInfo(QString food)
{
   // qDebug()<<"Food Selected: "<<food;
}

void MainWindow::getAllBoys()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * FROM Boys");
    bool result = query->exec();

    if(result == true){
        while(query->next())
        {
            QString name = query->record().value("name").toString();
            allBoysName.append(name);
        }
    }


    ui->boysComboBox->addItems(allBoysName);
    connect(ui->boysComboBox, SIGNAL(activated(QString)), this, SLOT(onBoysActivated(QString)));
    delete query;



}

void MainWindow::getAllTables()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * FROM DiningTables");
    bool result = query->exec();

    if(result == true){
        while(query->next())
        {
            QString name = query->record().value("name").toString();
            allTablesName.append(name);
        }
    }
    ui->combo_tables->addItems(allTablesName);
    connect(ui->combo_tables, SIGNAL(activated(QString)), this, SLOT(onTableActivated(QString)));
    delete query;
}

QPushButton *MainWindow::createCatagoryButton(Catagory *cat)
{
    QPushButton *button = new QPushButton(cat->getCatagoryName());

    return button;
}

QPushButton *MainWindow::createFoodButton(Food *food)
{    QPushButton *button = new QPushButton(food->getName());

     return button;
}

void MainWindow::addCatagoryButtonsToWidget(QScrollArea *widget)
{
    QGridLayout* layout = new QGridLayout();
    QWidget* w = new QWidget();


    int row = 0;
    int colum = 0;
    for(int i = 0; i < allCatagories.size(); i++)
    {

        Catagory* tempCatagory = new Catagory();
        tempCatagory = allCatagories.at(i);
        nSlectedCatagory = i;

        QPushButton *button = createCatagoryButton(tempCatagory);
        // button->setMinimumWidth(100);

        button->setCheckable(true);
        button->setMaximumSize(100,100);
        button->setSizePolicy(QSizePolicy ::Preferred, QSizePolicy::Preferred);
        allCatagoryButtons.push_back(button);

        connect(allCatagoryButtons.at(i), SIGNAL(clicked()), this, SLOT(onCatagoryButtonClicked()));
        layout->addWidget(button,row,colum);

        colum++;
        colum %= 3;

        if(colum == 0)
        {
            row++;
        }

        qDebug()<<"row: "<<row <<"colum: "<< colum;
    }

    w->setLayout(layout);
    widget->setWidget(w);


}

void MainWindow::addFoodButtonsToWidget(QScrollArea *widget)
{
    QVector<QPushButton*> empty;
    allFoodButtons = empty;
    QGridLayout* layout = new QGridLayout();
    QWidget* w = new QWidget();


    int row = 0;
    int colum = 0;
    for(int i = 0; i < allCatagorizedFoods.size(); i++)
    {

        Food* tempFood = new Food();
        tempFood = allCatagorizedFoods.at(i);


        QPushButton *button = createFoodButton(tempFood);


        button->setCheckable(true);
        button->setMaximumSize(100,100);
        button->setSizePolicy(QSizePolicy ::Preferred, QSizePolicy::Preferred);
        allFoodButtons.push_back(button);


        connect(allFoodButtons.at(i), SIGNAL(clicked()), this, SLOT(onFoodButtonClicked()));
        layout->addWidget(button,row,colum);

        colum++;
        colum %= 3;

        if(colum == 0)
        {
            row++;
        }

        qDebug()<<"row: "<<row <<"colum: "<< colum;
    }

    w->setLayout(layout);
    widget->setWidget(w);


}




void MainWindow::radioAdd() {
    QRadioButton * radio = new QRadioButton("Search from the &cursor", this);
    layout->addWidget(radio);
}

void MainWindow::onCatagoryButtonClicked()
{
    QPushButton *button = (QPushButton *)sender();

    connect(this, SIGNAL(catagorySelected(QString)), this, SLOT(onCatagorySelected(QString)),Qt::UniqueConnection);
    emit catagorySelected(button->text());

}

void MainWindow::onFoodButtonClicked()
{    QPushButton *button = (QPushButton *)sender();

     connect(this, SIGNAL(foodSelected(QString)), this, SLOT(onFoodSelected(QString)),Qt::UniqueConnection);
      emit foodSelected(button->text());

}


void MainWindow::onCatagorySelected(QString catagory)
{

    qDebug()<<catagory;
    deselectWithoutCatagory(catagory);
    getAllCatagorizedFoods(allCatagorizedFoods,catagory);
    addFoodButtonsToWidget(ui->scrollArea_DetailMainWindow);

}

void MainWindow::onFoodSelected(QString food)
{

    qDebug()<<food;
    getFoodInfo(food);
}

void MainWindow::onTempFoodItemClicked(QListWidgetItem *item)
{

    qDebug()<<"onTempFoodItemClicked";
}

void MainWindow::onTempFoodItemDoubleClicked(QListWidgetItem *item)
{
    qDebug()<<"Item index"<<item->text()<<alltempSelcetedRows.size();

    qDebug()<<"Before entering the util"<<item->text().toInt();
    alltempSelcetedRows.at(item->text().toInt())->setCheckBoxChecked();

    QString foodName = alltempSelcetedRows.at(item->text().toInt())->getMyFood()->getName();
    int foodQuantity = alltempSelcetedRows.at(item->text().toInt())->getQuantity();
    qDebug()<<"Food: "<<foodName<<"Quantity: "<<foodQuantity;

    if(cancelFlag == true)
    {

        qDebug()<<"cancel id"<<cancel_id;
        QSqlQuery query1;
        query1.prepare("DELETE FROM TempTransactionDetails WHERE transaction_id = :tr_id AND food=:food AND quantity= :quant");
        query1.bindValue(":tr_id", cancel_id);
        query1.bindValue(":food", foodName);
        query1.bindValue(":quant", foodQuantity);
        bool r1 = query1.exec();
        qDebug()<<"row From TempTransactionDetails Deleted: "<<r1;

        QSqlQuery query;
        query.prepare("SELECT * FROM TempTransactionDetails WHERE transaction_id = :current_order_id");
        query.bindValue(":current_order_id", cancel_id);
        bool r = query.exec();

        qDebug()<<((r == true)?"query success": "query false");

        if(r == true)
        {
            while(query.next())
            {
                Food *tempFood = new Food();
                tempFood->setName(query.record().value("food").toString());
                tempFood->setQuantity(query.record().value("quantity").toInt());
                tempFood->setPrice(query.record().value("price").toFloat());

                allTempSelectedFood.push_back(tempFood);
            }

        }


        while(tempFoodList->count()>0)
        {
            tempFoodList->takeItem(0);
        }
        QVector<FormtempFoodItem*> empty;
        alltempSelcetedRows = empty;

        for(int i = 0 ; i < allTempSelectedFood.size() ; i++){
            QListWidgetItem* item = new QListWidgetItem();
            item->setSizeHint(QSize(0,60));
            QWidget *widget = new QWidget();
            QVBoxLayout *layout = new QVBoxLayout();

            FormtempFoodItem* form = new FormtempFoodItem();
            tempFoodItem* tempfood = new tempFoodItem();
            tempfood->setFood(*allTempSelectedFood.at(i));
            tempfood->setQuantity(allTempSelectedFood.at(i)->getQuantity());
            form->setName(tempfood->getFood().getName());
            form->setPrice(QString::number(tempfood->getFood().getPrice()));
            form->setQuantity( QString::number( tempfood->getQuantity()) );
            layout->addWidget(form);
            widget->setLayout(layout);

            item->setText(QString::number(i));

            tempFoodList->addItem(item);
            tempFoodList->setItemWidget(item,widget);
            form->setMyItem(item);
            form->setMyFood(allTempSelectedFood.at(i));
            form->calcSubTotal();

            alltempSelcetedRows.push_back(form);
        }
        ui->scrollAreaCalcList->setWidget(tempFoodList);

        if(alltempSelcetedRows.size() <= 0)
        {
            QSqlQuery query;
            query.prepare("DELETE FROM TempTransaction WHERE id = :t_id");
            query.bindValue(":t_id", cancel_id);
            bool r = query.exec();
            qDebug()<<"row From TempTransaction Deleted: "<<r;

            QSqlQuery query1;
            query1.prepare("DELETE FROM TempTransactionDetails WHERE transaction_id = :tr_id");
            query1.bindValue(":tr_id", cancel_id);
            bool r1 = query1.exec();
            qDebug()<<"row From TempTransaction Deleted: "<<r1;

            //
            QSqlQueryModel* model = new QSqlQueryModel();
            QSqlQuery qry;
            qry.prepare("SELECT * FROM TempTransaction");
            r = qry.exec();
            qDebug()<<((r == true)?"Success":"Not selected");
            model->setQuery(qry);
            cancelOrdersTable->setModel(model);
            cancelOrdersTable->resizeColumnsToContents();
            cancelOrdersTable->horizontalHeader()->setStretchLastSection(true);
            ui->scrollArea_DetailMainWindow->setWidget(cancelOrdersTable);

        }

        QVector<Food*> emptyFood;
        allTempSelectedFood = emptyFood;

    }
}

void MainWindow::onTableActivated(QString item)
{
    qDebug()<<"onComboTablesCurrentIndexChanged"<<item;
    selectedTable = item;
}

void MainWindow::onBoysActivated(QString item)
{
    qDebug()<<"onComboTablesCurrentIndexChanged"<<item;
    selectedBoy = item;
}

void MainWindow::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    qDebug()<<"On Selection Changed"<<selected.indexes().at(0).column();


}

void MainWindow::selectionChanged(const QItemSelection &)
{

}

void MainWindow::onTableViewDoubleClicked(QModelIndex index)
{
    qDebug()<<"onTableViewDoubleClicked";
    loadEmptyWidget(ui->scrollAreaCalcList);
    current_order_id = currentOrdersTable->model()->data(index).toString();

    //    QVector<Catagory*> emptycat;
    //    allCatagories = emptycat;
    //    getAllCatagories(allCatagories);
    //    addCatagoryButtonsToWidget(ui->scrollArea_DetailMainWindow_2);

    QSqlQuery query;
    query.prepare("SELECT * FROM TempTransaction WHERE id = :t_id");
    query.bindValue(":t_id", current_order_id);
    bool r = query.exec();
    qDebug()<<"get boy and table of current order: "<<r;

    if(r == true)
    {
        while(query.next())
        {
            currentBoy = query.record().value("boy").toString();
            currentTable = query.record().value("dining").toString();
        }
    }

    if(currentBoy != "" && currentTable != "")
    {
        //hide ui
        ui->boysComboBox->setCurrentText(currentBoy);
        ui->boysComboBox->setEnabled(false);
        ui->combo_tables->setCurrentText(currentTable);
        ui->combo_tables->setEnabled(false);
    }

    qDebug()<<current_order_id;
    //
    QSqlQuery query1;
    QString a = "";
    a.append("TOTAL: ");
    query1.prepare("SELECT SUM(subtotal) AS sumTotal FROM TempTransactionDetails WHERE transaction_id=:t_id");
    query1.bindValue(":t_id", current_order_id);
    r = query1.exec();
    if(r == true)
    {
        while(query1.next())
        {
            a.append(query1.record().value("sumTotal").toString());
        }
    }
    //
    qDebug()<<a;
    a.append(" Tk.");

    ui->lbl_TotalHeader->setText(a);
    populateCurrentOrderFoodList();

    //index.row();

}

void MainWindow::onCancelOrderViewDoubleClicked(QModelIndex index)
{
    if(index.column() >0) return;
    qDebug()<<"onCancelOrderViewDoubleClicked";
    loadEmptyWidget(ui->scrollAreaCalcList);
    //  loadEmptyWidget(ui->scrollArea_DetailMainWindow);
    cancel_id = cancelOrdersTable->model()->data(index).toString();


    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Do you want to Cancel Total Order?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM TempTransaction WHERE id = :t_id");
        query.bindValue(":t_id", cancel_id);
        bool r = query.exec();
        qDebug()<<"row From TempTransaction Deleted: "<<r;

        QSqlQuery query1;
        query1.prepare("DELETE FROM TempTransactionDetails WHERE transaction_id = :tr_id");
        query1.bindValue(":tr_id", cancel_id);
        bool r1 = query1.exec();
        qDebug()<<"row From TempTransaction Deleted: "<<r1;

        //
        QSqlQueryModel* model = new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM TempTransaction");
        r = qry.exec();
        qDebug()<<((r == true)?"Success":"Not selected");
        model->setQuery(qry);
        cancelOrdersTable->setModel(model);
        cancelOrdersTable->resizeColumnsToContents();
        cancelOrdersTable->horizontalHeader()->setStretchLastSection(true);
        ui->scrollArea_DetailMainWindow->setWidget(cancelOrdersTable);
        //
    }else {

        populateCancelOrderFoodList();
        cancelFlag = true;

        // do something else
    }



}

void MainWindow::deselectWithoutCatagory(QString catagory)
{

    for(int i = 0; i<allCatagoryButtons.size(); i++)
    {
        if(allCatagoryButtons[i]->text() != catagory)
        {
            allCatagoryButtons[i]->setChecked(false);
        }

    }
}

bool MainWindow::isFoodAlreadyInsterted(QString food)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM TempTransactionDetails WHERE transaction_id = :t_id AND food = :food");
    query.bindValue(":t_id", new_order_id);
    query.bindValue(":food", food);
    bool r = query.exec();

    if(r == true)
    {
        if(query.next()) {return true;}
    }

    return false;
}

void MainWindow::onDiscouReturnPressed()
{
    qDebug()<<"onDiscouReturnPressed";
    nDiscount = discountInput->text().toInt();
    discountInput->close();
}

void MainWindow::ShowPayLabels()
{
    ui->lbl_discount->setText("DISCOUNT: \t\t"+ QString::number(nDiscount));
    ui->lbl_change->setText("CHANGE: \t\t"+change);
    ui->lbl_total->setText("TOTAL: \t\t\t"+total);
    ui->lbl_paid->setText("PAID: \t\t\t"+QString::number(nPaidAmount));
}

float MainWindow::getVat()
{
    QSqlQuery q;
    float vat = 0.0;
    q.prepare("SELECT * FROM vat");
    bool r= q.exec();
    if(r)
    {
        qDebug()<<"vat get Success";
        while(q.next())
        {
            vat = q.record().value("vat").toFloat();
        }
    }
    else
    {
        qDebug()<<"vat get failed";
    }

    return vat;
}

void MainWindow::onPayInputReturnPressed()
{
    ui->lbl_TotalHeader->setText("");
    qDebug()<<"onPayInputReturnPressed";

    QString ToPayPrint = "";

    ToPayPrint.append("**************************\n"
                      "**************************\n"
                      "******** ALFRESCO ********\n"
                      "**************************\n"
                      "**************************\n\n\n");
    ToPayPrint.append("ID: ");


    nPaidAmount = payInput->text().toInt();
    payInput->close();

    QSqlQuery query;
    query.prepare("SELECT SUM(subtotal) AS sumTotal FROM TempTransactionDetails WHERE transaction_id=:t_id");
    query.bindValue(":t_id", new_order_id);
    bool r = query.exec();
    if(r == true)
    {
        while(query.next())
        {
            total = query.record().value("sumTotal").toString();
        }
    }

    float fDisCountedAmount = (nDiscount*total.toDouble())/100;
    qDebug()<<"Discounted Amount: "<<fDisCountedAmount;
    float  fVatedAmount = (total.toDouble()*getVat())/100;
    qDebug()<<"Vated Amount: "<<fVatedAmount;

    change =  QString::number(nPaidAmount - total.toDouble()  + fDisCountedAmount - fVatedAmount);


    //=================

    QString food;
    int quantity;
    float price;
    QString diningTable;
    QString boy;
    int discount;
    QString transactionID;
    float subTotal;
    QString dateTime;

    discount = nDiscount;

    dateTime = QString::number(QDateTime::currentDateTime().toTime_t());


    //get data from TempTransaction Table
    QSqlQuery aa;
    aa.prepare("SELECT * FROM TempTransaction WHERE id = :t_id");
    aa.bindValue(":t_id",new_order_id);
    bool rr = aa.exec();

    if(rr)
    {

        while(aa.next())
        {
            qDebug()<<"TempTransactions select Successfull"<<aa.numRowsAffected();
            diningTable = aa.record().value("dining").toString();
            boy = aa.record().value("boy").toString();
            transactionID = aa.record().value("id").toString();

            QSqlQuery qr;
            qr.prepare("INSERT INTO Transactions(id, boy, dining, discount, vat, period, user, comments) VALUES(:id, :boy, :din, :dis, :vat, :date, :usr, :comments)");
            qr.bindValue(":id" , transactionID);
            qr.bindValue(":boy" , boy);
            qr.bindValue(":din" , diningTable);
            qr.bindValue(":dis" , discount);
            qr.bindValue(":date" , dateTime);
            qr.bindValue(":vat", getVat());
            qr.bindValue(":usr", operationalUser);
            qr.bindValue(":comments", notedText);
            bool  res = qr.exec();
            if(res)
            {
                qDebug()<<"Inserting in transection Sucessful";

            }else
            {
                qDebug()<<"Inserting in transection failed"<<qr.lastError();
            }
        }
        ToPayPrint.append(transactionID+"\n");
        ToPayPrint.append("Table: "+diningTable+"\n");
        ToPayPrint.append("+++++++++++++++++++++++++++\n");
        ToPayPrint.append("Items  Qty  Price  SubTotal\n");
        ToPayPrint.append("-----  ---  -----  --------\n\n\n");

    }
    else
    {
        qDebug()<<"TempTransactions select Failed"<< new_order_id;
    }

    //get data from TempTransactionDetails table
    QSqlQuery query1;
    query1.prepare("SELECT * FROM TempTransactionDetails WHERE transaction_id =:t_id");
    query1.bindValue(":t_id", new_order_id);
    bool res = query1.exec();
    if(res == true)
    {

        qDebug()<<"selecct from TempTransactionDetails Successful";
        while(query1.next())
        {
            food = query1.record().value("food").toString();
            quantity = query1.record().value("quantity").toInt();
            price = query1.record().value("price").toFloat();
            transactionID = query1.record().value("transaction_id").toString();
            subTotal = query1.record().value("subtotal").toFloat();

            QSqlQuery qr ;
            qr.prepare("INSERT INTO TransactionsDetails(Food,Quantity,Price,TransactionID,SubTotal) VALUES(:food, :qun , :price, :id , :subtotal)");
            qr.bindValue(":food", food);
            qr.bindValue(":qun",quantity);
            qr.bindValue(":price",price);
            qr.bindValue(":subtotal",subTotal);
            qr.bindValue(":id",transactionID);
            bool res = qr.exec();
            if(res){

                ToPayPrint.append(food + "\n");
                ToPayPrint.append("            "+QString::number(quantity));
                ToPayPrint.append("  "+ QString::number(price));
                ToPayPrint.append("  "+ QString::number(subTotal) +"\n");


                qDebug()<<"Inserting in TransactionsDetails Successful"<<transactionID;
            }
            else{
                qDebug()<<"Inserting in TransactionsDetails failed"<<food<<quantity;
            }


        }

        ToPayPrint.append("        -----------------\n");
        ToPayPrint.append("        Total:    "+total+"\n");
        ToPayPrint.append("        Discount: "+QString::number(nDiscount)+"\n");
        ToPayPrint.append("        Vat     : "+QString::number(((total.toFloat()* getVat())/100))+"\n");
        ToPayPrint.append("        ==================\n");
        ToPayPrint.append("      Grand Total:"+QString::number(total.toFloat() - ((nDiscount*total.toFloat())/100) + ((total.toFloat()* getVat())/100))+"\n");
        ToPayPrint.append("        Paid:     "+ QString::number(nPaidAmount)+"\n");
        ToPayPrint.append("        Change:   "+ change+"\n");
        ToPayPrint.append(QDateTime::currentDateTime().toString() + "\n\n");
        ToPayPrint.append("++++++++++++++++++++++++++\n");
        ToPayPrint.append("+       Thank you        +\n");
        ToPayPrint.append("++++++++++++++++++++++++++\n\n\n");
        ToPayPrint.append("soft. developed by ABMNGK Co.\n\n");
    }
    else
    {
        qDebug()<<"selecct from TempTransactionDetails Failed";
    }
    //
    QSqlQuery nq;
    nq.prepare("DELETE FROM TempTransaction WHERE id =:tid");
    nq.bindValue(":tid", transactionID);
    bool res1 = nq.exec();
    if(res1)
    {
        qDebug()<<"Deleted from TempTransaction Sucessful"<<nq.lastQuery();
    }
    else
    {
        qDebug()<<"Deleted from TempTransaction Failed";
    }
    //

    QSqlQuery nq1;
    nq1.prepare("DELETE FROM TempTransactionDetails WHERE transaction_id =:tid");
    nq1.bindValue(":tid", transactionID);
    res = nq1.exec();

    if(res == true)
    {
        qDebug()<<"Deleted From TransactionDetails Successfull"<< transactionID;
    }
    else
    {
        qDebug()<<"Deleted From TransactionsDetails Failed"<<nq1.lastError()<<transactionID;
    }
    //
    Util::Print(ToPayPrint);
    on_btn_CurrentOrder_clicked();
    ShowPayLabels();
}

void MainWindow::onLoggedInUserTypeRecieved(QString userType, QString user)
{
    if(userType == "Admin")
    {
        ui->btn_Admin->setEnabled(true);

    }
    else
    {
        ui->btn_Admin->setEnabled(false);
    }

    ui->btn_Exit->setText("Logged In As "+user+"\n(Logout)");

    operationalUser = user;
}

void MainWindow::onNotedTextEntered()
{
    notedText = txtNote->text();
    txtNote->close();
}

void MainWindow::on_pushButton_21_clicked()
{
    QVector<FormtempFoodItem*> empty;
    Util::alltempChangedRows = empty;

    if(allFoodButtons.size() <= 0) return;
    for(int i=0; i<allFoodButtons.size(); i++)
    {
        if(allFoodButtons[i]->isChecked())
        {
            int contains =listContains(allTempSelectedFood,allCatagorizedFoods.at(i));
            if(contains < 0){
                qDebug()<<"Selected foods:"<<allCatagorizedFoods.at(i)->getName();
                allTempSelectedFood.push_back(allCatagorizedFoods.at(i));
                qDebug()<<"Debug"<<allCatagorizedFoods.at(i)->getName()<<allCatagorizedFoods.at(i)->getCatagroy();
            }else{

                allTempSelectedFood.at(contains)->addQuantity(1);
            }

            allFoodButtons[i]->setChecked(false);
        }
    }

    populateTempOrders();


}



void MainWindow::insertQuery(Order* order)
{
    QSqlQuery sql;
    QString item = order->getItem();
    int amount = order->getAmount();
    QString order_id = order->getOrder_id();

    int prevAmount = 0;
    bool res;
    {
        QSqlQuery chkdup;
        chkdup.prepare("SELECT * FROM TempTransaction WHERE order_id = :order AND item = :item");
        chkdup.bindValue(":order", order_id);
        chkdup.bindValue(":item", item);
        res = chkdup.exec();

        if(res)
        {
            while(chkdup.next())
            {
                prevAmount = chkdup.record().value("amount").toInt();
            }
        }

    }

    if(prevAmount<=0)
    {
        sql.prepare("INSERT INTO TempTransaction(item, amount, order_id) VALUES(:item,:amount,:order_id)");
        sql.bindValue(":item", item);
        sql.bindValue(":amount", amount);
        sql.bindValue(":order_id", order_id);
    }

    else
    {
        int newAmount = amount+prevAmount;
        sql.prepare("UPDATE TempTransaction SET amount = :newAmount WHERE order_id = :order_id AND item = :item");
        sql.bindValue(":order_id", order_id);
        sql.bindValue(":item", item);
        sql.bindValue(":newAmount",newAmount);

    }
    bool result = sql.exec();

    if(result == true)
    {

        qDebug()<<"data inserted successfully";
        updateCalculationList(order_id);
    }


}

void MainWindow::updateCalculationList(QString order)
{

    //    QListWidget listWidget;
    //    QSqlQuery query;

    //    QString item;
    //    int qty;
    //    float rate;
    //    float cost;

    //    QWidget *widget = new QWidget();
    //    QVBoxLayout *layout = new QVBoxLayout();



    //    query.prepare("SELECT * FROM TempTransaction WHERE order_id = :order");
    //    query.bindValue(":order", order);

    //    int result = query.exec();
    //    if(result == true)
    //    {

    //        while(query.next())
    //        {
    //            QLabel *label = new QLabel();
    //            item = query.record().value("item").toString();

    //            {
    //                QSqlQuery query2;

    //                query2.prepare("SELECT * FROM Foods WHERE Name = :item");
    //                query2.bindValue(":item", item);
    //                int r = query2.exec();
    //                if(r == true)
    //                {
    //                    while(query2.next())
    //                    {
    //                        rate = query2.record().value("Price").toFloat();
    //                        qDebug()<<"rate: "<<rate;
    //                    }
    //                }


    //            }


    //            qty = query.record().value("amount").toInt();
    //            cost = qty*rate;

    //             qDebug()<<"cost: "<<cost;

    //            //label->setText("Hello....");
    //            label->setText(item + "\t" + QString::number(qty) + "\t" + QString::number(rate) + "\t" + QString::number(cost));

    //            layout->addWidget(label);

    //        }


    //        widget->setLayout(layout);

    //        ui->scrollAreaCalcList->setWidget(widget);

    //    }

    //    else
    //    {
    //        return;

    //    }

}

void MainWindow::populateTempOrders()
{
    QVector<FormtempFoodItem*> empty;
    alltempSelcetedRows = empty;

    tempFoodList = new QListWidget();
    tempFoodList->setSelectionMode(QAbstractItemView::MultiSelection);
    tempFoodList->setSelectionBehavior(QAbstractItemView::SelectItems);

    //connect(tempFoodList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onTempFoodItemClicked(QListWidgetItem*)));

    connect(tempFoodList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTempFoodItemDoubleClicked(QListWidgetItem*)), Qt::UniqueConnection);
    for(int i = 0 ; i < allTempSelectedFood.size() ; i++){
        QListWidgetItem* item = new QListWidgetItem();
        item->setSizeHint(QSize(0,60));
        QWidget *widget = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        FormtempFoodItem* form = new FormtempFoodItem();
        tempFoodItem* tempfood = new tempFoodItem();
        tempfood->setFood(*allTempSelectedFood.at(i));
        tempfood->setQuantity(allTempSelectedFood.at(i)->getQuantity());
        form->setName(tempfood->getFood().getName());
        form->setPrice(QString::number(tempfood->getFood().getPrice()));
        form->setQuantity( QString::number( tempfood->getQuantity()) );
        layout->addWidget(form);
        widget->setLayout(layout);

        item->setText(QString::number(i));

        tempFoodList->addItem(item);
        tempFoodList->setItemWidget(item,widget);
        form->setMyItem(item);
        form->setMyFood(allTempSelectedFood.at(i));
        form->calcSubTotal();

        alltempSelcetedRows.push_back(form);
    }
    //    QVector<Food*> empty;
    //    allTempSelectedFood = empty;
    ui->scrollAreaCalcList->setWidget(tempFoodList);
}

int MainWindow::listContains(QVector<Food *> source, Food * target)
{
    for(int i = 0 ; i < source.size() ; i++){
        if(*source.at(i) == *target){
            return i;
        }
    }
    return -1;
}

void MainWindow::on_btn_NewOrder_clicked()
{
    ui->lbl_TotalHeader->setText("");
    resetVariables();
    loadEmptyWidget(ui->scrollArea_DetailMainWindow);
    loadEmptyWidget(ui->scrollAreaCalcList);


    QString currentTime = QTime::currentTime().toString();
    new_order_id = QString(QCryptographicHash::hash(currentTime.toLatin1(),QCryptographicHash::Md5).toHex());


    ui->boysComboBox->setEnabled(true);
    ui->combo_tables->setEnabled(true);

    qDebug()<<"new order id"<<new_order_id;
}

void MainWindow::on_removeFromTempList_clicked()
{

    QVector<int> tempInt;
    QVector<int> tempAllTempSelectedFood;
    QVector<int> tempAlltempChangedRows;
    for(int i=0; i<Util::alltempChangedRows.size();i++)
    {

        qDebug()<<Util::alltempChangedRows.at(i)->getMyFood()->getName()<<"Quantity: "<<Util::alltempChangedRows.at(i)->getMyFood()->getQuantity() << Util::alltempChangedRows.at(i)->getChangedQuantity();

        int changeInQuantity = Util::alltempChangedRows.at(i)->getMyFood()->getQuantity() - Util::alltempChangedRows.at(i)->getChangedQuantity();
        if(changeInQuantity <= 0){
            for(int j = i ; j< Util::alltempChangedRows.size() ; j++){

                for(int yo = 0 ; yo < allTempSelectedFood.size() ; yo++){
                    qDebug()<<" yo yo Mama "<<Util::alltempChangedRows.at(j)->getMyFood()->getName()<<allTempSelectedFood.at(yo)->getName();
                    if(Util::alltempChangedRows.at(j)->getMyFood() == allTempSelectedFood.at(yo)){
                        qDebug()<<"Removed yo yo ";
                        tempAllTempSelectedFood.push_back(yo);
                        // allTempSelectedFood.remove(yo);
                        qDebug()<<Util::alltempChangedRows.at(j)->getMyFood()->getName();
                        // tempFoodList->removeItemWidget(Util::alltempChangedRows.at(i)->getMyItem());
                        // Util::alltempChangedRows.at(i)->getMyItem()->setText("");
                        tempFoodList->takeItem(Util::alltempChangedRows.at(j)->getMyItem()->text().toInt());
                        tempInt.push_back(Util::alltempChangedRows.at(j)->getMyItem()->text().toInt());
                        // Util::alltempChangedRows.remove(j);
                        tempAlltempChangedRows.push_back(j);
                    }
                }
            }
            for(int i = tempAlltempChangedRows.size()-1 ; i >= 0; i--){\
                qDebug()<<" " <<tempAlltempChangedRows.at(i);
                Util::alltempChangedRows.at(tempAlltempChangedRows.at(i))->getMyItem()->setText("");
                tempFoodList->removeItemWidget(Util::alltempChangedRows.at(tempAlltempChangedRows.at(i))->getMyItem());
                //tempFoodList->takeItem(Util::alltempChangedRows.at(tempAlltempChangedRows.at(i))->getMyItem()->text().toInt());
                Util::alltempChangedRows.remove(tempAlltempChangedRows.at(i));

            }
            for(int i = tempAllTempSelectedFood.size()-1 ; i >= 0   ; i--){\
                qDebug()<<""<<tempAllTempSelectedFood.at(i);

                allTempSelectedFood.remove(tempAllTempSelectedFood.at(i));

            }
            /*   qDebug()<<Util::alltempChangedRows.at(i)->getMyFood()->getName();
            tempFoodList->takeItem(Util::alltempChangedRows.at(i)->getMyItem()->text().toInt());
            Util::alltempChangedRows.remove(i);
          */
            // tempFoodList->removeItemWidget(Util::alltempChangedRows.at(i)->getMyItem());
        }else{
            qDebug()<<"New Quantity:"<<changeInQuantity<<"  Previous Quantity:"<< Util::alltempChangedRows.at(i)->getMyFood()->getQuantity();

            Util::alltempChangedRows.at(i)->setQuantity( QString::number(changeInQuantity) );
            Util::alltempChangedRows.at(i)->getMyFood()->setQuantity(changeInQuantity);
            Util::alltempChangedRows.at(i)->calcSubTotal();
            //Util::alltempChangedRows.remove(i);
        }

    }
    /* for(int i = tempInt.size()-1 ; i >=0   ; i--){\
        qDebug()<<tempInt.at(i)<<tempFoodList->count();
        tempFoodList->removeItemWidget(Util::alltempChangedRows.at(tempInt.at(i))->getMyItem());

    }*/

    //        QVector<FormtempFoodItem*> empty;
    //        Util::alltempChangedRows = empty;


}

void MainWindow::showMessage(QString message)
{
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}

void MainWindow::populateCurrentOrderFoodList()
{
    if(current_order_id == ""){showMessage("Double Click on id to get it's order list"); return;}
    QSqlQuery query;
    query.prepare("SELECT * FROM TempTransactionDetails WHERE transaction_id = :current_order_id");
    query.bindValue(":current_order_id", current_order_id);
    bool r = query.exec();

    qDebug()<<((r == true)?"query success": "query false");

    if(r == true)
    {
        while(query.next())
        {
            Food *tempFood = new Food();
            tempFood->setName(query.record().value("food").toString());
            tempFood->setQuantity(query.record().value("quantity").toInt());
            tempFood->setPrice(query.record().value("price").toFloat());

            allTempSelectedFood.push_back(tempFood);
        }

    }
    populateTempOrders();
    QVector<Food*> empty;
    allTempSelectedFood = empty;
    new_order_id = current_order_id;
    current_order_id = "";

}

void MainWindow::loadEmptyWidget(QScrollArea *area)
{
    QWidget* widget = new QWidget();
    area->setWidget(widget);

}

void MainWindow::populateCancelOrderFoodList()
{


    if(cancel_id == ""){showMessage("Double Click on id to get it's order list"); return;}
    QSqlQuery query;
    query.prepare("SELECT * FROM TempTransactionDetails WHERE transaction_id = :current_order_id");
    query.bindValue(":current_order_id", cancel_id);
    bool r = query.exec();

    qDebug()<<((r == true)?"query success": "query false");

    if(r == true)
    {
        while(query.next())
        {
            Food *tempFood = new Food();
            tempFood->setName(query.record().value("food").toString());
            tempFood->setQuantity(query.record().value("quantity").toInt());
            tempFood->setPrice(query.record().value("price").toFloat());

            allTempSelectedFood.push_back(tempFood);
        }

    }
    populateTempOrders();
    QVector<Food*> empty;
    allTempSelectedFood = empty;
    new_order_id = cancel_id;


}

void MainWindow::on_btn_ToKitchen_clicked()
{
    QString printToKitchen = "";
    printToKitchen.append("**************************\n"
                          "        To Kitchen.\n"
                          "**************************\n\n");
    printToKitchen.append("ORDER ID: "+new_order_id+"\n\n");


    if(currentBoy != "" && currentTable != "")
    {
        selectedBoy = currentBoy;
        selectedTable = currentTable;
    }

    printToKitchen.append("TABLE: "+selectedTable+"\n\n");
    printToKitchen.append("BOY: "+selectedBoy+"\n\n");

    if(new_order_id == ""){showMessage("Click New order or Select from Current Orders"); return;}
    if(selectedBoy == ""){showMessage("Boy Not Selected"); return;}
    if(selectedTable == ""){showMessage("Table Not Selected"); return;}
    if(allTempSelectedFood.size() == 0){showMessage("List Empty, No Food Selected"); return;}

    QString name;
    int quantity;
    float price;
    float subTotal;
    QString table = selectedTable;
    QString boy = selectedBoy;


    QSqlQuery query;
    query.prepare("INSERT INTO TempTransaction(id, boy, dining) VALUES(:id, :boy, :dining)");

    query.bindValue(":id", new_order_id);
    query.bindValue(":boy",boy);
    query.bindValue(":dining",table);
    bool flag =   query.exec();
    qDebug()<<flag;

    for(int i = 0; i<allTempSelectedFood.size(); i++)
    {
        //  qDebug()<<allTempSelectedFood.at(i)->getName()<<allTempSelectedFood.at(i)->getPrice()<<allTempSelectedFood.at(i)->getQuantity();
        name = allTempSelectedFood.at(i)->getName();
        price = allTempSelectedFood.at(i)->getPrice();
        quantity = allTempSelectedFood.at(i)->getQuantity();
        subTotal = price*quantity;

        printToKitchen.append(allTempSelectedFood.at(i)->getName());
        printToKitchen.append("\t\t\t");
        printToKitchen.append(QString::number(allTempSelectedFood.at(i)->getQuantity())+"  Pcs.");
        printToKitchen.append("\n");
        printToKitchen.append("----------------------------\n\n");

        QSqlQuery sql;

        if(isFoodAlreadyInsterted(name) == false)

        {
            sql.prepare("INSERT INTO TempTransactionDetails(food, quantity, price, subtotal, transaction_id) VALUES( :food, :quantity, :price, :subtotal, :transaction_id)");

            sql.bindValue(":food",name);
            sql.bindValue(":quantity",quantity);
            sql.bindValue(":price",price);
            sql.bindValue(":subtotal",subTotal);
            sql.bindValue(":transaction_id",new_order_id);
            bool flag =   sql.exec();
            qDebug()<<flag;
        }

        else
        {
            sql.prepare("UPDATE TempTransactionDetails SET quantity = quantity+:quant, subtotal = price*(quantity+:quant) WHERE transaction_id = :t_id AND food = :food");
            sql.bindValue(":quant", quantity);
            sql.bindValue(":t_id", new_order_id);
            sql.bindValue(":food", name);
            bool r = sql.exec();
            qDebug()<<"table updated:  "<<r;

        }
    }


    resetVariables();
    loadEmptyWidget(ui->scrollArea_DetailMainWindow);
    loadEmptyWidget(ui->scrollAreaCalcList);
    ui->lbl_TotalHeader->setText("");




    Util::Print(printToKitchen);
    Util::Print(printToKitchen);

}


void MainWindow::resetVariables()
{
    new_order_id = "";
    selectedBoy = "";
    selectedTable = "";
    currentBoy = "";
    currentTable = "";
    cancelFlag = false;
    cancel_id = "";
    QVector<Food*> empty;
    allTempSelectedFood = empty;
    notedText = "";

    ui->boysComboBox->setEnabled(true);
    ui->combo_tables->setEnabled(true);
}

void MainWindow::on_btn_CurrentOrder_clicked()
{

    loadEmptyWidget(ui->scrollAreaCalcList);

    ui->boysComboBox->setEnabled(true);
    ui->combo_tables->setEnabled(true);
    //

    resetVariables();
    //


    QSqlQueryModel* model = new QSqlQueryModel();

    currentOrdersTable = new QTableView();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM TempTransaction");
    //qry.prepare("SELECT food, quantity, price, subtotal FROM TempTransactionDetails UNIQUE(transaction_id)");
    bool r = qry.exec();
    qDebug()<<((r == true)?"Success":"Not selected");

    model->setQuery(qry);
    currentOrdersTable->setModel(model);

    connect(currentOrdersTable, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onTableViewDoubleClicked(QModelIndex)), Qt::UniqueConnection);
    // connect(currentOrdersTable->selectionModel(), SIGNAL(selectionChanged ( const QItemSelection & , const QItemSelection &  )), this, SLOT(onSelectionChanged ( const QItemSelection & , const QItemSelection &  )));
    //connect( tableView->selectionModel(), SIGNAL( selectionChanged( const QItemSelection & )), this, SLOT( selectionChanged( const QItemSeleciton & )), Qt::DirectConnection);

    currentOrdersTable->resizeColumnsToContents();
    currentOrdersTable->horizontalHeader()->setStretchLastSection(true);
    ui->scrollArea_DetailMainWindow->setWidget(currentOrdersTable);
}

void MainWindow::on_btn_CancelOrder_clicked()
{
    loadEmptyWidget(ui->scrollAreaCalcList);
    ui->boysComboBox->setEnabled(false);
    ui->combo_tables->setEnabled(false);
    //   loadEmptyWidget(ui->scrollArea_DetailMainWindow_2);
    //

    resetVariables();
    //


    QSqlQueryModel* model = new QSqlQueryModel();
    cancelOrdersTable = new QTableView();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM TempTransaction");
    bool r = qry.exec();
    qDebug()<<((r == true)?"Success":"Not selected");
    model->setQuery(qry);
    cancelOrdersTable->setModel(model);
    cancelOrdersTable->resizeColumnsToContents();
    cancelOrdersTable->horizontalHeader()->setStretchLastSection(true);
    ui->scrollArea_DetailMainWindow->setWidget(cancelOrdersTable);

    connect(cancelOrdersTable, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onCancelOrderViewDoubleClicked(QModelIndex)));



}

void MainWindow::on_viewTable_clicked()
{
    QSqlQuery query1;

    query1.prepare("SELECT DISTINCT dining FROM TempTransaction");
    bool r = query1.exec();
    QVector<QString> engazedTables;
    QVector<QString> Tables;

    if(r == true)
    {
        while(query1.next())
        {
            qDebug()<< query1.record().value("dining").toString();
            engazedTables.push_back(query1.record().value("dining").toString());
        }
    }

    QSqlQuery query2;
    query2.prepare("SELECT * FROM DiningTables");
    r =query2.exec();
    if(r == true)
    {
        while(query2.next())
        {
            Tables.push_back(query2.record().value("name").toString());
        }
    }

    for(int i =0; i<Tables.size(); i++)
    {
        TableStatus* tableStatus = new TableStatus();

        tableStatus->setTableName(Tables.at(i));
        if(engazedTables.contains(Tables.at(i)))
        {
            tableStatus->setTableStatus(TableStatus::OFF);
        }
        else
        {
            tableStatus->setTableStatus(TableStatus::ON);
        }

        allTableStatus.push_back(tableStatus);
    }

    //====================

    tableStatusList = new QListWidget();
    for(int i = 0 ; i < allTableStatus.size() ; i++){
        QListWidgetItem* item = new QListWidgetItem();
        item->setSizeHint(QSize(0,60));
        QWidget *widget = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->addWidget(allTableStatus.at(i));
        widget->setLayout(layout);

        // item->setText(QString::number(i));

        tableStatusList->addItem(item);
        tableStatusList->setItemWidget(item,widget);
    }

    ui->scrollArea_DetailMainWindow->setWidget(tableStatusList);
    //=========================
    QVector<QString> empty;
    engazedTables = empty;
    Tables = empty;
    QVector<TableStatus*> emp;
    allTableStatus = emp;

}

void MainWindow::on_discount_clicked()
{
    discountInput = new QLineEdit();
    discountInput->setText(QString::number(nDiscount));
    discountInput->setFocus(Qt::OtherFocusReason);
    discountInput->setValidator(new QIntValidator(0, 1000, this));
    discountInput->setWindowModality(Qt::ApplicationModal);
    connect(discountInput, SIGNAL(returnPressed()), SLOT(onDiscouReturnPressed()));

    discountInput->show();
}

void MainWindow::on_btn_Pay_clicked()
{
    if(new_order_id == ""){showMessage("Select an order to Pay"); return;}
    payInput = new QLineEdit();
    payInput->setFocus(Qt::OtherFocusReason);
    payInput->setValidator(new QIntValidator(0, 1000000, this));
    payInput->setWindowModality(Qt::ApplicationModal);
    connect(payInput, SIGNAL(returnPressed()), SLOT(onPayInputReturnPressed()));

    payInput->show();
}




void MainWindow::on_btn_Calculator_clicked()
{
    Calculator *calc = new Calculator;
    calc->setWindowModality(Qt::ApplicationModal);
    calc->show();
}

void MainWindow::on_btn_Admin_clicked()
{
    AdminLogin *adminLogin = new AdminLogin();
    adminLogin->setWindowModality(Qt::ApplicationModal);
    connect(adminLogin, SIGNAL(signal_AdminLogouted()), this, SLOT(onAdminLogoutClicked()));

    adminLogin->show();
}

void MainWindow::onAdminLogoutClicked()
{
    qDebug()<<"onAdminLogoutClicked";
}

void MainWindow::on_btn_Exit_clicked()
{
    this->close();
    UserLogin *w = new UserLogin();
    w->show();
}

void MainWindow::on_btn_Note_clicked()
{
    txtNote = new QLineEdit();
    txtNote->setMinimumSize(300,300);
    txtNote->setWindowModality(Qt::ApplicationModal);
    connect(txtNote, SIGNAL(returnPressed()), this, SLOT(onNotedTextEntered()));
    txtNote->show();


}
