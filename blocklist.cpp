#include "blocklist.h"
#include <iostream>

blockList::blockList()
{
head=nullptr;
}
void blockList::insert(int nodesAmount){
    int i=nodesAmount;
    while(i!=0){
        blockNode *newNode=  new blockNode();
        newNode->item=new QGraphicsRectItem(0,0,20,20);
        newNode->item1=new QGraphicsPixmapItem(QPixmap (":poi.png"));
        newNode->id=nodesAmount-i;
        if(i==nodesAmount){
            head=newNode;
        }
        else{
            blockNode *aux=head;
            while(aux->next!=nullptr){
                aux=aux->next;
            }
            aux->next=newNode;
        }
        i--;
    }
}
void blockList::show(){
    blockNode *aux=head;
    while(aux!=nullptr){
        std::cout<<aux->id<<" ";
        aux=aux->next;
    }
}

blockNode* blockList::findNode(int id){
    blockNode *aux=head;
    while(aux!=nullptr){
        if(aux->id==id)
            return aux;
        aux=aux->next;
    }
    return aux;
}
void blockList:: insert(){
    blockNode *newNode =new blockNode();
    blockNode *aux=head;
    if (head==nullptr){
        head=newNode;
    }
    int i=1;
    while(aux!=nullptr){
        if(aux->next==nullptr){
            newNode->id=i;
            aux->next=newNode;
        }
        aux=aux->next;
        i++;
    }
}
blockNode* blockList:: findLast(){
    blockNode* aux=head;
    while(aux->next!=nullptr)
        aux=aux->next;
    return aux;
}
