#include "hashmap.h"

HashMap::HashMap()
{
    SIZE = 9973;
    MULT = 26;

    for (int i=0; i<SIZE; i++){
        LinkNode *temp = new LinkNode;
        temp->num = 0;
        temp->key = i;
        temp->next = nullptr;
        myHashLink.push_back(temp);
    }

    myHashArray = new ArrayNode[SIZE];
    for (int i=0; i<SIZE; i++){
        myHashArray[i].num = 0;
        myHashArray[i].word = " ";
    }
}

void HashMap::clear_hashmap()
{
    resetHashLink();
    resetHashArray();
}

int HashMap::getKey_Qsr(QString word)
{
    long long sum=0;
    for (int i=0; i<word.length(); i++){
        if (word[i] < 'a' || word[i] > 'z') continue;
        sum = sum * 3 + word.toUtf8().at(i);
        sum %= SIZE;
    }
    sum = sum*sum;
    QString str=QString::number(sum);
    str = str.mid(str.length()/2-2, 4);
    return str.toInt() % SIZE;
}

int HashMap::getKey_Mod(QString word)
{
    long long sum=0;
    for (int i=0; i<word.length(); i++){
        if (word[i] < 'a' || word[i] > 'z') continue;
        sum = sum * MULT + word.toUtf8().at(i);
        sum %= SIZE;
    }
    return sum % SIZE;
}

int HashMap::getKey_Random(QString word)
{
    long long sum=0;
    for (int i=0; i<word.length(); i++){
        if (word[i] < 'a' || word[i] > 'z') continue;
        sum = sum * 10 + word.toUtf8().at(i);
        sum %= SIZE;
    }
    return sum % SIZE;
}

void HashMap::resetHashLink()
{
    for (int i=0; i<SIZE; i++){
        LinkNode *pre = myHashLink[i]->next;
        while(pre){
            LinkNode *p = pre->next;
            delete pre;
            pre = p;
        }
        myHashLink[i]->num = 0;
        myHashLink[i]->key = i;
        myHashLink[i]->next = nullptr;
    }
}

void HashMap::resetHashArray()
{
    for (int i=0; i<SIZE; i++){
        myHashArray[i].num = 0;
        myHashArray[i].word = " ";
    }
}

int HashMap::insert(QString word, int fun, int diff)
{
    int index;
    if (fun == 0)   index = getKey_Qsr(word);       //平方取中法
    else if (fun == 1)  index = getKey_Mod(word);   //除留余数法
    else    index = getKey_Random(word);            //随机数法

//    qDebug() << index << endl;

    int cnt=0;

    if (diff == 0){         //链地址法
        LinkNode *p = myHashLink[index]->next;
        LinkNode *pre = myHashLink[index];
        while (p && p->word != word){
            p = p->next;
            pre = pre->next;
            cnt++;
        }
        if (p && p->word == word){
            p->num++;
            cnt++;
        }
        else{
            LinkNode *temp = new LinkNode;
            temp->word = word;
            temp->num = 1;
            temp->next = nullptr;
            temp->key = index;
            myHashLink[index]->num++;
            pre->next = temp;
            cnt++;
        }
    }
    else if (diff == 1){    //线性探测
        if (myHashArray[index].num == 0){
            myHashArray[index].num = 1;
            myHashArray[index].word = word;
            cnt++;
        }
        else{
            while(myHashArray[index].num != 0){
                if (myHashArray[index].word == word)    break;
                index++;
                index %= SIZE;
                cnt++;
            }
            if (myHashArray[index].word == word){
                myHashArray[index].num++;
                cnt++;
            }
            else{
                myHashArray[index].num++;
                myHashArray[index].word = word;
                cnt++;
            }
        }
    }
    else if (diff == 2){    //平方探测
        if (myHashArray[index].num == 0){
            myHashArray[index].num++;
            myHashArray[index].word = word;
            cnt++;
        }
        else{
            int step=1, newindex=index, k=0;
            while(myHashArray[newindex].num != 0){
                if (myHashArray[newindex].word == word)    break;
                if (k%2 == 0){
                    newindex = index + step*step;
                    newindex %= SIZE;
                    k++;
                }
                else{
                    newindex = index - step*step;
                    while (newindex < 0)   newindex += SIZE;
                    k++;
                    step++;
                }
                if (step*step > 9973)   return -1;
                cnt++;
            }
            if (myHashArray[newindex].word == word){
                myHashArray[newindex].num++;
                cnt++;
            }
            else{
                myHashArray[newindex].num++;
                myHashArray[newindex].word = word;
                cnt++;
            }
        }
    }
    else if (diff == 3){    //随机探测
        int step=1;
        if (myHashArray[index].num == 0){
            myHashArray[index].num++;
            myHashArray[index].word = word;
            cnt++;
        }
        else{
            while(myHashArray[index].num){
                if (myHashArray[index].word == word)    break;
                index += step;
                step *= 3;
                step %= SIZE;
                index %= SIZE;
                cnt++;
            }
            if (myHashArray[index].word == word){
                myHashArray[index].num++;
                cnt++;
            }
            else{
                myHashArray[index].num++;
                myHashArray[index].word = word;
                cnt++;
            }
        }
    }
    return cnt;
}

void HashMap::setSIZE(int newSIZE)
{
    delete []myHashArray;

    resetHashLink();
    for(int i=0; i<SIZE; i++){
        delete myHashLink[i];
    }
    while(!myHashLink.empty())  myHashLink.pop_back();

    SIZE = newSIZE;

    myHashArray = new ArrayNode[SIZE];
    for (int i=0; i<SIZE; i++){
        myHashArray[i].num = 0;
        myHashArray[i].word = " ";
    }

    for (int i=0; i<SIZE; i++){
        LinkNode *temp = new LinkNode;
        temp->num = 0;
        temp->key = i;
        temp->next = nullptr;
        myHashLink.push_back(temp);
    }
}

int HashMap::getSIZE()
{
    return SIZE;
}
