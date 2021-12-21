#include "address.h"

/*
链表函数
*/
AddressList::AddressList()
{
    head = new Node_L;
    head->next = nullptr;
    len = 0;
    groupNum = 0;
}

void AddressList::init(QString filename)
{
    QFile file("../addressbook/" + filename + ".txt");
    if (file.exists())  qDebug() << "file exists" << endl;
    else    qDebug() << "file not exists" << endl;

    if (file.open(QIODevice::ReadOnly)) qDebug() << "file open" << endl;
    else{
        qDebug() << "file open fail" << endl;
        return;
    }

    BookName = filename;

    QTextStream txt(&file);
    QString line=txt.readLine();
    QStringList strlist=line.split(",");

    head = new Node_L;
    Node_L *p=head;
    head->next = nullptr;

    if (strlist.size() < 3) return;
    BookName = strlist[0];
    len = strlist[1].toInt();
    groupNum = strlist[2].toInt();
    qDebug() << strlist<< endl;

    line=txt.readLine();
    group = line.split(",");
    qDebug() << group << endl;

    for (int i=0; i<len; i++)
    {
        QString line=txt.readLine();
        QStringList strlist=line.split(",");
        Node_L *temp = new Node_L;
        temp->data.phone = strlist[0];
        temp->data.name = strlist[1];
        temp->data.email = strlist[2];
        temp->data.address = strlist[3];
        temp->data.remark = strlist[4];
        temp->data.groupIndex = strlist[5].toInt();

        p->next = temp;
        p = p->next;
        temp->next = nullptr;
    }

    file.close();
}

Node_L * AddressList::getHead()
{
    return head;
}

int AddressList::getLen()
{
    return len;
}

int AddressList::getGroupNum()
{
    return groupNum;
}

QString AddressList::getBookName()
{
    return BookName;
}

bool AddressList::addGroup(QString groupName)
{
    for (int i=0; i<groupNum; i++){
        if (group[i] == groupName)  return false;
    }

    groupNum++;
    group.append(groupName);
    return true;
}

void AddressList::AddressList_sort(int type, int basis)
{
    //手机号排序
    if(basis==1)
    {
        head=sortList(head);
        //升序
        if(type==1)
        {
            return ;
        }
        //降序
        else
        {
            head->next=listReverse(head->next);
        }
    }
    //姓名排序
    else
    {
        head=sortList_name(head);
        //升序
        if(type==1)
        {
            return ;
        }
        //降序
        else
        {
            head->next=listReverse(head->next);
            return ;
        }
    }
}
//手机号
Node_L* AddressList::merge(Node_L *left, Node_L *right){
    auto head = new Node_L;
    auto h = head;
    while(left && right){
        if(left->data.phone < right->data.phone){
            h->next = left;
            left = left->next;
        }else{
            h->next = right;
            right = right->next;
        }
        h = h->next;
    }
    h->next = left == NULL ? right : left;
    return head->next;
}
Node_L* AddressList::merge_sort(Node_L *head){
    if(!head->next) return head;
    Node_L *slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    auto r_head = slow->next;//slow->next右边部分的头结点
    slow->next = NULL;//左边切断开
    auto left = merge_sort(head);
    auto right = merge_sort(r_head);
    return merge(left, right);
}
Node_L* AddressList::sortList(Node_L* head) {
    if (!head || !head->next) return head;
    return merge_sort(head);
}
//姓名
Node_L* AddressList::merge_name(Node_L *left, Node_L *right){
    auto head = new Node_L;
    auto h = head;
    while(left && right){
        if(left->data.name < right->data.name){
            h->next = left;
            left = left->next;
        }else{
            h->next = right;
            right = right->next;
        }
        h = h->next;
    }
    h->next = left == NULL ? right : left;
    return head->next;
}
Node_L* AddressList::merge_sort_name(Node_L *head){
    if(!head->next) return head;
    Node_L *slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    auto r_head = slow->next;//slow->next右边部分的头结点
    slow->next = NULL;//左边切断开
    auto left = merge_sort_name(head);
    auto right = merge_sort_name(r_head);
    return merge_name(left, right);
}
Node_L* AddressList::sortList_name(Node_L* head) {
    if (!head || !head->next) return head;
    return merge_sort_name(head);
}
Node_L* AddressList::listReverse(Node_L* head) {
       Node_L* prev = nullptr;
       Node_L* curr = head;
       while (curr) {
           Node_L* next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
       }
       return prev;
}

void AddressList::quick_sort()
{
    int list[len], i=0;
    Node_L *p = head->next;
    while (p){
        list[i++] = p->data.phone.toInt();
        p = p->next;
    }

    qsort(list, 0, len-1);
    p = head->next;
    while (p){
        p->data.phone = QString::number(list[i++]);
        p = p->next;
    }
}

void AddressList::qsort(int *list, int low, int high)
{
    int i=low, j=high;
    if (low > high)     return;

    int temp = list[low];
    while (low < high){
        while (list[high] >= list[0] && low < high) high--;
        list[low] = list[high];

        while(list[low] <= list[0] && low < high)   low++;
        list[high] = list[low];
    }

    list[low] = temp;
    qsort(list, i, low-1);
    qsort(list, low+1, j);
}

void AddressList::Add()
{
    Node_L* nptr;
    nptr=new Node_L;
    nptr->data.name="unkonwn";
    nptr->data.email="un@known.com";
    nptr->data.phone="unknown";
    nptr->data.remark="unknown";
    nptr->data.address="unknown";
    nptr->data.groupIndex=0;
    nptr->next=nullptr;
    len++;
    if(head == nullptr)
    {
        head = nptr;
    }
    else
    {
        Node_L* pNode = head;
        while(pNode->next != nullptr)
            pNode = pNode->next;
        pNode->next = nptr;
    }
}

bool AddressList::Save()
{
    QFile file("../addressbook/" + BookName + ".txt");
    if (file.exists())  qDebug() << "file exists" << endl;
    else    qDebug() << "file not exists" << endl;

    if (file.open(QIODevice::WriteOnly)) qDebug() << "file open" << endl;
    else{
        qDebug() << "file open fail" << endl;
        return false;
    }

    QTextStream txt(&file);
    txt << BookName << ',' << len << ',' << groupNum << endl;
    txt << group[0];
    for (int i=1; i<groupNum; i++){
        txt << ',' << group[i];
    }
    txt << endl;
    Node_L *p=head->next;
    while(p){
        txt << p->data.phone << ',' << p->data.name << ',' << p->data.email << ',' << p->data.address << ',' << p->data.remark << ',' << p->data.groupIndex << endl;
        p = p->next;
    }

    file.close();
    return true;
}

/*
平衡二叉树函数
*/
AddressBTree::AddressBTree()
{
    root_name = nullptr;
    root_email = nullptr;
}

void AddressBTree::R_Rotate(BSTree &root)
{
    Node_BST *lc = root->lchild;
    root->lchild = lc->rchild;
    lc->rchild = root;
    root = lc;
}

void AddressBTree::L_Rotate(BSTree &root)
{
    Node_BST *rc = root->rchild;
    root->rchild = rc->lchild;
    rc->lchild = root;
    root = rc;
}

void AddressBTree::L_Balance(BSTree &root)
{
    Node_BST *lc = root->lchild;
    switch (lc->bf) {
        case 1:
            root->bf = lc->bf = 0;
            R_Rotate(root);
            break;
        case -1:
            Node_BST *rd = lc->rchild;
            switch (rd->bf) {
                case 1: root->bf = -1; lc->bf = 0; break;
                case 0: root->bf = lc->bf = 0; break;
                case -1: root->bf = 0; lc->bf = 1; break;
            }
            rd->bf = 0;
            L_Rotate(root->lchild);
            R_Rotate(root);
    }
}

void AddressBTree::R_Balance(BSTree &root)
{
    Node_BST *rc = root->rchild;
    switch (rc->bf) {
        case -1:
            root->bf = rc->bf = 0;
            L_Rotate(root);
            break;
        case 1:
            Node_BST *ld = rc->lchild;
            switch (ld->bf) {
                case 1: root->bf = 0; rc->bf = -1; break;
                case 0: root->bf = rc->bf = 0; break;
                case -1: root->bf = 1; rc->bf = 0; break;
            }
            ld->bf = 0;
            R_Rotate(root->rchild);
            L_Rotate(root);
    }
}

bool AddressBTree::insert(BSTree &root, Data data, bool &taller, int type)
{
    if (type == 1){
        if (!root){
            root = new Node_BST;
            root->data = data;
            root->lchild = root->rchild = nullptr;
            root->bf = 0;
            taller = true;
        }
        else {
            if (root->data.name == data.name){
                taller = false;
                return false;
            }
            else if (data.name < root->data.name){
                if (!insert(root->lchild, data, taller, type))    return false;
                if (taller){
                    switch (root->bf) {
                        case 1:
                            L_Balance(root);
                            taller = false;
                        break;
                        case 0:
                            root->bf = 1;
                            taller = true;
                        break;
                        case -1:
                            root->bf = 0;
                            taller = false;
                        break;
                    }
                }
            }
            else{
                if (!insert(root->rchild, data, taller, type))    return false;
                if (taller){
                    switch (root->bf) {
                        case 1:
                            root->bf = 0;
                            taller = false;
                        break;
                        case 0:
                            root->bf = -1;
                            taller = true;
                        break;
                        case -1:
                            R_Balance(root);
                            taller = false;
                        break;
                    }
                }
            }
        }
    }
    else if (type == 2){
        if (!root){
            root = new Node_BST;
            root->data = data;
            root->lchild = root->rchild = nullptr;
            root->bf = 0;
            taller = true;
        }
        else {
            if (root->data.email == data.email){
                taller = false;
                return false;
            }
            else if (data.email < root->data.email){
                if (!insert(root->lchild, data, taller, type))    return false;
                if (taller){
                    switch (root->bf) {
                        case 1:
                            L_Balance(root);
                            taller = false;
                        break;
                        case 0:
                            root->bf = 1;
                            taller = true;
                        break;
                        case -1:
                            root->bf = 0;
                            taller = false;
                        break;
                    }
                }
            }
            else{
                if (!insert(root->rchild, data, taller, type))    return false;
                if (taller){
                    switch (root->bf) {
                        case 1:
                            root->bf = 0;
                            taller = false;
                        break;
                        case 0:
                            root->bf = -1;
                            taller = true;
                        break;
                        case -1:
                            R_Balance(root);
                            taller = false;
                        break;
                    }
                }
            }
        }
    }
    return true;
}

BSTree AddressBTree::find(BSTree &root, int type, QString data, int &cnt)
{
    if (!root)  return nullptr;
    if (type == 1)  //按名称查找
    {
        cnt++;
        if (data == root->data.name) return root;
        else if (data < root->data.name)    return find(root->lchild, type, data, cnt);
        else    return find(root->rchild, type, data, cnt);

    }
    else    //按邮箱查找
    {
        cnt++;
        if (data == root->data.email) return root;
        else if (data < root->data.email)    return find(root->lchild, type, data, cnt);
        else    return find(root->rchild, type, data, cnt);
    }
}

BSTree & AddressBTree::getNameRoot()
{
    return root_name;
}

BSTree & AddressBTree::getEmailRoot()
{
    return root_email;
}
