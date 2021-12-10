#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_openadress.h"
#include "ui_openartical.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), openad(new OpenAdress), openartical(new OpenArtical)
{
    ui->setupUi(this);

    type = basis = 0;

    //设置文本框仅读
    ui->Text_MemberInfo->setReadOnly(true);
    ui->Text_OverallInfo->setReadOnly(true);
    ui->Text_ArticleShow->setReadOnly(true);
    ui->Text_HashDiffInfo->setReadOnly(true);
    ui->Text_HashInfo->setReadOnly(true);
    ui->Text_ArticalInfo->setReadOnly(true);

    //界面默认按钮
    ui->PB_AllAdress->hide();
    ui->PB_GroupAdress->hide();
    ui->PB_QueryAdress->hide();
    ui->PB_TextInfo->hide();
    ui->PB_DiffHashfun->hide();
    ui->PB_DiffConflict->hide();

    //通讯录-全部-控件
    ui->PB_OpenAdressBook->hide();
    ui->List_AddressBook->hide();
    ui->Text_MemberInfo->hide();
    ui->Text_OverallInfo->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();
    ui->PB_SortName->hide();
    ui->PB_SortPhone->hide();
    ui->PB_SortUp->hide();
    ui->PB_SortDown->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();

    //哈希表-统计-控件
    ui->Text_ArticleShow->hide();
    ui->Text_ArticalInfo->hide();
    ui->List_WordInfo->hide();
    ui->PB_OpenArtical->hide();

    //哈希表-函数-控件
    ui->PB_HashLinear->hide();
    ui->PB_HashQsr->hide();
    ui->PB_HashRandom->hide();
    ui->PB_HashLink->hide();
    ui->PB_HashNewRule->hide();
    ui->List_HashFun->hide();
    ui->Text_HashInfo->hide();
    ui->List_HashFunCompare->hide();

    //哈希表-冲突-控件
    ui->PB_DiffSqr->hide();
    ui->PB_DiffMod->hide();
    ui->PB_DiffRandom->hide();
    ui->List_HashDiff->hide();
    ui->List_HashDiffCompare->hide();
    ui->Text_HashDiffInfo->hide();

    //按钮连接
    connect(ui->PB_AddressList, SIGNAL(clicked()), this, SLOT(Press_AdressList()));
    connect(ui->PB_Text, SIGNAL(clicked()), this, SLOT(Press_Text()));
    connect(ui->PB_AllAdress, SIGNAL(clicked()), this, SLOT(Press_AllAdress()));
    connect(ui->PB_GroupAdress, SIGNAL(clicked()), this, SLOT(Press_GroupAdress()));
    connect(ui->PB_QueryAdress, SIGNAL(clicked()), this, SLOT(Press_QueryAdress()));
    connect(ui->PB_TextInfo, SIGNAL(clicked()), this, SLOT(Press_TextInfo()));
    connect(ui->PB_DiffHashfun, SIGNAL(clicked()), this, SLOT(Press_DiffHashfun()));
    connect(ui->PB_DiffConflict, SIGNAL(clicked()), this, SLOT(Press_DiffConflict()));

    connect(ui->List_AddressBook, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Press_AdressBook(QListWidgetItem*)));

    connect(ui->PB_OpenAdressBook, SIGNAL(clicked()), this, SLOT(Press_OpenAddressBook()));
    connect(ui->PB_AddMember, SIGNAL(clicked()), this, SLOT(Press_AddMember()));
    connect(ui->PB_DeleteMember, SIGNAL(clicked()), this, SLOT(Press_DeleteMember()));
    connect(ui->PB_ChangeMember, SIGNAL(clicked()), this, SLOT(Press_ChangeMember()));
    connect(ui->PB_SortName, SIGNAL(clicked()), this, SLOT(Press_SortName()));
    connect(ui->PB_SortPhone, SIGNAL(clicked()), this, SLOT(Press_SortPhone()));
    connect(ui->PB_SortUp, SIGNAL(clicked()), this, SLOT(Press_SortUp()));
    connect(ui->PB_SortDown, SIGNAL(clicked()), this, SLOT(Press_SortDown()));

    connect(ui->PB_CreateGroup, SIGNAL(clicked()), this, SLOT(Press_CreateGroup()));
    connect(ui->PB_ManageGroup, SIGNAL(clicked()), this, SLOT(Press_ManageGroup()));
    connect(ui->Input_CreateGroup, SIGNAL(returnPressed()), this, SLOT(Input_CreateGroup()));
    connect(ui->List_MemberInGroup, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Press_MemberInGroup(QListWidgetItem*)));

    connect(ui->PB_QueryMember, SIGNAL(clicked()), this, SLOT(Press_QueryMember()));
    connect(ui->Input_QueryMember, SIGNAL(returnPressed()), this, SLOT(Input_QueryMember()));
    connect(ui->PB_QueryInfo, SIGNAL(clicked()), this, SLOT(Press_QueryInfo()));

    connect(openad->ui->List_AddressList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Press_AdressFilename(QListWidgetItem*)));

    connect(ui->PB_OpenArtical, SIGNAL(clicked()), this, SLOT(Press_OpenArtical()));
    connect(openartical->ui->List_Artical, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Press_ArticalFileName(QListWidgetItem*)));

    connect(ui->PB_HashLinear, SIGNAL(clicked()), this, SLOT(Press_HashLinear()));
    connect(ui->PB_HashQsr, SIGNAL(clicked()), this, SLOT(Press_HashQsr()));
    connect(ui->PB_HashRandom, SIGNAL(clicked()), this, SLOT(Press_HashRandom()));
    connect(ui->PB_HashLink, SIGNAL(clicked()), this, SLOT(Press_HashLink()));
    connect(ui->PB_HashNewRule, SIGNAL(clicked()), this, SLOT(Press_HashNewRule()));

    connect(ui->PB_DiffSqr, SIGNAL(clicked()), this, SLOT(Press_DiffSqr()));
    connect(ui->PB_DiffMod, SIGNAL(clicked()), this, SLOT(Press_DiffMod()));
    connect(ui->PB_DiffRandom, SIGNAL(clicked()), this, SLOT(Press_DiffRandom()));
}
void MainWindow::Press_AdressList()
{
    //界面默认按钮
    ui->PB_AllAdress->show();
    ui->PB_GroupAdress->show();
    ui->PB_QueryAdress->show();
    ui->PB_TextInfo->hide();
    ui->PB_DiffHashfun->hide();
    ui->PB_DiffConflict->hide();

    //通讯录-全部-控件
    ui->PB_OpenAdressBook->show();
    ui->List_AddressBook->show();
    ui->Text_MemberInfo->show();
    ui->Text_OverallInfo->show();
    ui->PB_AddMember->show();
    ui->PB_DeleteMember->show();
    ui->PB_ChangeMember->show();
    ui->PB_SortName->show();
    ui->PB_SortPhone->show();
    ui->PB_SortUp->show();
    ui->PB_SortDown->show();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();

    //哈希表-统计-控件
    ui->Text_ArticleShow->hide();
    ui->Text_ArticalInfo->hide();
    ui->List_WordInfo->hide();
    ui->PB_OpenArtical->hide();

    //哈希表-函数-控件
    ui->PB_HashLinear->hide();
    ui->PB_HashQsr->hide();
    ui->PB_HashRandom->hide();
    ui->PB_HashLink->hide();
    ui->PB_HashNewRule->hide();
    ui->List_HashFun->hide();
    ui->Text_HashInfo->hide();
    ui->List_HashFunCompare->hide();

    //哈希表-冲突-控件
    ui->PB_DiffSqr->hide();
    ui->PB_DiffMod->hide();
    ui->PB_DiffRandom->hide();
    ui->List_HashDiff->hide();
    ui->List_HashDiffCompare->hide();
    ui->Text_HashDiffInfo->hide();
}

void MainWindow::Press_Text()
{
    //界面默认按钮
    ui->PB_TextInfo->show();
    ui->PB_DiffHashfun->show();
    ui->PB_DiffConflict->show();
    ui->PB_AllAdress->hide();
    ui->PB_GroupAdress->hide();
    ui->PB_QueryAdress->hide();

    //通讯录-全部-控件
    ui->PB_OpenAdressBook->hide();
    ui->List_AddressBook->hide();
    ui->Text_MemberInfo->hide();
    ui->Text_OverallInfo->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();
    ui->PB_SortName->hide();
    ui->PB_SortPhone->hide();
    ui->PB_SortUp->hide();
    ui->PB_SortDown->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();

    //哈希表-统计-控件
    ui->Text_ArticleShow->show();
    ui->Text_ArticalInfo->show();
    ui->List_WordInfo->show();
    ui->PB_OpenArtical->show();

    //哈希表-函数-控件
    ui->PB_HashLinear->hide();
    ui->PB_HashQsr->hide();
    ui->PB_HashRandom->hide();
    ui->PB_HashLink->hide();
    ui->PB_HashNewRule->hide();
    ui->List_HashFun->hide();
    ui->Text_HashInfo->hide();
    ui->List_HashFunCompare->hide();

    //哈希表-冲突-控件
    ui->PB_DiffSqr->hide();
    ui->PB_DiffMod->hide();
    ui->PB_DiffRandom->hide();
    ui->List_HashDiff->hide();
    ui->List_HashDiffCompare->hide();
    ui->Text_HashDiffInfo->hide();
}

void MainWindow::Press_AllAdress()
{
    //通讯录-全部-控件
    ui->PB_OpenAdressBook->show();
    ui->PB_AddMember->show();
    ui->PB_DeleteMember->show();
    ui->PB_ChangeMember->show();
    ui->PB_SortName->show();
    ui->PB_SortPhone->show();
    ui->PB_SortUp->show();
    ui->PB_SortDown->show();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();

    Set_LinkList();
}

void MainWindow::Press_GroupAdress()
{
    //通讯录-全部-控件
    ui->PB_OpenAdressBook->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();
    ui->PB_SortName->hide();
    ui->PB_SortPhone->hide();
    ui->PB_SortUp->hide();
    ui->PB_SortDown->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->show();
    ui->PB_ManageGroup->show();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->hide();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->hide();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();

    //设置列表
    ui->List_AddressBook->clear();
    for (int i=0; i<addresslinklist.getGroupNum(); i++){
        QString str = addresslinklist.group[i];
        ui->List_AddressBook->addItem(str);
    }
}

void MainWindow::Press_QueryAdress()
{
    //通讯录-全部-控件
    ui->PB_OpenAdressBook->hide();
    ui->PB_AddMember->hide();
    ui->PB_DeleteMember->hide();
    ui->PB_ChangeMember->hide();
    ui->PB_SortName->hide();
    ui->PB_SortPhone->hide();
    ui->PB_SortUp->hide();
    ui->PB_SortDown->hide();

    //通讯录-分组-控件
    ui->PB_CreateGroup->hide();
    ui->PB_ManageGroup->hide();
    ui->Input_CreateGroup->hide();
    ui->List_MemberInGroup->hide();

    //通讯录-查询-控件
    ui->PB_QueryMember->show();
    ui->Input_QueryMember->hide();
    ui->PB_QueryInfo->show();
    ui->Text_OverallInfo->clear();
    ui->Text_MemberInfo->clear();

    //创建平衡二叉树
    Node_L *p = addresslinklist.getHead();
    p = p->next;

    while (p){
        bool nametaller=false, phonetaller=false;
        addressBTree.insert(addressBTree.getNameRoot(), p->data, nametaller, 1);
        addressBTree.insert(addressBTree.getEmailRoot(), p->data, phonetaller, 2);
        p = p->next;
    }

    Set_LinkList();
}

void MainWindow::Press_TextInfo()
{
    //哈希表-统计-控件
    ui->Text_ArticleShow->show();
    ui->Text_ArticalInfo->show();
    ui->List_WordInfo->show();
    ui->PB_OpenArtical->show();

    //哈希表-函数-控件
    ui->PB_HashLinear->hide();
    ui->PB_HashQsr->hide();
    ui->PB_HashRandom->hide();
    ui->PB_HashLink->hide();
    ui->PB_HashNewRule->hide();
    ui->List_HashFun->hide();
    ui->Text_HashInfo->hide();
    ui->List_HashFunCompare->hide();

    //哈希表-冲突-控件
    ui->PB_DiffSqr->hide();
    ui->PB_DiffMod->hide();
    ui->PB_DiffRandom->hide();
    ui->List_HashDiff->hide();
    ui->List_HashDiffCompare->hide();
    ui->Text_HashDiffInfo->hide();
}

void MainWindow::Press_DiffHashfun()
{
    //哈希表-统计-控件
    ui->Text_ArticleShow->hide();
    ui->Text_ArticalInfo->hide();
    ui->List_WordInfo->hide();
    ui->PB_OpenArtical->hide();

    //哈希表-函数-控件
    ui->PB_HashLinear->show();
    ui->PB_HashQsr->show();
    ui->PB_HashRandom->show();
    ui->PB_HashLink->show();
    ui->PB_HashNewRule->show();
    ui->List_HashFun->show();
    ui->Text_HashInfo->show();
    ui->List_HashFunCompare->show();

    //哈希表-冲突-控件
    ui->PB_DiffSqr->hide();
    ui->PB_DiffMod->hide();
    ui->PB_DiffRandom->hide();
    ui->List_HashDiff->hide();
    ui->List_HashDiffCompare->hide();
    ui->Text_HashDiffInfo->hide();
}

void MainWindow::Press_DiffConflict()
{
    //哈希表-统计-控件
    ui->Text_ArticleShow->hide();
    ui->Text_ArticalInfo->hide();
    ui->List_WordInfo->hide();
    ui->PB_OpenArtical->hide();

    //哈希表-函数-控件
    ui->PB_HashLinear->hide();
    ui->PB_HashQsr->hide();
    ui->PB_HashRandom->hide();
    ui->PB_HashLink->hide();
    ui->PB_HashNewRule->show();
    ui->List_HashFun->hide();
    ui->Text_HashInfo->hide();
    ui->List_HashFunCompare->hide();

    //哈希表-冲突-控件
    ui->PB_DiffSqr->show();
    ui->PB_DiffMod->show();
    ui->PB_DiffRandom->show();
    ui->List_HashDiff->show();
    ui->List_HashDiffCompare->show();
    ui->Text_HashDiffInfo->show();
}

void MainWindow::Press_OpenArtical()
{
    openartical->show();
    openartical->set_List();
}

bool cmp(pair<QString, int> a, pair<QString, int> b)
{
    return a.second > b.second;
}

void MainWindow::Press_ArticalFileName(QListWidgetItem* item)
{
    ui->Text_ArticleShow->clear();
    ui->List_WordInfo->clear();
    ui->Text_ArticalInfo->clear();
    QFile file("D:\\GitHub\\qtpro\\text\\" + item->text() + ".txt");
    if (file.exists())  qDebug() << "file exists" << endl;
    else    qDebug() << "file not exists" << endl;

    if (file.open(QIODevice::ReadOnly)) qDebug() << "file open" << endl;
    else{
        qDebug() << "file open fail" << endl;
        return;
    }

    article.clear();

    QTextStream txt(&file);
    QString line=txt.readLine();
    while(!line.isNull()){
        ui->Text_ArticleShow->append(line);
        line.replace(',', " ");
        line.replace('.', " ");
        line.replace(QRegExp("[\\s]+"), " ");
        line = line.toLower();
        line = line.trimmed();
        article.append(line);
        line=txt.readLine();
    }

    file.close();
    hashMap.clear_hashmap();

    for (int i=0; i<article.size(); i++){
        QStringList words=article[i].split(" ");
        for (int j=0; j<words.size(); j++){
            hashMap.stlMap[words[j]]++;
        }
    }

    int sum=0;
    vector<pair<QString, int>> numToWord(hashMap.stlMap.begin(), hashMap.stlMap.end());
    sort(numToWord.begin(), numToWord.end(), cmp);
    for (int i=0; i<numToWord.size(); i++){
        ui->List_WordInfo->addItem(numToWord[i].first + '\t' + QString::number(numToWord[i].second));
        sum += numToWord[i].second;
    }
    ui->Text_ArticalInfo->append("文章名称：" + item->text());
    ui->Text_ArticalInfo->append("文章段落数量：" + QString::number(article.size()) + "段");
    ui->Text_ArticalInfo->append("文章单词数量：" + QString::number(sum) + "个");
    ui->Text_ArticalInfo->append("文章不重复单词数量：" + QString::number(numToWord.size()) + "个");
    ui->Text_ArticalInfo->append("\n高频词汇前三位：");
    ui->Text_ArticalInfo->append("单词：" + numToWord[0].first + "\t\t" + "频数：" + QString::number(numToWord[0].second));
    ui->Text_ArticalInfo->append("单词：" + numToWord[1].first + "\t\t" + "频数：" + QString::number(numToWord[1].second));
    ui->Text_ArticalInfo->append("单词：" + numToWord[2].first + "\t\t" + "频数：" + QString::number(numToWord[2].second));
    openartical->hide();
}

void MainWindow::Press_OpenAddressBook()
{
    openad->show();
    openad->set_List();
}

void MainWindow::Press_AddMember()
{
    addresslinklist.Add();
    Set_LinkList();
}

void MainWindow::Press_DeleteMember()
{

}

void MainWindow::Press_ChangeMember()
{

}

void MainWindow::Press_CreateGroup()
{
    ui->Input_CreateGroup->clear();
    ui->Input_CreateGroup->show();
    ui->Input_CreateGroup->setPlaceholderText("请在此处输入新分组的名称：");
    ui->List_MemberInGroup->hide();
}

void MainWindow::Input_CreateGroup()
{
    ui->Input_CreateGroup->hide();
    ui->Text_OverallInfo->clear();

    addresslinklist.addGroup(ui->Input_CreateGroup->text());
}

void MainWindow::Press_ManageGroup()
{
    ui->List_MemberInGroup->show();
    ui->Input_CreateGroup->hide();

    ui->Text_OverallInfo->clear();
    ui->Text_OverallInfo->append("该分组内成员：");
}

void MainWindow::Press_MemberInGroup(QListWidgetItem* item)
{
    qDebug() << item->text() << endl;
}

void MainWindow::Press_QueryMember()
{
    //设置查询输入框
    ui->Input_QueryMember->clear();
    ui->Input_QueryMember->show();
    ui->Input_QueryMember->setPlaceholderText("请在输入查询内容：（按姓名查找1-；按邮箱查找2-）");
}

void MainWindow::Input_QueryMember()
{
    //查找输入内容
    ui->Text_MemberInfo->clear();
    ui->Input_QueryMember->hide();

    QString order = ui->Input_QueryMember->text();
    order = order.trimmed();

    qDebug() << order << endl;

    BSTree p=nullptr;
    int cnt;
    if (order[0] == '1')    p = addressBTree.find(addressBTree.getNameRoot(), 1, order.right(order.size()-2), cnt);
    else if (order[0] == '2')    p = addressBTree.find(addressBTree.getEmailRoot(), 0, order.right(order.size()-2), cnt);
    else    return;

    if (p){
        ui->Text_MemberInfo->append("姓名：" + p->data.name);
        ui->Text_MemberInfo->append("电话号码：" + p->data.phone);
        ui->Text_MemberInfo->append("电子邮箱：" + p->data.email);
        ui->Text_MemberInfo->append("地址：" + p->data.address);
        ui->Text_MemberInfo->append("备注：" + p->data.remark);
        ui->Text_MemberInfo->append("分组：" + addresslinklist.group[p->data.groupIndex]);
    }
}

void MainWindow::Press_QueryInfo()
{
    //计算查找信息
    double sum_name=0, sum_email=0;

    Node_L *p=addresslinklist.getHead();
    p = p->next;

    while (p)
    {
        int cnt_name=0, cnt_email=0;
        addressBTree.find(addressBTree.getNameRoot(), 1, p->data.name, cnt_name);
        addressBTree.find(addressBTree.getEmailRoot(), 1, p->data.email, cnt_email);
        sum_name += cnt_name;
        sum_email += cnt_email;
        p = p->next;
    }

    ui->Text_OverallInfo->clear();
    ui->Text_OverallInfo->append("\n用户数：" + QString::number(addresslinklist.getLen()) + "条");
    ui->Text_OverallInfo->append("ASL（平均查找次数）：");
    ui->Text_OverallInfo->append("\n\t\t\t按姓名查找：" + QString::number(sum_name/addresslinklist.getLen()) + "次");
    ui->Text_OverallInfo->append("\n\t\t\t按邮箱查找：" + QString::number(sum_email/addresslinklist.getLen()) + "次");

    qDebug() << sum_name << sum_email << endl;
}

void MainWindow::Press_SortName()
{
    type=1,basis=0;
    addresslinklist.AddressList_sort(type,basis);
    Set_LinkList();
}

void MainWindow::Press_SortPhone()
{
    type=1,basis=1;
    addresslinklist.AddressList_sort(type,basis);
    Set_LinkList();
}

void MainWindow::Press_SortUp()
{
    type=1;
    addresslinklist.AddressList_sort(type,basis);
    Set_LinkList();
}

void MainWindow::Press_SortDown()
{
    type=0;
    addresslinklist.AddressList_sort(type,basis);
    Set_LinkList();
}

void MainWindow::Press_AdressBook(QListWidgetItem* item)
{
    ui->Text_MemberInfo->clear();

    qDebug() << item->text() << endl;
    QStringList strlist=item->text().split("\t");
    if (item->text().contains('@')){    //处理全部界面
        QString str=strlist[1];

        Node_L *p=addresslinklist.getHead();
        p = p->next;
        while (p && p->data.email!=str) p=p->next;

        ui->Text_MemberInfo->append("姓名：" + p->data.name);
        ui->Text_MemberInfo->append("电话号码：" + p->data.phone);
        ui->Text_MemberInfo->append("电子邮箱：" + p->data.email);
        ui->Text_MemberInfo->append("地址：" + p->data.address);
        ui->Text_MemberInfo->append("备注：" + p->data.remark);
        ui->Text_MemberInfo->append("分组：" + addresslinklist.group[p->data.groupIndex]);
    }
    else if (strlist.size() > 1){       //处理分组界面-用户部分

    }
    else {      //处理分组界面-分组部分
        QString groupname=strlist[0];
        ui->Text_MemberInfo->append("分组名称：" + groupname);
    }
}

void MainWindow::Press_AdressFilename(QListWidgetItem* item)
{
    qDebug() << item->text() << endl;

    addresslinklist.init(item->text());

    Set_LinkList();

    openad->hide();
}

void MainWindow::Set_LinkList()
{
    ui->List_AddressBook->clear();

    Node_L *p=addresslinklist.getHead();
    p = p->next;

    while (p)
    {
        QString thistext=p->data.name + "\t" + p->data.email;
        ui->List_AddressBook->addItem(thistext);
        p = p->next;
    }
}

void MainWindow::Press_HashLinear()
{
    ui->List_HashFun->clear();

    int sum[3]={0};
    double wordNum=0;

    for (int k=0; k<3; k++){
        hashMap.resetHashArray();
        for (int i=0; i<article.size(); i++){
            QStringList words=article[i].split(" ");
            for (int j=0; j<words.size(); j++){
                sum[k] += hashMap.insert(words[j], k, 1);
                wordNum++;
            }
        }

        if (k == 0) ui->List_HashFun->addItem("平方取中法");
        else if (k == 1) ui->List_HashFun->addItem("除留余数法");
        else    ui->List_HashFun->addItem("随机数法");
    }

    qDebug() << sum[0] << sum[1] << sum[2] << wordNum/3 << endl;

    ui->List_HashFunCompare->clear();
    ui->List_HashFunCompare->addItem("平方取中法：" + QString::number(sum[0]/wordNum*3));
    ui->List_HashFunCompare->addItem("除留余数法：" + QString::number(sum[1]/wordNum*3));
    ui->List_HashFunCompare->addItem("随机数法：" + QString::number(sum[2]/wordNum*3));
}

void MainWindow::Press_HashQsr()
{
    ui->List_HashFun->clear();

    int sum[3]={0};
    double wordNum=0;

    for (int k=0; k<3; k++){
        hashMap.resetHashArray();
        for (int i=0; i<article.size(); i++){
            QStringList words=article[i].split(" ");
            for (int j=0; j<words.size(); j++){
                sum[k] += hashMap.insert(words[j], k, 2);
                wordNum++;
            }
        }

        if (k == 0) ui->List_HashFun->addItem("平方取中法");
        else if (k == 1) ui->List_HashFun->addItem("除留余数法");
        else    ui->List_HashFun->addItem("随机数法");
    }

    qDebug() << sum[0] << sum[1] << sum[2] << wordNum/3 << endl;

    ui->List_HashFunCompare->clear();
    ui->List_HashFunCompare->addItem("平方取中法：" + QString::number(sum[0]/wordNum*3));
    ui->List_HashFunCompare->addItem("除留余数法：" + QString::number(sum[1]/wordNum*3));
    ui->List_HashFunCompare->addItem("随机数法：" + QString::number(sum[2]/wordNum*3));
}

void MainWindow::Press_HashRandom()
{
    ui->List_HashFun->clear();

    int sum[3]={0};
    double wordNum=0;

    for (int k=0; k<3; k++){
        hashMap.resetHashArray();
        for (int i=0; i<article.size(); i++){
            QStringList words=article[i].split(" ");
            for (int j=0; j<words.size(); j++){
                sum[k] += hashMap.insert(words[j], k, 3);
                wordNum++;
            }
        }

        if (k == 0) ui->List_HashFun->addItem("平方取中法");
        else if (k == 1) ui->List_HashFun->addItem("除留余数法");
        else    ui->List_HashFun->addItem("随机数法");
    }

    qDebug() << sum[0] << sum[1] << sum[2] << wordNum/3 << endl;

    ui->List_HashFunCompare->clear();
    ui->List_HashFunCompare->addItem("平方取中法：" + QString::number(sum[0]/wordNum*3));
    ui->List_HashFunCompare->addItem("除留余数法：" + QString::number(sum[1]/wordNum*3));
    ui->List_HashFunCompare->addItem("随机数法：" + QString::number(sum[2]/wordNum*3));
}

void MainWindow::Press_HashLink()
{
    ui->List_HashFun->clear();

    int sum[3]={0};
    double wordNum=0;

    for (int k=0; k<3; k++){
        hashMap.resetHashLink();
        for (int i=0; i<article.size(); i++){
            QStringList words=article[i].split(" ");
            for (int j=0; j<words.size(); j++){
                sum[k] += hashMap.insert(words[j], k, 0);
                wordNum++;
            }
        }

        if (k == 0) ui->List_HashFun->addItem("平方取中法");
        else if (k == 1) ui->List_HashFun->addItem("除留余数法");
        else    ui->List_HashFun->addItem("随机数法");
    }

    qDebug() << sum[0] << sum[1] << sum[2] << wordNum/3 << endl;

    ui->List_HashFunCompare->clear();
    ui->List_HashFunCompare->addItem("平方取中法：" + QString::number(sum[0]/wordNum*3));
    ui->List_HashFunCompare->addItem("除留余数法：" + QString::number(sum[1]/wordNum*3));
    ui->List_HashFunCompare->addItem("随机数法：" + QString::number(sum[2]/wordNum*3));
}

void MainWindow::Press_HashNewRule()
{

}

void MainWindow::Press_DiffSqr()
{
    ui->List_HashDiff->clear();

    int sum[4]={0};
    double wordNum=0;

    for (int k=0; k<4; k++){
        if (k==0)   hashMap.resetHashLink();
        else    hashMap.resetHashArray();
        for (int i=0; i<article.size(); i++){
            QStringList words=article[i].split(" ");
            for (int j=0; j<words.size(); j++){
                sum[k] += hashMap.insert(words[j], 0, k);
                wordNum++;
            }
        }

        if (k == 0) ui->List_HashDiff->addItem("链地址法");
        else if (k == 1) ui->List_HashDiff->addItem("开放定值法-线性探测");
        else if (k == 2) ui->List_HashDiff->addItem("开放定值法-平方探测");
        else    ui->List_HashDiff->addItem("开放定值法-随机探测");
    }

    qDebug() << sum[0] << sum[1] << sum[2] << sum[3] << wordNum/4 << endl;

    ui->List_HashDiffCompare->clear();
    ui->List_HashDiffCompare->addItem("链地址法：" + QString::number(sum[0]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-线性探测：" + QString::number(sum[1]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-平方探测：" + QString::number(sum[2]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-随机探测：" + QString::number(sum[3]/wordNum*4));
}

void MainWindow::Press_DiffMod()
{
    ui->List_HashDiff->clear();

    int sum[4]={0};
    double wordNum=0;

    for (int k=0; k<4; k++){
        if (k==0)   hashMap.resetHashLink();
        else    hashMap.resetHashArray();
        for (int i=0; i<article.size(); i++){
            QStringList words=article[i].split(" ");
            for (int j=0; j<words.size(); j++){
                sum[k] += hashMap.insert(words[j], 1, k);
                wordNum++;
            }
        }

        if (k == 0) ui->List_HashDiff->addItem("链地址法");
        else if (k == 1) ui->List_HashDiff->addItem("开放定值法-线性探测");
        else if (k == 2) ui->List_HashDiff->addItem("开放定值法-平方探测");
        else    ui->List_HashDiff->addItem("开放定值法-随机探测");
    }

    qDebug() << sum[0] << sum[1] << sum[2] << sum[3] << wordNum/4 << endl;

    ui->List_HashDiffCompare->clear();
    ui->List_HashDiffCompare->addItem("链地址法：" + QString::number(sum[0]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-线性探测：" + QString::number(sum[1]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-平方探测：" + QString::number(sum[2]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-随机探测：" + QString::number(sum[3]/wordNum*4));
}

void MainWindow::Press_DiffRandom()
{
    ui->List_HashDiff->clear();

    int sum[4]={0};
    double wordNum=0;

    for (int k=0; k<4; k++){
        if (k==0)   hashMap.resetHashLink();
        else    hashMap.resetHashArray();
        for (int i=0; i<article.size(); i++){
            QStringList words=article[i].split(" ");
            for (int j=0; j<words.size(); j++){
                sum[k] += hashMap.insert(words[j], 2, k);
                wordNum++;
            }
        }

        if (k == 0) ui->List_HashDiff->addItem("链地址法");
        else if (k == 1) ui->List_HashDiff->addItem("开放定值法-线性探测");
        else if (k == 2) ui->List_HashDiff->addItem("开放定值法-平方探测");
        else    ui->List_HashDiff->addItem("开放定值法-随机探测");
    }

    qDebug() << sum[0] << sum[1] << sum[2] << sum[3] << wordNum/4 << endl;

    ui->List_HashDiffCompare->clear();
    ui->List_HashDiffCompare->addItem("链地址法：" + QString::number(sum[0]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-线性探测：" + QString::number(sum[1]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-平方探测：" + QString::number(sum[2]/wordNum*4));
    ui->List_HashDiffCompare->addItem("开放定值法-随机探测：" + QString::number(sum[3]/wordNum*4));
}

MainWindow::~MainWindow()
{
    delete ui;
}
