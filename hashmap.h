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
    QString word;
    int num;
    linknode *next;
}LinkNode;

class HashMap
{
public:
    HashMap();
private:
    map<QString, int> stlMap;
    Array myHashArray;
    vector<LinkNode *> myHashLink;

    int size;
    int len;

};

#endif // HASHMAP_H
