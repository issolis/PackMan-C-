#include "localserver.h"
#include <QTcpServer>
#include <QTcpSocket>
/**
 * @brief Constructor de la clase `LocalServer` que inicializa el servidor local.
 *
 * @param parent Objeto padre (opcional) para la instancia del servidor local.
 * @return Instancia de la clase `LocalServer` con el servidor local inicializado.
 */
LocalServer::LocalServer(QObject *parent)
    : QTcpServer(parent){
    socket=nullptr;

    connect(this, &LocalServer::newConnection, [&](){
       socket=nextPendingConnection();
    });
}
