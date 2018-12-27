#include "addnewcatagory.h"
#include "ui_addnewcatagory.h"

#include <QFileDialog>

AddNewCatagory::AddNewCatagory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewCatagory)
{
    ui->setupUi(this);
}

AddNewCatagory::~AddNewCatagory()
{
    delete ui;
}

void AddNewCatagory::SetName(QString name)
{
    ui->lineEdit_NewCatagory->setText(name);
}



void AddNewCatagory::on_btn_AddCatagory_clicked()
{
    QString catagoryName = ui->lineEdit_NewCatagory->text();
    QImage img = catagoryImage;
    if(img.isNull() == true)
    {
        img = QImage(":/graph.jpg");
    }

   img =  img.scaled(50, 50,Qt::KeepAspectRatio);
    emit AddCatagoryNewButtonClicked(catagoryName,img );
   this->close();
}

void AddNewCatagory::on_btn_BrowseImage_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
       tr("Open Images"), "/home/rpi/Desktop/Picture/Sample Pictures", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty())
    {
         QImage image(fileName);


         catagoryImage = image.scaled(100, 100,Qt::KeepAspectRatio);

      //   ui->lbl_AddCatagroyImage->setPixmap(QPixmap::fromImage(catagoryImage));

    }
}
