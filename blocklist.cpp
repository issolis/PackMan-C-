#include "blocklist.h"
#include <iostream>

blockList::blockList()
{
head=nullptr;
}
/**
 * @brief Inserta nodos en la lista.
 *
 * Inserta la cantidad especificada de nodos en la lista.
 * Cada nodo se crea con un elemento de rectángulo gráfico y un elemento de imagen de mapa de bits.
 * El ID de cada nodo se asigna en orden descendente desde nodesAmount-1 hasta 0.
 *
 * @param nodesAmount Cantidad de nodos a insertar.
 * @return none.
 */
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
/**
 * @brief Muestra los IDs de los nodos en la lista.
 *
 * Imprime en la consola los IDs de los nodos en la lista.
 * @param none.
 *
 * @return none.
 */
void blockList::show(){
    blockNode *aux=head;
    while(aux!=nullptr){
        std::cout<<aux->id<<" ";
        aux=aux->next;
    }
}
/**
 * @brief Busca un nodo por su ID.
 *
 * Busca y devuelve el nodo con el ID especificado.
 * Si no se encuentra ningún nodo con el ID dado, devuelve un puntero nulo.
 *
 * @param id ID del nodo a buscar.
 * @return Puntero al nodo encontrado o puntero nulo si no se encuentra.
 */
blockNode* blockList::findNode(int id){
    blockNode *aux=head;
    while(aux!=nullptr){
        if(aux->id==id)
            return aux;
        aux=aux->next;
    }
    return aux;
}
/**
 * @brief Inserta un nodo en la lista.
 *
 * Inserta un nuevo nodo al final de la lista.
 *@param none.
 *@return none.
 */
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
/**
 * @brief Busca el último nodo en la lista.
 *
 * Busca y devuelve el último nodo en la lista.
 *@param none.
 * @return Puntero al último nodo.
 */
blockNode* blockList:: findLast(){
    blockNode* aux=head;
    while(aux->next!=nullptr)
        aux=aux->next;
    return aux;
}
