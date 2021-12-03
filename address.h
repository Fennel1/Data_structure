#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

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
}*BTree, Node_BT;

class AddressList       //链表
{
public:
    AddressList();
    void init();
    void sort(int type, int basis);
    void add_node(Data data);
    void delete_node(Data data);

private:
    List head;
    int len;
};

class AddressBTree      //平衡二叉树
{
public:
    AddressBTree();
    void init();
    void find(int basis);

private:
    BTree root_name;
    BTree root_phone;
};

#endif // ADDRESS_H
