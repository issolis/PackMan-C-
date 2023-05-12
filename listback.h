#ifndef LISTBACK_H
#define LISTBACK_H
#include "nodeback.h"
#include <QString>

class listBack
{
public:
    nodeBack* head=nullptr;
    listBack();
    void add(int x, int y);
    void deleteNode();
    void deleteFirst();
    bool esvacia();
    void printPath(listBack path);
    int length();
    void addToGlobalList(listBack path, listBack id_list);
    bool hasDuplicates() ;
    void addId(int id);
    void printId();
    void addL(listBack path);
    int numberElements=0;




};

#endif // LISTBACK_H
