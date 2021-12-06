#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QtDebug>

#include "address.h"
#include "addressbook.h"
#include "openadress.h"

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

    void Press_OpenAddressBook();
    void Press_AddMember();
    void Press_DeleteMember();
    void Press_ChangeMember();
    void Press_SortName();
    void Press_SortPhone();
    void Press_SortUp();
    void Press_SortDown();

    void Press_CreateGroup();
    void Press_ManageGroup();

    void Press_QueryMember();

    void Press_AdressBook(QListWidgetItem* item);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    OpenAdress *openad;
};

#endif // MAINWINDOW_H
