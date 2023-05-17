#include "linkedlist.h"


linkedList::linkedList()
{

}
/**
 * @brief Inserta un nodo en la lista enlazada.
 *
 * Inserta un nuevo nodo con el ID especificado al final de la lista.
 * Si el ID del nodo es igual al ID final, se marca la ruta como encontrada.
 *
 * @param id Puntero al nodo a insertar.
 * @return none.
 */
void linkedList:: insert(pathFindingNode* id){
    node *newNode= new node(id);
    node *aux = head;
    bool insertable=true;
    if(id->id==idFinal) routeFinded=true;

    if(head==nullptr){
        insertable=false;
        head= newNode;
    }

    while(insertable && aux->next!=nullptr)
        aux=aux->next;
    if(insertable)
        aux->next=newNode;
    findMin();
}
/**
 * @brief Elimina un nodo de la lista enlazada.
 *
 * Elimina el nodo especificado de la lista enlazada, ajustando los punteros adecuadamente.
 *
 * @param Node Puntero al nodo a eliminar.
 * @return none.
 */
void linkedList::deleteNode(pathFindingNode *Node){

    node *aux = head;
    node *aux1=head;
    if(head!=nullptr){
        if(head->id==Node) {
            if(head->next!=nullptr){
                head=head->next;
            }
            else
                head=nullptr;
        }
        aux=head;
        while(aux!=nullptr){

            if(aux->id==Node){
                if(aux->next!=nullptr)
                    aux1->next=aux->next;
                else
                    aux1->next=nullptr;
                break;
            }
            aux1=aux;
            aux=aux->next;
        }
    }
}
/**
 * @brief Encuentra el nodo con el valor mínimo en la lista enlazada.
 *
 * Encuentra el nodo con el valor mínimo de la función f en la lista enlazada.
 * El resultado se guarda en el atributo `min` de la clase `linkedList`.
 *
 * @param none.
 * @return none.
 */
void linkedList:: findMin(){

        pathFindingNode *min=head->id;
        node *aux=head;

        while(aux!=nullptr){
            if(min->f>aux->id->f)
                min=aux->id;
            aux=aux->next;
        }
        this->min=min;


}
