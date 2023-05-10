#ifndef BLOCKLIST_H
#define BLOCKLIST_H
#include <blocknode.h>

class blockList
{
public:
    blockList();
    blockNode *head=nullptr;
    void insert(int nodesAmount);
    void insert();
    void show();
    blockNode *findNode(int id);
    blockNode* findLast();


};

#endif // BLOCKLIST_H
