#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QtDebug>

#include "address.h"
#include "addressbook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:   //槽函数
    void Press_AdressList();
    void Press_Text();
    void Press_AllAdress();
    void Press_GroupAdress();
    void Press_QueryAdress();
    void Press_TextInfo();
    void Press_DiffHashfun();
    void Press_DiffConflict();

    void Press_AdressBook(QListWidgetItem* item);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
