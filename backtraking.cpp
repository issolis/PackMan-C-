#include "backtraking.h"
#include <iostream>
#include <cstring>
#include <QDebug>


using namespace std;




backTraking::backTraking(int arr[m][N]) {

    shortestPathLength=9999;
    memcpy(grid, arr, sizeof(grid));


}
/**
 * @brief Realiza el algoritmo de retroceso para encontrar el camino más corto.
 *
 * Realiza el algoritmo de retroceso (backtracking) para encontrar el camino más corto desde las coordenadas (x, y)
 * hasta las coordenadas (end_x, end_y) en la cuadrícula.
 * Se considera el valor de cada celda en la cuadrícula para determinar si se puede avanzar hacia una dirección específica.
 * Se actualiza la lista `path` con las coordenadas visitadas durante el proceso de retroceso.
 * Si se alcanzan las coordenadas de destino, se compara la distancia del camino actual con la distancia del camino más corto
 * encontrado hasta el momento y se actualiza si es más corto.
 *
 * @param x Coordenada x actual.
 * @param y Coordenada y actual.
 * @param distance Distancia recorrida hasta el momento.
 * @param end_x Coordenada x de destino.
 * @param end_y Coordenada y de destino.
 * @param path Lista de coordenadas visitadas durante el retroceso.
 * @return none.
 */
void backTraking::backtrack(int x, int y, int distance, int end_x, int end_y, listBack path) {
    int value = grid[x][y];
    int row = N;
    int colum = m;

    int manhattanDist = abs(end_x - x) + abs(end_y - y);
    bool canMoveRight = (end_x > x && manhattanDist > abs(end_y - y));
    bool canMoveLeft = (end_x < x && manhattanDist > abs(end_y - y));
    bool canMoveDown = (end_y > y && manhattanDist > abs(end_x - x));
    bool canMoveUp = (end_y < y && manhattanDist > abs(end_x - x));



    if (canMoveRight && grid[x+1][y] != -1) {

        if (grid[x+1][y] >0 ){

            int newValue = grid[x+1][y];

            grid[x+1][y] = -1;
            path.add(x+1, y);
            backtrack(x+1, y, distance + abs(value - newValue), end_x, end_y, path);
            path.deleteNode();
            grid[x+1][y] = newValue;

        }
        else {
            if (!canMoveLeft && x>0 ) {
                canMoveLeft=true;

            }

            if (!canMoveDown && y<row-1) {
                canMoveDown=true;
            }

            if (!canMoveUp && y>0) {
                canMoveUp=true;
            }
        }


    }
    if (canMoveLeft  && grid[x-1][y] != -1) {


        if (grid[x-1][y] >0){

            int newValue = grid[x-1][y];
            grid[x-1][y] = -1;
            path.add(x-1, y);
            backtrack(x-1, y, distance + abs(value - newValue), end_x, end_y, path);
            path.deleteNode();
            grid[x-1][y] = newValue;
        }else {
            if (!canMoveRight && x < colum - 1) {
                canMoveRight=true;

            }

            if (!canMoveDown && y<row-1) {
                canMoveDown=true;
            }

            if (!canMoveUp && y>0) {
                canMoveUp=true;
            }
        }



    }
    if (canMoveDown && grid[x][y+1] != -1) {

        if(grid[x][y+1] >0){
            int newValue = grid[x][y+1];
            grid[x][y+1] = -1;
            path.add(x, y+1);
            backtrack(x, y+1, distance + abs(value - newValue), end_x, end_y, path);
            path.deleteNode();
            grid[x][y+1] = newValue;
        }  else {
            if (!canMoveLeft && x>0) {
                canMoveLeft=true;

            }

            if (!canMoveRight && x < colum - 1) {
                canMoveRight=true;
            }

            if (!canMoveUp && y>0) {
                canMoveUp=true;
            }
        }


    }
    if (canMoveUp && grid[x][y-1] != -1) {

        if (grid[x][y-1] >0 ){

            int newValue = grid[x][y-1];
            grid[x][y-1] = -1;
            path.add(x, y-1);
            backtrack(x, y-1, distance + abs(value - newValue), end_x, end_y, path);
            path.deleteNode();


            grid[x][y-1] = newValue;
        }else {
            if (!canMoveLeft && x>0) {
                canMoveLeft=true;

            }

            if (!canMoveDown && y<row-1) {
                canMoveDown=true;
            }

            if (!canMoveRight && x < colum - 1) {
                canMoveRight=true;
            }
        }


    }
    if (x == end_x && y == end_y ){    ;


        if ( distance < shortestPathLength){

            shortestPathLength = distance;

            if(path.hasDuplicates()==false){
                shortestPath.addToGlobalList(path,id_list);
                shortestPath.printPath(shortestPath);



            }
            path.printPath(path);





        }

        return ;
    }

}
/**
 * @brief Método auxiliar para encontrar el camino más corto desde un punto de inicio hasta un punto final.
 *
 * Crea una lista `path` y agrega el punto de inicio a la lista.
 * Luego, llama al método `backtrack()` para encontrar el camino más corto desde el punto de inicio hasta el punto final.
 * Agrega el contenido de la lista `shortestPath` a la lista `id_list` y la imprime.
 *
 * @param start_x Coordenada x del punto de inicio.
 * @param start_y Coordenada y del punto de inicio.
 * @param end_x Coordenada x del punto final.
 * @param end_y Coordenada y del punto final.
 * @return La lista `id_list` que contiene los identificadores del camino más corto.
 */
listBack backTraking::auxFindShortestPath(int start_x, int start_y, int end_x, int end_y) {
    listBack path;
    path.add(start_x, start_y);
    backtrack(start_x, start_y, 0, end_x, end_y, path);


    id_list.addL(shortestPath);
    id_list.printId();
    return id_list;




}
/**
 * @brief Encuentra el camino más corto desde un punto de inicio hasta un punto final.
 *
 * Calcula el punto de inicio y el punto final en coordenadas de la cuadrícula y luego llama al método auxiliar
 * `auxFindShortestPath()` para encontrar el camino más corto.
 *
 * @param beggining Punto de inicio.
 * @param final Punto final.
 * @return El camino más corto como una lista de coordenadas.
 */
listBack backTraking::findShortestPath(int beggining, int final ){
    int xB=(beggining-1)/22;
    int yB=(beggining-1)%22;
    int xF=(final-1)/22;
    int yF=(final-1)%22;

    return auxFindShortestPath(xB,yB,xF,yF);
}
