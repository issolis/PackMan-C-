#include "graphicview.h"
#include <QKeyEvent>
#include <QDebug>
#include <windowgame.h>

bool GameStarted=false;
/**
 * @brief Constructor de la clase GraphicsView.
 *
 * Crea una instancia de la clase GraphicsView y configura la política de enfoque.
 * Centra la vista en la escena.
 *
 * @param parent Puntero al widget padre.
 * @return none.
 */
GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    centerOn(mapToScene(viewport()->rect().center()));

}
/**
 * @brief Manejador de eventos de teclado.
 *
 * Se invoca cuando se presiona una tecla en la vista.
 * Si la tecla presionada es la tecla Return, muestra un mensaje de depuración "hola".
 * De lo contrario, se llama al manejador de eventos de teclado de la clase base.
 *
 * @param event Puntero al evento de teclado.
 * @return none.
 */

void GraphicsView::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Return)
    {
        qDebug()<<"hola";
    }
    else
    {
        QGraphicsView::keyPressEvent(event);
    }
}
/**
 * @brief Establece la escena de la vista.
 *
 * Establece la escena especificada como la escena de la vista.
 *
 * @param scene Puntero a la escena a establecer.
 * @return none.
 */
void GraphicsView:: setScene(QGraphicsScene *scene) {
    QGraphicsView::setScene(scene);
}

