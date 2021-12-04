#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //界面默认按钮
    ui->PB_AllAdress->hide();
    ui->PB_GroupAdress->hide();
    ui->PB_QueryAdress->hide();
    ui->PB_TextInfo->hide();
    ui->PB_DiffHashfun->hide();
    ui->PB_DiffConflict->hide();

    //通讯录-全部-控件
    ui->List_AddressBook->hide();
    ui->Text_MemberInfo->hide();
    ui->Text_OverallInfo->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();

    //按钮连接
    connect(ui->PB_AddressList, SIGNAL(clicked()), this, SLOT(Press_AdressList()));
    connect(ui->PB_Text, SIGNAL(clicked()), this, SLOT(Press_Text()));
    connect(ui->PB_AllAdress, SIGNAL(clicked()), this, SLOT(Press_AllAdress()));
    connect(ui->PB_GroupAdress, SIGNAL(clicked()), this, SLOT(Press_GroupAdress()));
    connect(ui->PB_QueryAdress, SIGNAL(clicked()), this, SLOT(Press_QueryAdress()));
    connect(ui->PB_TextInfo, SIGNAL(clicked()), this, SLOT(Press_TextInfo()));
    connect(ui->PB_DiffHashfun, SIGNAL(clicked()), this, SLOT(Press_DiffHashfun()));
    connect(ui->PB_DiffConflict, SIGNAL(clicked()), this, SLOT(Press_DiffConflict()));

    connect(ui->List_AddressBook, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Press_AdressBook(QListWidgetItem*)));

}

void MainWindow::Press_AdressList()
{
    //界面默认按钮
    ui->PB_AllAdress->show();
    ui->PB_GroupAdress->show();
    ui->PB_QueryAdress->show();
    ui->PB_TextInfo->hide();
    ui->PB_DiffHashfun->hide();
    ui->PB_DiffConflict->hide();

    //通讯录-全部-控件
    ui->List_AddressBook->show();
    ui->Text_MemberInfo->show();
    ui->Text_OverallInfo->show();
    ui->PB_AddMember->show();
    ui->PB_DeleteMember->show();
    ui->PB_ChangeMember->show();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
}

void MainWindow::Press_Text()
{
    //界面默认按钮
    ui->PB_TextInfo->show();
    ui->PB_DiffHashfun->show();
    ui->PB_DiffConflict->show();
    ui->PB_AllAdress->hide();
    ui->PB_GroupAdress->hide();
    ui->PB_QueryAdress->hide();

    //通讯录-全部-控件
    ui->List_AddressBook->hide();
    ui->Text_MemberInfo->hide();
    ui->Text_OverallInfo->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
}

void MainWindow::Press_AllAdress()
{
    //通讯录-全部-控件
    ui->PB_AddMember->show();
    ui->PB_DeleteMember->show();
    ui->PB_ChangeMember->show();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
}

void MainWindow::Press_GroupAdress()
{
    //通讯录-全部-控件
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->show();
    ui->PB_ManageGroup->show();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
}

void MainWindow::Press_QueryAdress()
{
    //通讯录-全部-控件
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->show();
}

void MainWindow::Press_TextInfo()
{

}

void MainWindow::Press_DiffHashfun()
{

}

void MainWindow::Press_DiffConflict()
{

}

void MainWindow::Press_AdressBook(QListWidgetItem* item)
{
    qDebug() << item->text() << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
