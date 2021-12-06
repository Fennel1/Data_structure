#include "openadress.h"
#include "ui_openadress.h"

OpenAdress::OpenAdress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenAdress)
{
    ui->setupUi(this);
}

OpenAdress::~OpenAdress()
{
    delete ui;
}
