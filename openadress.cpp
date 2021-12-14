#include "openadress.h"
#include "ui_openadress.h"

OpenAdress::OpenAdress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenAdress)
{
    ui->setupUi(this);
    this->setMinimumSize(800, 600);
    this->setMaximumSize(800, 600);
}

void OpenAdress::set_List()
{
    ui->List_AddressList->clear();

    QDir dir("../addressbook/");
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    QFileInfoList list = dir.entryInfoList();

    qDebug() << list << endl;

    for (int i=0; i<list.size(); i++){
        QString filename = list.at(i).fileName();
        filename = filename.left(filename.size()-4);
        ui->List_AddressList->addItem(filename);
    }
}

OpenAdress::~OpenAdress()
{
    delete ui;
}
