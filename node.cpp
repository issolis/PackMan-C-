#include "node.h"
/**
 * @brief Constructor de la clase `node` que asigna un nodo de búsqueda.
 *
 * @param id El nodo de búsqueda que se asignará al objeto `node`.
 * @return Instancia de la clase `node` con el nodo de búsqueda asignado.
 */
node::node(pathFindingNode* id)
{
    this->id=id;
}
