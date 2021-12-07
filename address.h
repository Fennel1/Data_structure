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
    void sort(int type, int basis);
    void init(QString filename);
    //添加删除节点
    void add_node(Data data);
    void delete_node(Data data);

    Node_L * getHead();
    int getLen();

private:
    List head;
    int len;
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
