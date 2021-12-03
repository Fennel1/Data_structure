#include "address.h"

/*
链表函数
*/
AddressList::AddressList()
{
    head = new Node_L;
    head->next = nullptr;
}

/*
平衡二叉树函数
*/
AddressBTree::AddressBTree()
{
    root_name = new Node_BT;
    root_name->lchild = root_name->rchild = nullptr;
    root_phone = new Node_BT;
    root_phone->lchild = root_phone->rchild = nullptr;
}

