#include "nodeback.h"
/**
 * @brief Constructor de la clase `nodeBack` que inicializa las coordenadas `x` e `y`.
 *
 * @param x La coordenada `x` del nodo.
 * @param y La coordenada `y` del nodo.
 * @return Instancia de la clase `nodeBack` con las coordenadas `x` e `y` inicializadas.
 */
nodeBack::nodeBack(int x, int y)
{
    this->x = x;
    this->y = y;
    next = nullptr;

}
/**
 * @brief Constructor de la clase `nodeBack` que inicializa el identificador `id`.
 *
 * @param id El identificador del nodo.
 * @return Instancia de la clase `nodeBack` con el identificador `id` inicializado.
 */
nodeBack::nodeBack(int id){
    this->id=id;
    next=nullptr;
}
