#include "pathfindinglist.h"
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <QtGlobal>
#include <linkedlist.h>
#include <string>
pathFindingList::pathFindingList()
{
    head=nullptr;
}
/**
 * @brief Función para construir una matriz en forma de lista enlazada.
 *
 * Esta función construye una matriz en forma de lista enlazada utilizando nodos de la clase `pathFindingNode`.
 * La matriz tendrá el número de filas y columnas especificadas por los parámetros `rows` y `colums`.
 *
 * @param rows El número de filas de la matriz.
 * @param colums El número de columnas de la matriz.
 * @return Una nueva instancia de `pathFindingList` que contiene la matriz construida.
 */
pathFindingList pathFindingList::buildMatrix(int rows, int colums){
    pathFindingNode *newNode=  new pathFindingNode();
    head=newNode;
    head->idRow=0;
    head->idColum=0;
    head->id=1;
    this->rows=rows;
    this->colums=colums;


    pathFindingNode *auxColum=head;
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    for (int i = 0; i<rows; i++){
        for(int j=0; j<colums; j++){
            pathFindingNode *node1= new pathFindingNode();
            pathFindingNode *node2= new pathFindingNode();

            if(i==0 && j!=colums-1){
                aux->right=node1;
            }
            else{
                if(j!=colums-1)
                    aux->right=aux1->right->down;

            }
            if(j!=colums-1){
                aux->right->idRow=i;
                aux->right->idColum=j+1;
                aux->right->left=aux;}

            if(i!=rows-1){
                aux->down=node2;
                aux->down->idColum=j;
                aux->down->idRow=i+1;
                aux->down->up=aux;
            }
            aux1=aux1->right;
            aux=aux->right;

        }
        aux1=auxColum;
        aux=auxColum->down;
        auxColum=auxColum->down;
    }

    definePos();
    pathFindingList list;
    list.head=head;
    return list;

}
/**
 * @brief Define las posiciones de los nodos en la matriz.
 *
 * Esta función asigna un identificador único a cada nodo en la matriz, basado en su posición de fila y columna.
 * El identificador se calcula como `id = idRow * colums + idColum + 1`.
 *
 * La función recorre la matriz y actualiza el valor del identificador para cada nodo.
 * @param none.
 * @return none.
 */
void pathFindingList::definePos(){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    int i=0;
    while(i!=rows){
        while(aux!=nullptr){
            aux->id=aux->idRow * colums + aux->idColum+1;
            aux=aux->right;
        }
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
}
/**
 * @brief Muestra los nodos en la matriz.
 *
 * Esta función recorre la matriz y muestra los nodos en las listas "open" y "close".
 * Crea una cadena de texto con los identificadores de los nodos en la lista "open"
 * y otra cadena de texto con los identificadores de los nodos en la lista "close".
 * @param none.
 * @return none.
 */
void pathFindingList::show(){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    QTextStream cout(stdout);
    int i=0;
    QString closeList="";
    QString openList="";
    while(i!=rows){
        while(aux!=nullptr){

            if(aux->closed && aux->impresable){
                closeList=QString::number(aux->id)+" "+closeList;
            }
            if(aux->opened){
                openList=QString::number(aux->id)+" "+openList;
            }
            aux=aux->right;
        }

        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
    qDebug()<<"openList: "<<openList;
    qDebug()<<"closeList: "<<closeList;
}
/**
 * @brief Define la función heurística (h) para cada nodo en la matriz.
 *
 * Esta función calcula el valor heurístico para cada nodo en la matriz en función de su posición y la posición del nodo final.
 * El valor heurístico se calcula como la suma de la distancia vertical y la distancia horizontal entre el nodo y el nodo final.
 * El cálculo se realiza utilizando la función qAbs() para obtener el valor absoluto.
 *
 * La función recorre la matriz y actualiza el valor heurístico para cada nodo.
 * @param xF La posición X del nodo final.
 * @param yF La posición Y del nodo final.
 * @return none.
 */
void pathFindingList:: defineH(int xF, int yF){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;

    int i=0;
    while(i!=rows){
        while(aux!=nullptr){

            aux->h= qAbs((aux->idRow)-(yF))+qAbs(aux->idColum-xF);
            aux=aux->right;
        }
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
}
/**
 * @brief Encuentra la ruta desde un nodo inicial hasta un nodo final utilizando el algoritmo de búsqueda A*.
 *
 * Esta función encuentra la ruta desde un nodo inicial hasta un nodo final utilizando el algoritmo de búsqueda A*.
 * La función calcula los valores de g (costo acumulado), h (heurística) y f (suma de g y h) para cada nodo en el proceso de búsqueda.
 * El algoritmo se ejecuta hasta que se encuentra la ruta o se agota la lista de nodos abiertos.
 *
 * @param beginning El identificador del nodo inicial.
 * @param final El identificador del nodo final.
 * @return none.
 */
void pathFindingList:: findRoute(int beggining, int final){
    int xB=-1, yB;
    int xF=-1, yF;
    routeWeight=0;

    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;

    int i=0;
    while(i!=rows){
        while(aux!=nullptr){

            if(aux->id==beggining) {
                xB=aux->idColum;
                yB=aux->idRow;
                start=aux;
            }

            else if(aux->id==final){
                xF=aux->idColum;
                yF=aux->idRow;
                end=aux;
            }
            aux=aux->right;

            if(xB!=-1 && xF!=-1) break;


        }
        if(xB!=-1 && xF!=-1) break;

        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }

    defineH(xF, yF);

    linkedList openList; int iteration=1;

    openList.idFinal=final;
    start->closed=true;
    start->opened=true;
    qDebug()<<"Iteracion "<<iteration;
    show();
    pathFindingNode *auxiliar=start;
    while(!openList.routeFinded){
        if(auxiliar->right!=nullptr && !auxiliar->right->closed) {
            if(auxiliar->right->g!=0){
                if(auxiliar->g+10 < auxiliar->right->g){
                    auxiliar->right->g=auxiliar->g+10;
                    auxiliar->right->f=auxiliar->right->g+auxiliar->right->h;
                    auxiliar->right->parent=auxiliar;
                }
            }
            else{
                auxiliar->right->g=auxiliar->g+10;
                auxiliar->right->f=auxiliar->right->g+auxiliar->right->h;
                auxiliar->right->parent=auxiliar;
            }

            if(!auxiliar->right->opened)
                openList.insert(auxiliar->right);
            auxiliar->right->opened=true;
        }

        if(auxiliar->left!=nullptr && !auxiliar->left->closed) {
            if(auxiliar->left->g!=0){
                if(auxiliar->g+10 < auxiliar->left->g){
                    auxiliar->left->g=auxiliar->g+10;
                    auxiliar->left->parent=auxiliar;
                }
            }else{
                auxiliar->left->g=auxiliar->g+10;
                auxiliar->left->parent=auxiliar;
                auxiliar->left->f=auxiliar->left->g+auxiliar->left->h;
            }

            if(!auxiliar->left->opened)
                openList.insert(auxiliar->left);
            auxiliar->left->opened=true;
        }

        if(auxiliar->down!=nullptr && !auxiliar->down->closed) {
            if(auxiliar->down->g!=0){
                if(auxiliar->g+10 < auxiliar->down->g){
                    auxiliar->down->g=auxiliar->g+10;
                    auxiliar->down->f=auxiliar->down->g+auxiliar->down->h;
                    auxiliar->down->parent=auxiliar;
                }
            }
            else{
                auxiliar->down->g=auxiliar->g+10;
                auxiliar->down->f=auxiliar->down->g+auxiliar->down->h;
                auxiliar->down->parent=auxiliar;
            }

            if(!auxiliar->down->opened){
                openList.insert(auxiliar->down);}
            auxiliar->down->opened=true;
        }

        if(auxiliar->up!=nullptr && !auxiliar->up->closed) {
            if(auxiliar->up->g!=0){
                if(auxiliar->g+10 < auxiliar->up->g){
                    auxiliar->up->g=auxiliar->g+10;
                    auxiliar->up->f=auxiliar->up->g+auxiliar->up->h;
                    auxiliar->up->parent=auxiliar;
                }
            }else{
                auxiliar->up->g=auxiliar->g+10;
                auxiliar->up->f=auxiliar->up->g+auxiliar->up->h;
                auxiliar->up->parent=auxiliar;
            }

            if(!auxiliar->up->opened)
                openList.insert(auxiliar->up);
            auxiliar->up->opened=true;
        }

        if(openList.head!=nullptr)
            openList.findMin();
        else{
            break;
        }
        auxiliar=openList.min;
        auxiliar->closed=true;
        openList.deleteNode(auxiliar);
        iteration++;
        qDebug()<<"Iteracion "<<iteration;
        qDebug()<<" ";
        show();
        qDebug()<<" ";
    }
    if(openList.head!=nullptr){
        pathFindingNode *auxP=end;
        QString route="";
        if(auxP!=nullptr){
            while(auxP->parent!=nullptr){
                route=QString::number(auxP->id )+"-"+ route;
                auxP=auxP->parent;
                routeWeight++;
            }
            route=QString::number(beggining)+"-"+route;
            qDebug()<<route;
        }
    }
}
/**
 * @brief Encuentra un nodo en la matriz por su identificador.
 *
 * Esta función busca un nodo en la matriz basándose en su identificador y devuelve un puntero al nodo encontrado.
 *
 * @param id El identificador del nodo a buscar.
 * @return Un puntero al nodo encontrado, o nullptr si no se encontró ningún nodo con el identificador dado.
 */
pathFindingNode* pathFindingList:: findNode(int id){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    QTextStream cout(stdout);
    int i=0;
    while(i!=rows){
        while(aux!=nullptr){
            if(aux->id==id)
                return aux;
            aux=aux->right;
        }
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
    return aux;
}
/**
 * @brief Restablece los valores de los nodos en la matriz.
 *
 * Esta función restablece los valores de los nodos en la matriz, estableciendo las banderas "closed" y "opened" en falso,
 * y reiniciando los valores de "f", "g", "h" y "parent" a cero o nulo.
 *
 * @param none.
 * @return none.
 */
void pathFindingList::makeItTrue(){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    QTextStream cout(stdout);
    int i=0;
    while(i!=rows){
        while(aux!=nullptr){
            aux->closed=false;
            aux->opened=false;
            aux->f=0;
            aux->g=0;
            aux->h=0;
            aux->parent=nullptr;
            aux=aux->right;
        }
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
}
/**
 * @brief Libera la memoria utilizada por los nodos en la matriz.
 *
 * Esta función recorre la matriz y elimina cada nodo, liberando la memoria asignada.
 * Al finalizar, establece el puntero `head` en nulo para indicar que la lista está vacía.
 *
 * @param none.
 * @return none.
 */

void pathFindingList:: freeEveryThing(){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    QTextStream cout(stdout);
    int i=0;
    while(i!=rows){
        pathFindingNode *next;
        while(aux!=nullptr){
            next=aux->right;
            delete aux;
            aux=next;
        }

        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
    head=nullptr;
}
