#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QtDebug>
#include <QDir>

#include "address.h"
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
    void Input_CreateGroup();
    void Press_MemberInGroup(QListWidgetItem* item);

    void Press_QueryMember();
    void Input_QueryMember();
    void Press_QueryInfo();

    void Press_AdressBook(QListWidgetItem* item);

    void Press_AdressFilename(QListWidgetItem* item);

public:

    friend class OpenAdress;
    explicit MainWindow(QWidget *parent = nullptr);

    void Set_LinkList();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    OpenAdress *openad;

    //数据链表
    AddressList addresslinklist;
    //数据二叉树
    AddressBTree addressBTree;
};

#endif // MAINWINDOW_H
