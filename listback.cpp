#include "listback.h"
#include <iostream>
#include <QString>
#include <QDebug>
listBack::listBack()
{
    this->head = nullptr;
}
/**
 * @brief Agrega un nuevo nodo con coordenadas (x, y) al final de la lista.
 *
 * Crea un nuevo nodo con las coordenadas proporcionadas y lo agrega al final de la lista.
 *
 * @param x Coordenada x del nodo.
 * @param y Coordenada y del nodo.
 * @return none.
 */
void listBack::add(int x, int y){
    nodeBack* newNode = new nodeBack(x, y);
    if (head == nullptr) {
        head= newNode;
    } else {
        nodeBack* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

}
/**
 * @brief Agrega un nuevo nodo con un ID al final de la lista.
 *
 * Crea un nuevo nodo con el ID proporcionado y lo agrega al final de la lista.
 *
 * @param id ID a agregar a la lista.
 * @return none.
 */
void listBack::addId(int id){
    nodeBack* newNode = new nodeBack(id);
    if (head == nullptr) {
        head= newNode;
    } else {
        nodeBack* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    numberElements++;
}
/**
 * @brief Elimina el último nodo de la lista.
 *
 * Elimina el último nodo de la lista, ajustando los punteros adecuadamente.
 *
 * @param none.
 * @return none.
 */
void listBack::deleteNode(){
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    nodeBack* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
/**
 * @brief Verifica si la lista está vacía.
 *
 * Verifica si la lista está vacía, es decir, si no tiene ningún nodo.
 *
 * @param none.
 * @return true si la lista está vacía, false en caso contrario.
 */
bool listBack::esvacia(){
    return head == nullptr;
}
/**
 * @brief Imprime la lista de coordenadas.
 *
 * Imprime las coordenadas (x, y) de cada nodo de la lista en el formato "(x, y) , (x, y) , ...".
 *
 * @param path Lista de coordenadas a imprimir.
 * @return none.
 */
void listBack::printPath(listBack path){
    if (path.head == nullptr) {
        std::cout << "Empty path\n";
        return;
    }
    nodeBack* curr = path.head;
    std::cout << "(" << curr->x << "," << curr->y << ")";
    curr = curr->next;
    while (curr != nullptr) {
        std::cout << " , (" << curr->x << "," << curr->y << ")";
        curr = curr->next;
    }
    std::cout << std::endl;
}
/**
 * @brief Calcula la longitud de la lista.
 *
 * Calcula el número de nodos en la lista y devuelve su longitud.
 *
 * @param none
 * @return Longitud de la lista.
 */
int listBack::length(){
    int len = 0;
    nodeBack* current = head;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}
/**
 * @brief Agrega una lista de coordenadas a la lista global.
 *
 * Agrega cada nodo de la lista `path` a la lista global, y también agrega los IDs correspondientes a la lista `id_list`.
 *
 * @param path Lista de coordenadas a agregar.
 * @param id_list Lista de IDs asociados a las coordenadas.
 * @return none.
 */
void listBack::addToGlobalList(listBack path, listBack id_list){

    nodeBack* curr = path.head;
    while (curr != nullptr) {
        add(curr->x, curr->y);
        int id= 22*curr->x+curr->y+1;
        id_list.addId(id);

        curr = curr->next;
    }




}
/**
 * @brief Verifica si la lista tiene duplicados.
 *
 * Verifica si la lista contiene nodos con las mismas coordenadas (x, y).
 *
 * @param none.
 * @return true si hay duplicados, false en caso contrario.
 */
bool listBack  ::hasDuplicates() {
    if (head == nullptr) {

        return false;
    }
    else {
        nodeBack* current = head;
        while (current != nullptr) {
            nodeBack* runner = current->next;
            while (runner != nullptr) {
                if (current->x == runner->x && current->y == runner->y) {

                    return true;
                }
                runner = runner->next;
            }
            current = current->next;
        }

        return false;
    }
}
/**
 * @brief Imprime los IDs de la lista.
 *
 * Imprime los IDs de cada nodo de la lista en el formato "ID1, ID2, ...".
 *
 * @param none.
 * @return none.
 */
void listBack::printId(){
    if (head == nullptr) {
        qDebug()<< "Empty path\n";
        return;
    }
    nodeBack* curr = head;
    std::cout << curr->id;
    curr = curr->next;
    while (curr != nullptr) {
        std::cout << " , " << curr->id;
        curr = curr->next;
    }
    std::cout << std::endl;
}
/**
 * @brief Agrega una lista de Ids a la lista global.
 *
 * Agrega los IDs correspondientes a cada nodo de la lista `path` a la lista global.
 *
 * @param path Lista de coordenadas a agregar.
 * @return none
 */
void listBack::addL(listBack path){
    nodeBack* curr = path.head;
    while (curr != nullptr) {

        int id= 22*curr->x+curr->y+1;
        addId(id);

        curr = curr->next;
    }

}
/**
 * @brief Elimina el primer nodo de la lista.
 *
 * Elimina el primer nodo de la lista, ajustando los punteros adecuadamente.
 *
 * @param none.
 * @return none.
 */
void listBack::deleteFirst(){
    if(head!=nullptr){
        if(head->next!=nullptr)
            head=head->next;
        else
            head=nullptr;
    }
    numberElements--;
}
