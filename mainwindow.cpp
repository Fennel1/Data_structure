#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //按钮默认隐藏
    ui->PB_AllAdress->hide();
    ui->PB_GroupAdress->hide();
    ui->PB_QueryAdress->hide();
    ui->PB_TextInfo->hide();
    ui->PB_DiffHashfun->hide();
    ui->PB_DiffConflict->hide();

    //按钮连接
    connect(ui->PB_AddressList, SIGNAL(clicked()), this, SLOT(Press_AdressList()));
    connect(ui->PB_Text, SIGNAL(clicked()), this, SLOT(Press_Text()));
    connect(ui->PB_AllAdress, SIGNAL(clicked()), this, SLOT(Press_AllAdress()));
    connect(ui->PB_GroupAdress, SIGNAL(clicked()), this, SLOT(Press_GroupAdress()));
    connect(ui->PB_QueryAdress, SIGNAL(clicked()), this, SLOT(Press_QueryAdress()));
    connect(ui->PB_TextInfo, SIGNAL(clicked()), this, SLOT(Press_TextInfo()));
    connect(ui->PB_DiffHashfun, SIGNAL(clicked()), this, SLOT(Press_DiffHashfun()));
    connect(ui->PB_DiffConflict, SIGNAL(clicked()), this, SLOT(Press_DiffConflict()));

}

void MainWindow::Press_AdressList()
{
    ui->PB_AllAdress->show();
    ui->PB_GroupAdress->show();
    ui->PB_QueryAdress->show();
    ui->PB_TextInfo->hide();
    ui->PB_DiffHashfun->hide();
    ui->PB_DiffConflict->hide();

}

void MainWindow::Press_Text()
{
    ui->PB_TextInfo->show();
    ui->PB_DiffHashfun->show();
    ui->PB_DiffConflict->show();
    ui->PB_AllAdress->hide();
    ui->PB_GroupAdress->hide();
    ui->PB_QueryAdress->hide();
}

void MainWindow::Press_AllAdress()
{

}

void MainWindow::Press_GroupAdress()
{

}

void MainWindow::Press_QueryAdress()
{

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

MainWindow::~MainWindow()
{
    delete ui;
}
