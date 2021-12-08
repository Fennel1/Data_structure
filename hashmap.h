#ifndef HASHMAP_H
#define HASHMAP_H

#include <QString>
#include <QtDebug>
#include <map>
#include <vector>

using namespace std;

typedef struct arraynode{
    QString word;
    int num;
}ArrayNode, *Array;

typedef struct linknode{
    int key;
    QString word;
    int num;
    linknode *next;
}LinkNode;

class HashMap
{
public:
    HashMap();

    void clear_hashmap();

    int getKey_Qsr(QString word);   //平方取中法
    int getKey_Mod(QString word);   //除留余数法
    int getKey_Random(QString word); //随机数法

    void resetHashLink();
    void resetHashArray();

    int insert(QString word, int fun, int diff);

    map<QString, int> stlMap;
    Array myHashArray;
    vector<LinkNode *> myHashLink;

private:
    int SIZE;
    int MULT;
    int len;

};

#endif // HASHMAP_H
