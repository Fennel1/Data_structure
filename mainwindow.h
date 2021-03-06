#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <algorithm>
#include <vector>
#include <QtDebug>
#include <QDir>
#include <QMessageBox>
#include <QRegExp>


#include "address.h"
#include "openadress.h"
#include "openartical.h"
#include "hashmap.h"
#include "changeinfopage.h"

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
    void Press_Save();
    void Press_CreateAdress();
    void Input_CreateAdress();

    void Press_CreateGroup();
    void Press_ManageGroup();
    void Input_CreateGroup();
    void Press_MemberInGroup(QListWidgetItem* item);
    void Press_ReturnGroup();

    void Press_QueryMember();
    void Input_QueryMember();
    void Press_QueryInfo();

    void Press_AdressBook(QListWidgetItem* item);
    void Press_AdressFilename(QListWidgetItem* item);

    void Press_OpenArtical();
    void Press_ArticalFileName(QListWidgetItem* item);

    void Press_HashLinear();
    void Press_HashQsr();
    void Press_HashRandom();
    void Press_HashLink();
    void Press_HashNewRule();

    void Press_DiffSqr();
    void Press_DiffMod();
    void Press_DiffRandom();
    void Input_SetHashSIZE();
    void Press_HashFunInfo(QListWidgetItem* item);
    void Press_HashDiffInfo(QListWidgetItem* item);

    void on_pushButton_clicked();

public:

    friend class OpenAdress;
    friend class OpenArtical;
    friend class ChangeInfoPage;

    explicit MainWindow(QWidget *parent = nullptr);
    bool PassEmail(QString email);
    void Set_LinkList();
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    OpenAdress *openad;
    OpenArtical *openartical;
    ChangeInfoPage *changeinfopage;

    //数据链表
    AddressList addresslinklist;
    //数据二叉树
    AddressBTree addressBTree;
    QString EMAIL;

    QStringList article;
    HashMap hashMap;

    int type;
    int basis;

    int hashfunType;
    int hashdiffType;
};

#endif // MAINWINDOW_H
