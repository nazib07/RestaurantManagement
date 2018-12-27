#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    rowCount(0),
    userSelectedForTransaction("ALL"),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    util.ConnectDatabase(PATH_TO_DB);

    listWidget = new QListWidget();
    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(onListFoodCatagoryItemClicked(QListWidgetItem*)));
    populateCatagoryList();
    populateTableList();
    populateBoyList();
    populateFoodList();

    addCustomPlot(ui->widget_Graph);

    connect(ui->dateTimeEdit_Start, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(onDateTimeFromChanged(QDateTime)));
    connect(ui->dateTimeEdit_End, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(onDateTimeToChanged(QDateTime)));
}

AdminWindow::~AdminWindow()
{
    //   delete addCatagory;
    delete ui;
}

void AdminWindow::on_btn_AddFoodCatagory_clicked()
{
    AddNewCatagory* newCatagory = new AddNewCatagory();
    newCatagory->setWindowModality(Qt::ApplicationModal);
    connect(newCatagory, SIGNAL(AddCatagoryNewButtonClicked(QString, QImage)), this, SLOT(onAddCatagoryNewButtonClicked(QString, QImage)));

    newCatagory->show();
}

void AdminWindow::addFoodCatagory(QString catagoryName, QImage imageName)
{
    QString s = QString::number(rowCount++);
    QWidget* w = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    w->setLayout(layout);

    FoodCatagory* newCatagory = new FoodCatagory();
    newCatagory->SetName(s);
    newCatagory->SetCatagory(catagoryName);
    newCatagory->SetImage(imageName);

    foodCatagories.push_back(newCatagory);

    layout->addWidget(newCatagory);

    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint(QSize(0,60));


    item->setText(s);
    listWidget->setSpacing(2);
    listWidget->addItem(item);
    listWidget->setItemWidget(item, w);


    ui->scrollArea_FoodCatagory->setWidget(listWidget);

}

AdminWindow* AdminWindow::instance = NULL;

AdminWindow *AdminWindow::getInstance()
{
    instance = new AdminWindow();
    return instance;
}

void AdminWindow::populateCatagoryList()
{
    listCatagory = new QListWidget();


    QWidget *widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    QSqlQuery query;
    query.prepare("SELECT * FROM Catagories");
    bool r = query.exec();
    if(r == true)
    {
        while(query.next())
        {
            qDebug()<<"Catagory Selected: "<<query.record().value("name").toString();
            //======================
            QListWidgetItem* item = new QListWidgetItem();
            item->setSizeHint(QSize(0,60));



            FoodCatagory *catagory = new FoodCatagory();
            catagory->SetName(query.record().value("name").toString());
            layout->addWidget(catagory);
            connect(catagory, SIGNAL(signal_foodCataoryRemoved(QString)), this, SLOT(onFoodCatagoryRemoved(QString)));
            connect(catagory, SIGNAL(signal_foodCataoryEdited(QString)), this, SLOT(onFoodCatagoryEdited(QString)));

            //        item->setText(QString::number(i));

            //==============================

        }



        widget->setLayout(layout);
        ui->scrollArea_FoodCatagory->setWidget(widget);



    }
}

void AdminWindow::populateTableList()
{
    listTable = new QListWidget();


    QWidget *widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    QSqlQuery query;
    query.prepare("SELECT * FROM DiningTables");
    bool r = query.exec();
    if(r == true)
    {
        while(query.next())
        {
            qDebug()<<"Table Selected: "<<query.record().value("name").toString();
            //======================
            QListWidgetItem* item = new QListWidgetItem();
            item->setSizeHint(QSize(0,60));



            DiningTables *catagory = new DiningTables();
            catagory->SetName(query.record().value("name").toString());
            layout->addWidget(catagory);
            connect(catagory, SIGNAL(signal_tableRemoved(QString)), this, SLOT(onTableRemoved(QString)));
            connect(catagory, SIGNAL(signal_tableEdited(QString)), this, SLOT(onTableEdited(QString)));

            //        item->setText(QString::number(i));

            //==============================

        }



        widget->setLayout(layout);
        ui->scrollArea_TablesDetail->setWidget(widget);



    }

}

void AdminWindow::populateBoyList()
{
    listBoy = new QListWidget();


    QWidget *widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    QSqlQuery query;
    query.prepare("SELECT * FROM Boys");
    bool r = query.exec();
    if(r == true)
    {
        while(query.next())
        {
            qDebug()<<"Boy Selected: "<<query.record().value("name").toString();
            //======================
            QListWidgetItem* item = new QListWidgetItem();
            item->setSizeHint(QSize(0,60));



            BoyRow *catagory = new BoyRow();
            Boys *boy = new Boys();
            boy->setName(query.record().value("name").toString());
            boy->setMobile(query.record().value("mobile").toString());
            boy->setPhoto(query.record().value("photo").toString());
            boy->setAddress(query.record().value("address").toString());

            catagory->SetBoy(boy);
            layout->addWidget(catagory);


            connect(catagory, SIGNAL(signal_boyRemoved(QString)), this, SLOT(onBoyRemoved(QString)));
            connect(catagory, SIGNAL(signal_boyEdited(Boys*)), this, SLOT(onBoyEdited(Boys*)));
            connect(catagory, SIGNAL(signal_boyViewed(Boys*)), this, SLOT(onBoyViewed(Boys*)));

        }



        widget->setLayout(layout);
        ui->scrollArea_BoysDetail->setWidget(widget);



    }
}

void AdminWindow::populateFoodList()
{
    listFood = new QListWidget();


    QWidget *widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    QSqlQuery query;
    query.prepare("SELECT * FROM Foods");
    bool r = query.exec();
    if(r == true)
    {
        while(query.next())
        {
          //  qDebug()<<"Food Selected: "<<query.record().value("name").toString();
            //======================
            QListWidgetItem* item = new QListWidgetItem();
            item->setSizeHint(QSize(0,60));



            FoodRow *catagory = new FoodRow();
            Food *food = new Food();
            food->setName(query.record().value("Name").toString());
            food->setCatagroy(query.record().value("Catagory").toString());
            food->setPrice(query.record().value("Price").toFloat());



            catagory->SetFood(food);
            layout->addWidget(catagory);


            connect(catagory, SIGNAL(signal_foodRemoved(QString)), this, SLOT(onFoodRemoved(QString)));
            connect(catagory, SIGNAL(signal_foodEdited(Food*)), this, SLOT(onFoodEdited(Food*)));


        }



        widget->setLayout(layout);
        ui->scrollArea_FoodAdd->setWidget(widget);



    }
}

void AdminWindow::addCustomPlot(QCustomPlot *customPlot)
{

    // generate some data:
    QVector<double> x1(101), y1(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x1[i] = i/50.0 - 1; // x goes from -1 to 1
      y1[i] = x1[i]*x1[i];  // let's plot a quadratic function
    }
//    // create graph and assign data to it:
//    customPlot->addGraph();
//    customPlot->graph(0)->setData(x, y);
//    // give the axes some labels:
//    customPlot->xAxis->setLabel("x");
//    customPlot->yAxis->setLabel("y");
//    // set axes ranges, so we see all data:
//    customPlot->xAxis->setRange(-1, 1);
//    customPlot->yAxis->setRange(0, 1);

    QCPGraph *graph1 = customPlot->addGraph();
    graph1->setData(x1, y1);
    graph1->setPen(Qt::NoPen);
    graph1->setBrush(QColor(70, 165, 255, 150));

    customPlot->addLayer("abovemain", customPlot->layer("main"), QCustomPlot::limAbove);
    customPlot->addLayer("belowmain", customPlot->layer("main"), QCustomPlot::limBelow);
    graph1->setLayer("abovemain");
    customPlot->xAxis->grid()->setLayer("belowmain");
    customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    customPlot->axisRect()->setBackground(axisRectGradient);

    customPlot->rescaleAxes();
    customPlot->yAxis->setRange(0, 2);

}

void AdminWindow::loadEmptyWidget(QScrollArea *area)
{
    QWidget* widget = new QWidget();
    area->setWidget(widget);

}

void AdminWindow::onAddCatagoryNewButtonClicked(QString str, QImage img)
{
    //    addFoodCatagory(str, img);

    QString name = str;
    QString picture = "default.png";
    QString description = "Nothing";

    QSqlQuery query;
    query.prepare("INSERT INTO Catagories(name, picture, description) VALUES(:name, :pic, :desc)");
    query.bindValue(":name", name);
    query.bindValue(":pic", picture);
    query.bindValue(":desc", description);
    bool r =query.exec();

    if(r == true)
    {
        qDebug()<<"Insert Catgory Successfully";
        populateCatagoryList();
    }
    else
    {
        qDebug()<<"Insert Catgory Failed";
    }



}

void AdminWindow::onListFoodCatagoryItemClicked(QListWidgetItem *item)
{

    //    QString str = item->text();
    //    qDebug()<<str;

}

void AdminWindow::onFoodCatagoryRemoved(QString Name)
{
    qDebug()<<"Removing Catagory Name: "<<Name;
    QSqlQuery query;
    query.prepare("DELETE FROM Catagories WHERE name = :name");
    query.bindValue(":name", Name);
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Removed Successfully";

        QSqlQuery query1;
        query1.prepare("DELETE FROM Foods WHERE Catagory = :name");
        query1.bindValue(":name", Name);
        bool rr = query1.exec();

        if(rr)
        {
            qDebug()<<"Foods Removed Successfully";
            populateFoodList();

        }
        populateCatagoryList();
    }


}

void AdminWindow::onFoodCatagoryEdited(QString name)
{
    qDebug()<<"Editing Catagory Name: "<<name;


    UpdateFoodCatagory* newCatagory = new UpdateFoodCatagory();
    newCatagory->setWindowModality(Qt::ApplicationModal);
    newCatagory->setPrevName(name);
    connect(newCatagory, SIGNAL(UpdateCatagoryButtonClicked(QString, QString)), this, SLOT(onUpdateCatagoryButtonClicked(QString, QString)));

    newCatagory->show();

}

void AdminWindow::onUpdateCatagoryButtonClicked(QString prevName, QString currName)
{
    qDebug()<<"Update: "<<prevName <<currName;
    QSqlQuery query;
    query.prepare("UPDATE Catagories SET name = :currName WHERE name =:prevName");
    query.bindValue(":currName",currName );
    query.bindValue(":prevName", prevName);
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Updated Succsesfully";
    }
    else
    {
        qDebug()<<"Update Failed";
    }

    populateCatagoryList();

}

void AdminWindow::onAddTableNewButtonClicked(QString name)
{

    QString type = "default";

    QSqlQuery query;
    query.prepare("INSERT INTO DiningTables(name, type) VALUES(:name, :type)");
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    bool r =query.exec();

    if(r == true)
    {
        qDebug()<<"Insert table Successfully";
        populateTableList();
    }
    else
    {
        qDebug()<<"Insert table Failed";
    }

}

void AdminWindow::onTableRemoved(QString Name)
{
    qDebug()<<"Removing Table Name: "<<Name;
    QSqlQuery query;
    query.prepare("DELETE FROM DiningTables WHERE name = :name");
    query.bindValue(":name", Name);
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Removed Successfully";
    }
}

void AdminWindow::onTableEdited(QString name)
{
    qDebug()<<"Editing Table Name: "<<name;


    updateTable* newCatagory = new updateTable();
    newCatagory->setWindowModality(Qt::ApplicationModal);
    newCatagory->setPrevName(name);
    connect(newCatagory, SIGNAL(UpdateTableButtonClicked(QString, QString)), this, SLOT(onUpdateTableButtonClicked(QString, QString)));

    newCatagory->show();

}

void AdminWindow::onUpdateTableButtonClicked(QString prevName, QString currName)
{
    qDebug()<<"Update: "<<prevName <<currName;
    QSqlQuery query;
    query.prepare("UPDATE DiningTables SET name = :currName WHERE name =:prevName");
    query.bindValue(":currName",currName );
    query.bindValue(":prevName", prevName);
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Updated Succsesfully";
    }
    else
    {
        qDebug()<<"Update Failed";
    }

    populateTableList();
}

void AdminWindow::onBoyAddedSignalRecieved(Boys *boy)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Boys(name, address, photo, mobile) VALUES(:name, :address, :photo, :mobile)");
    query.bindValue(":name",boy->getName());
    query.bindValue(":address", boy->getAddress());
    query.bindValue(":photo", boy->getPhoto());
    query.bindValue(":mobile", boy->getMobile());
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Boy inserted successfully";
        populateBoyList();

    }
    else
    {
        qDebug()<<"Boy not inserted successfully";
    }
}

void AdminWindow::onBoyRemoved(QString Name)
{
    qDebug()<<"Removing Boy Name: "<<Name;
    QSqlQuery query;
    query.prepare("DELETE FROM Boys WHERE name = :name");
    query.bindValue(":name", Name);
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Removed Successfully";
    }
    populateBoyList();
}

void AdminWindow::onBoyEdited(Boys *boy)
{
    qDebug()<<"Editing Boy Name: "<<boy->getName();


    updateBoy* newCatagory = new updateBoy();
    newCatagory->setWindowModality(Qt::ApplicationModal);

    newCatagory->setPrev_boy(boy);


    connect(newCatagory, SIGNAL(UpdateBoyButtonClicked(Boys*, Boys*)), this, SLOT(onUpdateBoyButtonClicked(Boys*, Boys*)));

    newCatagory->show();

}

void AdminWindow::onBoyViewed(Boys* boy)
{
    boyView* boyview = new boyView();
    boyview->setBoy(boy);
    boyview->setWindowModality(Qt::ApplicationModal);
    boyview->show();

}

void AdminWindow::onUpdateBoyButtonClicked(Boys *prev_boy, Boys *curr_boy)
{
    qDebug()<<"Update Boy: "<<prev_boy->getName() <<curr_boy->getName();
    QSqlQuery query;
    query.prepare("UPDATE Boys SET name = :currName, address = :adr, photo = :pht, mobile = :mob WHERE name =:prevName");
    query.bindValue(":currName",curr_boy->getName() );
    query.bindValue(":adr",curr_boy->getAddress() );
    query.bindValue(":pht",((curr_boy->getPhoto() != NULL)?curr_boy->getPhoto():prev_boy->getPhoto()) );
    query.bindValue(":mob",curr_boy->getMobile() );

    query.bindValue(":prevName", prev_boy->getName());
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Boy Updated Succsesfully";
    }
    else
    {
        qDebug()<<"Boy Update Failed";
    }

    populateBoyList();
}

void AdminWindow::onFoodRemoved(QString Name)
{
    qDebug()<<"Removing Food Name: "<<Name;
    QSqlQuery query;
    query.prepare("DELETE FROM Foods WHERE name = :name");
    query.bindValue(":name", Name);
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Removed Successfully";
    }
    populateFoodList();
}

void AdminWindow::onFoodEdited(Food *food)
{    qDebug()<<"Editing Food Name: "<<food->getName();

QStringList allCatagoriesList;
     UpdateFood* newCatagory = new UpdateFood();
     newCatagory->setWindowModality(Qt::ApplicationModal);

      /**/
      QSqlQuery *query = new QSqlQuery();
      query->prepare("SELECT * FROM Catagories");
      bool result = query->exec();

      if(result == true){
          while(query->next())
          {
              QString name = query->record().value("name").toString();
              allCatagoriesList.append(name);
          }
      }
     newCatagory->setCatagoryList(allCatagoriesList);
     newCatagory->setPrevFood(food);

      delete query;


     connect(newCatagory, SIGNAL(UpdateFoodButtonClicked(Food*, Food*)), this, SLOT(onUpdateFoodButtonClicked(Food*, Food*)));

     newCatagory->show();


}

void AdminWindow::onUpdateFoodButtonClicked(Food *prev_food, Food *curr_food)
{
    qDebug()<<"Update Food: "<<prev_food->getName() <<curr_food->getName();
    QSqlQuery query;
    query.prepare("UPDATE Foods SET Name = :currName, Catagory = :cat, Price = :price WHERE Name =:prevName");
    query.bindValue(":currName",curr_food->getName() );
    query.bindValue(":cat",curr_food->getCatagroy());
    query.bindValue(":price",curr_food->getPrice() );

    query.bindValue(":prevName", prev_food->getName());
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Food Updated Succsesfully";
    }
    else
    {
        qDebug()<<"Food Update Failed";
    }

    populateFoodList();
}

void AdminWindow::onFoodAddedSignalRecieved(Food *food)
{
    QSqlQuery query;
    QString pic = "defalult.jpg";//need to update later
    QString desc = "None"; //need t be upadate later

    query.prepare("INSERT INTO Foods(Name, Catagory, Price, Picture, Description) VALUES(:name, :cat, :prc, :pic, :desc)");
    query.bindValue(":name",food->getName());
    query.bindValue(":cat", food->getCatagroy());
    query.bindValue(":prc", food->getPrice());
    query.bindValue(":pic", pic);
    query.bindValue(":desc", desc);
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"Food inserted successfully";
        populateFoodList();

    }
    else
    {
        qDebug()<<"Food not inserted successfully";
    }
}

void AdminWindow::onTransactionTableDoubleClicked(QModelIndex index)
{

    if(index.column() >0) return;
  QSqlQueryModel* model = new QSqlQueryModel();
  transactionDetail = new QTableView();

  qDebug()<< transactionTable->model()->data(index).toString();
  QString data  = transactionTable->model()->data(index).toString();
  QSqlQuery qr ;
  qr.prepare("SELECT food, quantity, subtotal FROM TransactionsDetails WHERE TransactionID = :t_id");
  qr.bindValue(":t_id",data);
  bool res = qr.exec();
  if(res)
  {
      model->setQuery(qr);
      transactionDetail->setModel(model);

      qDebug()<<data;

      while(qr.next())
      {

          qDebug()<<qr.record().value("food")<<qr.record().value("quantity");
      }
  }

  transactionDetail->resizeColumnsToContents();
  transactionDetail->horizontalHeader()->setStretchLastSection(true);
  transactionDetail->setWindowModality(Qt::ApplicationModal);
  transactionDetail->show();

}

void AdminWindow::onDateTimeFromChanged(QDateTime datetime)
{
    fromDateTime = datetime;
    qDebug()<<datetime.date();
    qDebug()<<datetime.time();
}

void AdminWindow::onDateTimeToChanged(QDateTime datetime)
{
    toDateTime = datetime;
    qDebug()<<datetime.date();
    qDebug()<<datetime.time();
}

void AdminWindow::onUserRemoved(QString name)
{
    QSqlQuery q;
    q.prepare("DELETE FROM Users WHERE name = :name");
    q.bindValue(":name", name);
    bool r = q.exec();

    if(r)
    {
        qDebug()<<"User Deleted Successfully";
        on_btn_Users_clicked();
    }

    else
    {
        qDebug()<<"User Delete failed";
    }



}

void AdminWindow::onUserEdited(UserRegiData *userData)
{
    isUserEditBtnClicked = false;
    UserEdit *userEdit = new UserEdit();
    userEdit->setUserData(userData);

    connect(userEdit, SIGNAL(UserEditButtonClicked(UserRegiData*,UserRegiData*)), this, SLOT(onUserEditButtonClicked(UserRegiData*,UserRegiData*)));
    connect(userEdit, SIGNAL(onCloseEvent()), this, SLOT(onUserEditFormDestroyed()),Qt::UniqueConnection);
    userEdit->setWindowModality(Qt::ApplicationModal);
    userEdit->show();

}

void AdminWindow::onUserViewed(UserRegiData *userData)
{
    UserView *userView = new UserView();
    userView->setName(userData->getName());
    userView->setMobile(userData->getMobile());
    userView->setType(userData->getType());
    userView->setAddress(userData->getAddress());
    userView->setPhoto(userData->getPhoto());

    userView->setWindowModality(Qt::ApplicationModal);
    userView->show();
}

void AdminWindow::onUserRegiSubmitted(UserRegiData *userData)
{

    QSqlQuery query;
    query.prepare("INSERT INTO Users(name, password, type, address, mobile, photo) VALUES(:name, :pass, :type, :address, :mobile, :photo)");
    query.bindValue(":name",userData->getName());
    query.bindValue(":pass",userData->getPass());
    query.bindValue(":type",userData->getType());
    query.bindValue(":address", userData->getAddress());
    query.bindValue(":mobile", userData->getMobile());
    query.bindValue(":photo", userData->getPhoto());
    bool r = query.exec();

    if(r == true)
    {
        qDebug()<<"User inserted successfully";
        on_btn_Users_clicked();

    }
    else
    {
        qDebug()<<"User not inserted successfully";
    }
}

void AdminWindow::onUserEditButtonClicked(UserRegiData *prev_user, UserRegiData *curr_user)
{
    isUserEditBtnClicked = true;

    QString name = curr_user->getName();
    QString pass = curr_user->getPass();
    QString type = curr_user->getType();
    QString address = curr_user->getAddress();
    QString mobile = curr_user->getMobile();
    QString photo = ((curr_user->getPhoto() != NULL)?curr_user->getPhoto():prev_user->getPhoto());

    QString prev_name = prev_user->getName();
//    QString prev_type = prev_user->getType();
//    QString prev_pass = prev_user->getPass();

    QSqlQuery q;
    q.prepare("UPDATE Users SET name = :name, password = :pass, type = :type, address = :address, mobile = :mobile, photo = :photo WHERE name = :prev_name");
    q.bindValue(":name", name);
    q.bindValue(":pass", pass);
    q.bindValue(":type", type);
    q.bindValue(":address", address);
    q.bindValue(":mobile", mobile);
    q.bindValue(":photo", photo);
    q.bindValue(":prev_name", prev_name);
//    q.bindValue(":prev_type", prev_type);
//    q.bindValue("prev_pass", prev_pass);

    bool r = q.exec();

    if(r)
    {
        qDebug()<<"User Updated Successfully";

    }

    else
    {

        qDebug()<<"User Update failed";

    }


    on_btn_Users_clicked();



}

void AdminWindow::onUserEditFormDestroyed()
{
    if(!isUserEditBtnClicked)
        on_btn_Users_clicked();
}

void AdminWindow::onUserSelectedForTransactionRecieved(QString userName)
{
    userSelectedForTransaction = userName;
}

void AdminWindow::onVatReturnPressed()
{
    vat = vatInput->text();
    if(vat == "")return;

    QSqlQuery q;
    q.prepare("UPDATE vat SET vat = :v");
    q.bindValue(":v", vat.toFloat());
    bool r = q.exec();
    if(r)
    {
        qDebug()<<"vat updated successfully";
        vatInput->close();
    }
    else
    {
        qDebug()<<"vat update failed";
    }
}


void AdminWindow::on_btn_AddTable_clicked()
{
    AddNewTable* newTable = new AddNewTable();
    newTable->setWindowModality(Qt::ApplicationModal);
    connect(newTable, SIGNAL(AddTableNewButtonClicked(QString)), this, SLOT(onAddTableNewButtonClicked(QString)));

    newTable->show();
}

float AdminWindow::getVat()
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

void AdminWindow::on_btn_AddBoy_clicked()
{
    AddBoy* newBoy = new AddBoy();
    newBoy->setWindowModality(Qt::ApplicationModal);
    connect(newBoy, SIGNAL(signal_boyAdded(Boys*)), this, SLOT(onBoyAddedSignalRecieved(Boys*)));
    newBoy->show();
}

void AdminWindow::on_btn_AddFood_clicked()
{
    addFood* newFood = new addFood();
    newFood->setWindowModality(Qt::ApplicationModal);
QStringList allCatagoriesList;

    /**/
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * FROM Catagories");
    bool result = query->exec();

    if(result == true){
        while(query->next())
        {
            QString name = query->record().value("name").toString();
            allCatagoriesList.append(name);
        }
    }
   newFood->setCatagoryList(allCatagoriesList);


    delete query;


    connect(newFood, SIGNAL(signal_foodAdded(Food*)), this, SLOT(onFoodAddedSignalRecieved(Food*)));
    newFood->show();
}

void AdminWindow::on_btn_ViewDetailTransaction_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    transactionTable = new QTableView();

    QSqlQuery qr;

    float grandTotalSum = 0.0f;
    float grandDiscount = 0.0f;
    float grandVat = 0.0f;

   // qr.prepare("SELECT TransactionsDetails.TransactionID, (SUM(TransactionsDetails.SubTotal)-Transactions.discount) AS TotalSum, Transactions.discount, datetime(Transactions.period, 'unixepoch', 'localtime'), Transactions.boy, Transactions.dining FROM TransactionsDetails, Transactions WHERE Transactions.id = TransactionsDetails.TransactionID AND (datetime(period, 'unixepoch', 'localtime') >= datetime(:fromDate, 'unixepoch', 'localtime')  AND datetime(period, 'unixepoch', 'localtime') <= datetime(:toDate, 'unixepoch', 'localtime')) GROUP BY TransactionsDetails.TransactionID");
    if(userSelectedForTransaction == "ALL")
    {
        qr.prepare("SELECT TransactionsDetails.TransactionID, (SUM(TransactionsDetails.SubTotal)-((Transactions.discount*SUM(TransactionsDetails.SubTotal))/100) + ((Transactions.vat*SUM(TransactionsDetails.SubTotal))/100) ) AS TotalSum, Transactions.discount, Transactions.vat, datetime(Transactions.period, 'unixepoch', 'localtime') AS Transactions_Time, Transactions.boy, Transactions.dining, Transactions.user, Transactions.comments FROM TransactionsDetails, Transactions WHERE Transactions.id = TransactionsDetails.TransactionID AND ((datetime(period, 'unixepoch', 'localtime') >= datetime(:fromDate, 'unixepoch', 'localtime')  AND datetime(period, 'unixepoch', 'localtime') <= datetime(:toDate, 'unixepoch', 'localtime'))) GROUP BY TransactionsDetails.TransactionID");
        qr.bindValue(":toDate", QString::number(toDateTime.toTime_t()));
        qr.bindValue(":fromDate", QString::number(fromDateTime.toTime_t()));

    }


    else
    {
        qr.prepare("SELECT TransactionsDetails.TransactionID, (SUM(TransactionsDetails.SubTotal)-((Transactions.discount*SUM(TransactionsDetails.SubTotal))/100) + ((Transactions.vat*SUM(TransactionsDetails.SubTotal))/100) ) AS TotalSum, Transactions.discount, Transactions.vat, datetime(Transactions.period, 'unixepoch', 'localtime') AS Transactions_Time, Transactions.boy, Transactions.dining, Transactions.user, Transactions.comments FROM TransactionsDetails, Transactions WHERE Transactions.id = TransactionsDetails.TransactionID AND ((datetime(period, 'unixepoch', 'localtime') >= datetime(:fromDate, 'unixepoch', 'localtime')  AND datetime(period, 'unixepoch', 'localtime') <= datetime(:toDate, 'unixepoch', 'localtime')) AND user = :user) GROUP BY TransactionsDetails.TransactionID");
        qr.bindValue(":toDate", QString::number(toDateTime.toTime_t()));
        qr.bindValue(":fromDate", QString::number(fromDateTime.toTime_t()));
        qr.bindValue(":user", userSelectedForTransaction);

    }


   // qr.prepare("SELECT * FROM Transactions WHERE datetime(period, 'unixepoch', 'localtime') >= datetime(:curr, 'unixepoch', 'localtime')");
  //  qr.bindValue(":curr",QString::number(QDateTime::currentDateTime().toTime_t()));
   // qr.bindValue(":unixepoch", "unixepoch");
    bool r = qr.exec();
    if(r)
    {
           model->setQuery(qr);
           transactionTable->setModel(model);

           int count = transactionTable->model()->rowCount();
           for(int i=0; i<count; i++)
           {

               float sum =  transactionTable->model()->data(transactionTable->model()->index(i,1)).toFloat();
               float dis =  transactionTable->model()->data(transactionTable->model()->index(i,2)).toFloat();
               float vat =  transactionTable->model()->data(transactionTable->model()->index(i,3)).toFloat();

               grandTotalSum += sum;

               grandDiscount += ((sum*100)/(100-dis))*(dis/100);
               grandVat += ((sum*100)/(100+vat))*(vat/100);



           }



//        while(qr.next())
//        {
//            qDebug()<<"nazib.........";

//            grandTotalSum += qr.record().value("TotalSum").toFloat();

//            qDebug()<< qr.record().value("TotalSum").toString();
//            qDebug()<< qr.record().value("TransactionID").toString();
//            qDebug()<< qr.record().value("period").toString();
//            qDebug()<< qr.record().value("boy").toString();
//            qDebug()<< qr.record().value("dining").toString();


//        }

           ui->lbl_totalSum->setText("Total : "+QString::number(grandTotalSum)+" <----> Total Discount: "+QString::number(grandDiscount)+" <----> Total Vat: "+QString::number(grandVat));

         grandTotalSum = 0.0f;
         grandDiscount = 0.0f;
         grandVat = 0.0f;

        connect(transactionTable, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onTransactionTableDoubleClicked(QModelIndex)), Qt::UniqueConnection);

        transactionTable->resizeColumnsToContents();
        transactionTable->horizontalHeader()->setStretchLastSection(true);
        ui->scrollArea_Detail->setWidget(transactionTable);

    }
    else
    {
        qDebug()<<qr.lastError();
    }
}

void AdminWindow::on_btn_AdminLogout_clicked()
{
    emit signal_AdminLogout();
    this->close();
}

void AdminWindow::on_btn_Users_clicked()
{
    QVector<UserRegiData*> allUsers;
    Users *users = new Users();
    //
    QSqlQuery query;
    query.prepare("SELECT * FROM Users");
    bool r = query.exec();

    if(r)
    {
        while(query.next())
        {
            UserRegiData *user = new UserRegiData();

            user->setName(query.record().value("name").toString());
            user->setType(query.record().value("type").toString());
            user->setPass(query.record().value("password").toString());
            user->setAddress(query.record().value("address").toString());
            user->setMobile(query.record().value("mobile").toString());
            user->setPhoto(query.record().value("photo").toString());

            allUsers.push_back(user);
        }
    }
    //

    connect(users, SIGNAL(signal_userRemoved(QString)), this, SLOT(onUserRemoved(QString)),  Qt::UniqueConnection);
    connect(users, SIGNAL(signal_userEdited(UserRegiData*)), this, SLOT(onUserEdited(UserRegiData*)), Qt::UniqueConnection);
    connect(users, SIGNAL(signal_userViewed(UserRegiData*)), this, SLOT(onUserViewed(UserRegiData*)),  Qt::UniqueConnection);

    connect(users, SIGNAL(signal_UserRegiSubmitted(UserRegiData*)), this, SLOT(onUserRegiSubmitted(UserRegiData*)), Qt::UniqueConnection);

    connect(this, SIGNAL(signal_AdminPanelUsersBtnClicked(QVector<UserRegiData*>)), users, SLOT(onAdminWindowUsersBtnClicked(QVector<UserRegiData*>)),  Qt::UniqueConnection);


    emit(signal_AdminPanelUsersBtnClicked(allUsers));

    users->setWindowModality(Qt::ApplicationModal);


    users->show();


}

void AdminWindow::on_btn_UserWiseTransaction_clicked()
{
    QVector<QString> allUserName;
    UserWiseTransaction *a = new UserWiseTransaction();
    a->setWindowModality(Qt::ApplicationModal);
    a->show();

    //
    QSqlQuery q;
    q.prepare("SELECT * FROM Users");
    bool r = q.exec();

    if(r)
    {
        while(q.next())
        {
            allUserName.push_back(q.record().value("name").toString());
        }

    }

    connect(this, SIGNAL(signal_AdminPanelUserWiseTransButtonClicked(QVector<QString>)), a, SLOT(onSignalAdminPanelUserWiseButtonRecieved(QVector<QString>)), Qt::UniqueConnection);
    connect(a, SIGNAL(signal_onUserSelectedForTransaction(QString)), this, SLOT(onUserSelectedForTransactionRecieved(QString)));

    emit signal_AdminPanelUserWiseTransButtonClicked(allUserName);
    //
}


void AdminWindow::on_btn_EditVat_clicked()
{

    QSqlQuery q;
    q.prepare("SELECT * FROM vat");
    bool r = q.exec();
    if(r)
    {
        while(q.next())
        {
            vat = q.record().value("vat").toString();
        }
    }

    vatInput = new QLineEdit();
    vatInput->setText(vat);
    vatInput->setFocus(Qt::OtherFocusReason);
    vatInput->setValidator(new QDoubleValidator(0, 1000, 2, this));
    vatInput->setWindowModality(Qt::ApplicationModal);
    connect(vatInput, SIGNAL(returnPressed()), SLOT(onVatReturnPressed()));

    vatInput->show();
}

void AdminWindow::on_btn_FoodTransaction_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    transactionTable = new QTableView();
    QSqlQuery q;
   // q.prepare("SELECT * FROM TransactionsDetails WHERE TransactionID = (SELECT id FROM Transactions WHERE datetime(period, 'unixepoch', 'localtime') >= datetime(:fromDate, 'unixepoch', 'localtime')  AND datetime(period, 'unixepoch', 'localtime') <= datetime(:toDate, 'unixepoch', 'localtime'))");
     q.prepare("SELECT TransactionsDetails.TransactionID FROM TransactionsDetails");
  //  q.bindValue(":toDate", QString::number(toDateTime.toTime_t()));
  //  q.bindValue(":fromDate", QString::number(fromDateTime.toTime_t()));

    bool r = q.exec();
    if(r)
    {
         qDebug()<<"Query Success"<<q.lastError().text();
           model->setQuery(q);
           transactionTable->setModel(model);
    }
    else
    {
        qDebug()<<"Query Error"<<q.lastError().text();
    }
}
