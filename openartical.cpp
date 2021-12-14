#include "openartical.h"
#include "ui_openartical.h"

OpenArtical::OpenArtical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenArtical)
{
    ui->setupUi(this);
    this->setMinimumSize(800, 600);
    this->setMaximumSize(800, 600);
}

void OpenArtical::set_List()
{
    ui->List_Artical->clear();

    QDir dir("../text/");
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    QFileInfoList list = dir.entryInfoList();

    qDebug() << list << endl;

    for (int i=0; i<list.size(); i++){
        QString filename = list.at(i).fileName();
        filename = filename.left(filename.size()-4);
        ui->List_Artical->addItem(filename);
    }
}

OpenArtical::~OpenArtical()
{
    delete ui;
}
