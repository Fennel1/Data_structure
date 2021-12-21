#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>
#include <QtDebug>
#include <QDir>

typedef struct{     //数据
    QString phone;
    QString name;
    QString email;
    QString address;
    QString remark;
    int groupIndex;
}Data;

typedef struct node_L{  //链表节点
    Data data;
    node_L *next;
}*List, Node_L;

typedef struct node_st{ //平衡二叉树节点
    Data data;
    node_st *lchild, *rchild;
    int bf;
}*BSTree, Node_BST;

class AddressList       //链表
{
public:
    AddressList();
    //按需求排序
    void AddressList_sort(int type, int basis);
    void init(QString filename);
    //添加删除节点
    void add_node(Data data);
    void delete_node(Data data);

    //排序算法
    Node_L* merge(Node_L *left, Node_L *right);
    Node_L* merge_sort(Node_L *head);
    Node_L* sortList(Node_L* head);

    void quick_sort();
    void qsort(int *list, int low, int high);

    Node_L* merge_name(Node_L *left, Node_L *right);
    Node_L* merge_sort_name(Node_L *head);
    Node_L* sortList_name(Node_L* head);
    //链表反转
    Node_L* listReverse(Node_L *pHead);

    //插入
    void Add();

    Node_L * getHead();
    int getLen();
    int getGroupNum();
    QString getBookName();
    bool Save();

    bool addGroup(QString groupName);

    QStringList group;
    int len;
private:
    List head;

    int groupNum;
    QString BookName;
};

class AddressBTree      //平衡二叉树
{
public:
    AddressBTree();
    //左旋右旋
    void L_Rotate(BSTree &root);
    void R_Rotate(BSTree &root);
    //左平衡右平衡
    void L_Balance(BSTree &root);
    void R_Balance(BSTree &root);
    //插入节点
    bool insert(BSTree &root, Data data, bool &taller, int type);
    //查找操作
    BSTree find(BSTree &root, int type, QString data, int &cnt);

    BSTree & getNameRoot();
    BSTree & getEmailRoot();

private:
    //平衡二叉树根节点
    BSTree root_name;
    BSTree root_email;

    //平均查找长度
    int ASL_name;
    int ASL_email;
};

#endif // ADDRESS_H
