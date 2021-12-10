#include "changeinfopage.h"
#include "ui_changeinfopage.h"

ChangeInfoPage::ChangeInfoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeInfoPage)
{
    ui->setupUi(this);
}

ChangeInfoPage::~ChangeInfoPage()
{
    delete ui;
}





void ChangeInfoPage::on_lineEdit_name_textEdited(const QString &arg1)
{
    QString str=ui->lineEdit_name->text();
}
