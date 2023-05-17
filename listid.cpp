#include "listid.h"
#include <iostream>
#include <QString>
#include <QDebug>


listID::listID()
{

}
/**
 * @brief Inserta un nuevo elemento en la lista de IDs.
 *
 * Crea un nuevo nodo con el ID proporcionado y lo inserta al principio de la lista.
 *
 * @param id ID a insertar en la lista.
 * @return none.
 */
void listID::insert(int id){
    nodeID *newNode= new nodeID (id);


    if (head==nullptr){
        head=newNode;
    }else{
        nodeID *aux=head;
        head=newNode;
        head->next=aux;
    }
    numberElements++;
}
/**
 * @brief Muestra los elementos de la lista de IDs.
 *
 * Recorre la lista y muestra los IDs almacenados en cada nodo.
 *
 * @param none.
 * @return none.
 */
void listID::show(){
    nodeID *aux=head;
    QString string="";

    while(aux!=nullptr){
        string= string+" "+QString::number(aux->id);
        aux=aux->next;
    }
    qDebug()<<string;
}
/**
 * @brief Elimina el primer elemento de la lista de IDs.
 *
 * Elimina el primer nodo de la lista, ajustando los punteros de la lista en caso de que existan más nodos.
 *
 * @param none.
 * @return none.
 */
void listID::deleteFirst(){
    if(head!=nullptr){
        if(numberElements==1)
            head=nullptr;
        else
            head=head->next;
        numberElements--;
    }
}
/**
 * @brief Busca un nodo en la lista de IDs.
 *
 * Busca un nodo con el ID proporcionado en la lista y devuelve el nodo si se encuentra, o un nodo especial con un ID inválido en caso contrario.
 *
 * @param id ID a buscar en la lista.
 * @return Puntero al nodo con el ID buscado, o un nodo especial con un ID inválido si no se encuentra.
 */
nodeID* listID:: findNode(int id){
    nodeID *aux=head;
    while(aux!=nullptr){
        if(aux->id==id)
            return aux;
        aux=aux->next;
    }
    nodeID *avoidError=new nodeID(-1);
    return avoidError;
}
