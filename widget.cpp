#include "widget.h"
#include <QDebug>
#include <QRandomGenerator>
#include <listid.h>
#include <QTcpSocket>
#include <QLabel>
int posXL1 [54]={-120,-100,-80 ,-60 , -40,-20 ,0   ,-60 ,-60,-60,-60,-120,-100,-80 ,-60 , -40,-20 ,0,40,40,40,40,40,40,60,80,100,120,120,120,120,120,120,-40,-40,-40,-40,-40,-20,0,-20,0,40,40,40,40,40,60,80,60,80,60,80};
int posYL1 [54]={-120,-120,-120,-120,-120,-120,-120,-100,-80,-60,-40,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20,-120,-100,-80,-60,-40,-20,-100,-80,-100,-120,-100,-80,-60,-40,-20,20,40,60,80,100, 20,20,100,100,20,40,60,80,100,20,20,60,60,100,100};
int posXL2[82]={-180 ,-160 ,-140 ,-120 ,-100 ,0 ,80 ,-140 ,-20 ,0 ,20 ,60 ,80 ,100 ,-140 ,-40 ,-20 ,0 ,20 ,40 ,60 ,80 ,100 ,120 ,-140 ,-60 ,-40 ,-20 ,0 ,20 ,40 ,60 ,80 ,100 ,120 ,140 ,-140 ,-40 ,-20 ,0 ,20 ,40 ,60 ,80 ,100 ,120 ,-140 ,-20 ,0 ,20 ,40 ,60 ,80 ,100 ,-140 ,0 ,20 ,40 ,60 ,80 ,-140 ,20 ,40 ,60 ,-180 ,-160 ,-140 ,-120 ,-100 ,40 ,100 ,160 ,100 ,160 ,100 ,160 ,100 ,160 ,100 ,120 ,140 ,160};
int posYL2[82]={-120 ,-120 ,-120 ,-120 ,-120 ,-120 ,-120 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,0 ,0 ,0 ,0 ,0 ,0 ,20 ,20 ,20 ,20 ,40 ,40 ,40 ,40 ,40 ,40 ,40 ,40 ,60 ,60 ,80 ,80 ,100 ,100 ,120 ,120 ,120 ,120};
int posXL3[78]={-200 ,-180 ,-160 ,-80 ,-60 ,-40 ,-20 ,0 ,20 ,120 ,140 ,160 ,-200 ,-160 ,-120 ,120 ,-200 ,-160 ,-120 ,-80 ,-20 ,120 ,160 ,-200 ,-160 ,-140 ,-120 ,-80 ,-20 ,40 ,60 ,80 ,120 ,140 ,160 ,-80 ,-20 ,40 ,80 ,-80 ,-20 ,40 ,80 ,-80 ,-20 ,40 ,80 ,140 ,180 ,-80 ,-20 ,140 ,180 ,-140 ,-120 ,-100 ,-80 ,-20 ,40 ,60 ,80 ,-20 ,40 ,140 ,160 ,180 ,-140 ,-120 ,-100 ,-80 ,-60 ,-20 ,40 ,60 ,80 ,140 ,160 ,180};
int posYL3[78]={-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-80 ,-80 ,-80 ,-80 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-20 ,-20 ,-20 ,-20 ,0 ,0 ,0 ,0 ,20 ,20 ,20 ,20 ,20 ,20 ,40 ,40 ,40 ,40 ,60 ,60 ,60 ,60 ,60 ,60 ,60 ,60 ,80 ,80 ,80 ,80 ,80 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100};
int posXL4[100]={-180 ,-160 ,-140 ,-120 ,-100 ,0 ,80 ,-140 ,-20 ,0 ,20 ,60 ,80 ,100 ,-140 ,-40 ,-20 ,0 ,20 ,40 ,60 ,80 ,100 ,120 ,-200 ,-180 ,-140 ,-60 ,-40 ,-20 ,0 ,20 ,40 ,60 ,80 ,100 ,120 ,140 ,-180 ,-140 ,-40 ,-20 ,0 ,20 ,40 ,60 ,80 ,100 ,120 ,-180 ,-140 ,-20 ,0 ,20 ,40 ,60 ,80 ,100 ,-180 ,-140 ,0 ,20 ,40 ,60 ,80 ,-140 ,-60 ,-40 ,20 ,40 ,60 ,-180 ,-160 ,-140 ,-120 ,-100 ,-60 ,40 ,100 ,160 ,-60 ,-40 ,-20 ,100 ,160 ,-20 ,100 ,160 ,-120 ,-100 ,-80 ,-60 ,-40 ,-20 ,100 ,160 ,100 ,120 ,140 ,160};
int posYL4[100]={-120 ,-120 ,-120 ,-120 ,-120 ,-120 ,-120 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-100 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-80 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-60 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-40 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,20 ,20 ,20 ,20 ,20 ,20 ,40 ,40 ,40 ,40 ,40 ,40 ,40 ,40 ,40 ,60 ,60 ,60 ,60 ,60 ,80 ,80 ,80 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,120 ,120 ,120 ,120 };
bool  enemiesScaping=false;
bool enemy1Catched=false;
bool enemy2Catched=false;
bool enemy3Catched=false;
bool enemy4Catched=false;
bool ended1=true;
QVariant auxiliarBlocks=0;
bool levelPased=false;
widget::widget(QWidget *parent)
    : QWidget(parent)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-220,-140, 440, 280);
    QBrush brush(Qt::gray);
    scene->setBackgroundBrush(brush);
    view = new QGraphicsView(this);
    view->setScene(scene);
    view->setFixedSize(442, 282);
    L1 = scene->addWidget(b_LevelI);
    QPixmap myPixmap(":g1.png");
    enemy1=new QGraphicsPixmapItem(myPixmap);
    enemy2=new QGraphicsPixmapItem(myPixmap);
    enemy3=new QGraphicsPixmapItem(myPixmap);
    enemy4=new QGraphicsPixmapItem(myPixmap);
    enemy2->setPos(-1000,-1000);
    enemy3->setPos(-1000,-1000);enemy4->setPos(-1000,-1000);
    QPixmap myPixma (":pac.png");
    pacman= new QGraphicsPixmapItem(myPixma);
    points.insert(315);
    power=new blockList();
    power->insert(70);
    IDList2= listBack (); IDList3= listBack ();
    QObject::connect(b_LevelI, &QPushButton::clicked, [&]{
        bL1_Clicked();
    });
}
void widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W && !keyUnlocked) {
        direcction=3;
    }
    if (event->key() == Qt::Key_S && !keyUnlocked) {
        direcction=4;
    }
    if (event->key() == Qt::Key_D && !keyUnlocked) {
        direcction=1;
    }
    if (event->key() == Qt::Key_A && !keyUnlocked) {
        direcction=2;
    }
    if (event->key() == Qt::Key_Alt) {
        if(keyUnlocked)
            keyUnlocked=false;
        else
            keyUnlocked=true;
    }
}
/**
 * @brief Coloca una cantidad específica de bloques en la escena del widget.
 *
 * @param amount La cantidad de bloques a colocar en la escena.
 *
 * @return none
 */
void widget:: putBlocks(int amount){
    list.insert(amount);
    int i=0;
    blockNode *aux=list.head;
    while(i!=amount){
        scene->addItem(aux->item);
        QBrush redBrush(Qt::blue);
        QPen pen(Qt::blue);
        aux->item->setBrush(redBrush);
        aux->item->setPen(pen);
        if(level.toInt()==1)
            aux->item->setPos(posXL1[i], posYL1[i]);
        if(level.toInt()==2)
            aux->item->setPos(posXL2[i], posYL2[i]);
        if(level.toInt()==3)
            aux->item->setPos(posXL3[i], posYL3[i]);
        if(level.toInt()==4)
            aux->item->setPos(posXL4[i], posYL4[i]);
        aux=aux->next;
        i++;
    }
}

/**
 * @brief Maneja el evento de clic para el botón de nivel 1.
 *
 * Oculta el botón de nivel 1, coloca los bloques en la escena,
 * agrega los elementos del enemigo y el jugador a la escena,
 * establece sus posiciones iniciales, coloca los puntos en la escena,
 * inicia el movimiento del enemigo, controla el movimiento del jugador,
 * verifica los puntos obtenidos, envía los puntos al servidor,
 * verifica las colisiones y muestra una etiqueta en la interfaz.
 *
 * @param none
 * @return none
 */
void widget::bL1_Clicked(){
    b_LevelI->hide();
    b_LevelI->setEnabled(false);
    putBlocks(53);
    scene->addItem(enemy1);
    scene->addItem(pacman);
    pacman->setPos(-120,0);
    colocatePoints();
    enemy1->setPos(-200, -120);
    MoveFirstEnemy();
    movePlayer();
    checkPoints();
    sendPoints();
    checkCollision();
    label();
    server();
    catched();
}

/**
 * @brief Define la ruta para el primer enemigo.
 *
 * Crea una lista de búsqueda de ruta y construye una matriz.
 * Configura los nodos de bloqueo y marcados según el nivel actual.
 * Muestra la lista de búsqueda de ruta.
 * Calcula la posición de conversión y obtiene la posición del jugador o el poder.
 * Si el enemigo está escapando, se elige una posición aleatoria.
 * Encuentra la ruta desde la posición de conversión hasta la posición objetivo.
 * Guarda los identificadores de los nodos en una lista.
 * Libera la memoria utilizada por la lista de búsqueda de ruta.
 *
 * @param None
 * @return None
 */
void widget:: defineRouteFirstEnemy(){
    pathFindingList *list=new pathFindingList;
    list->buildMatrix(14,22);
    list->makeItTrue();
    int i=0;
    if(level==1){
        while(i!=blocks){
            list->findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->closed=true;
            list->findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->impresable=true;
            i++;
        }
    }
    else if(level==2){
        while(i!=blocks){
            list->findNode (((220+posXL2[i])/20+(140+posYL2[i])/20*22)+1)->closed=true;
            list->findNode (((220+posXL2[i])/20+(140+posYL2[i])/20*22)+1)->impresable=true;
            i++;
        }
    }
    else if(level==3){
        while(i!=blocks){
            list->findNode (((220+posXL3[i])/20+(140+posYL3[i])/20*22)+1)->closed=true;
            list->findNode (((220+posXL3[i])/20+(140+posYL3[i])/20*22)+1)->impresable=true;
            i++;
        }
    }
    else if(level==4){
        while(i!=blocks){
            list->findNode (((220+posXL4[i])/20+(140+posYL4[i])/20*22)+1)->closed=true;
            list->findNode (((220+posXL4[i])/20+(140+posYL4[i])/20*22)+1)->impresable=true;
            i++;
        }
    }
    list->show();
    int conversionPos=((220+enemy1->pos().x())/20+(140+enemy1->pos().y())/20*22)+1;
    int x = 0;
    if(!powerTaken){
        x=((220+pacman->pos().x())/20+(140+pacman->pos().y())/20*22)+1;
    }else{
        x=((220+  power->findNode(IDPower.toInt()-1)->item1->pos().x())/20+(140+  power->findNode(IDPower.toInt()-1)->item1->pos().y())/20*22)+1;
    }
    if(enemiesScaping==true)
        x=randNumber();
    list->findRoute(conversionPos, x);
    pathFindingNode *auxEnd;
    auxEnd= list->end;
    if(auxEnd!=nullptr){
        while (auxEnd!=nullptr) {
            IDList.insert(auxEnd->id);
            auxEnd=auxEnd->parent;
        }
    }
    list->freeEveryThing();
    free(list );
    came=false;
}
/**
 * @brief Define la ruta para el segundo enemigo.
 *
 * Crea una lista de búsqueda de ruta y construye una matriz.
 * Configura los nodos de bloqueo y marcados según el nivel actual.
 * Calcula la posición de conversión y obtiene la posición del jugador o el poder.
 * Si el enemigo está escapando, se elige una posición aleatoria.
 * Encuentra la ruta desde la posición de conversión hasta la posición objetivo.
 * Guarda los identificadores de los nodos en una lista.
 * Libera la memoria utilizada por la lista de búsqueda de ruta.
 *
 * @param None
 * @return None
 */
void widget:: defineRouteSecondEnemy(){
    pathFindingList *list=new pathFindingList;
    list->buildMatrix(15,22);
    list->makeItTrue();
    int i=0;
    if(level==1){
        while(i!=blocks){
            list->findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->closed=true;
            list->findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->impresable=true;
            i++;
        }
    }
    else if(level==2){
        while(i!=blocks){
            list->findNode (((220+posXL2[i])/20+(140+posYL2[i])/20*22)+1)->closed=true;
            list->findNode (((220+posXL2[i])/20+(140+posYL2[i])/20*22)+1)->impresable=true;
            i++;
        }
    }
    else if(level==3){
        while(i!=blocks){
            list->findNode (((220+posXL3[i])/20+(140+posYL3[i])/20*22)+1)->closed=true;
            list->findNode (((220+posXL3[i])/20+(140+posYL3[i])/20*22)+1)->impresable=true;
            i++;
        }
    }
    else if(level==4){
        while(i!=blocks){
            list->findNode (((220+posXL4[i])/20+(140+posYL4[i])/20*22)+1)->closed=true;
            list->findNode (((220+posXL4[i])/20+(140+posYL4[i])/20*22)+1)->impresable=true;
            i++;
        }
    }
    int conversionPos=((220+enemy2->pos().x())/20+(140+enemy2->pos().y())/20*22)+1;
    int x=0;
    if(!powerTaken){
        x=((220+pacman->pos().x())/20+(140+pacman->pos().y())/20*22)+1;
    }else{
        x=((220+power->findNode(IDPower.toInt()-1)->item1->pos().x())/20+(140+  power->findNode(IDPower.toInt()-1)->item1->pos().y())/20*22)+1;
    }
    if(enemiesScaping)
        x=randNumber();
    list->findRoute(conversionPos, x);
    pathFindingNode *auxEnd;
    auxEnd= list->end;
    if(auxEnd!=nullptr){
        while (auxEnd!=nullptr) {
            IDList1.insert(auxEnd->id);
            auxEnd=auxEnd->parent;
        }
    }
    list->freeEveryThing();
    free(list );
    came1=false;
}
/**
 * @brief Define la ruta para el tercer enemigo.
 * @param none.
 * @return none.
 */
void widget::defineRouteThirdEnemy(){
    const int N = 22;
    const int m = 15;

    int level2[14][22]={
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
    };
    int level3[14][22]={
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    int level4[14][22]={
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
    };
    backTraking bt (level2);
    backTraking bt1 (level3);
    backTraking bt2 (level4);


    int conversionPos=((220+enemy3->pos().x())/20+(140+enemy3->pos().y())/20*22)+1;
    int x = 0;
    if(!powerTaken){
        x=((220+pacman->pos().x())/20+(140+pacman->pos().y())/20*22)+1;
    }else{
        x=((220+  power->findNode(IDPower.toInt()-1)->item1->pos().x())/20+(140+  power->findNode(IDPower.toInt()-1)->item1->pos().y())/20*22)+1;
    }
    if(enemiesScaping==true)
        x=randNumber();
    if(level==2)
        IDList2=bt.findShortestPath(conversionPos,x);
    else if(level==3)
        IDList2=bt1.findShortestPath(conversionPos,x);
    else if(level==4)
        IDList2=bt2.findShortestPath(conversionPos,x);
    IDList2.printId();
    came2=false;
    ended1=true;
}
/**
 * @brief Define la ruta para el cuarto enemigo.
 *
 * Esta función define la ruta para el cuarto enemigo en el juego.
 * Utiliza una matriz de nivel predefinida para establecer el diseño del nivel.
 * Luego, encuentra el camino más corto desde la posición del enemigo hasta la posición del objetivo.
 * El objetivo puede ser la posición del personaje principal (Pacman) o una posición de poder,
 * dependiendo de las condiciones del juego.
 * Finalmente, almacena la lista de IDs de los nodos del camino más corto.
 * @param none.
 * @return none.
 */
void widget::defineRouteFourthEnemy(){
    const int N = 22;
    const int m = 15;


    int level2[14][22]={
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
    };
    int level3[14][22]={
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    int level4[14][22]={
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
    };
    backTraking bt (level2);
    backTraking bt1 (level3);
    backTraking bt2 (level4);


    int conversionPos=((220+enemy4->pos().x())/20+(140+enemy4->pos().y())/20*22)+1;
    int x = 0;
    if(!powerTaken){
        x=((220+pacman->pos().x())/20+(140+pacman->pos().y())/20*22)+1;
    }else{
        x=((220+  power->findNode(IDPower.toInt()-1)->item1->pos().x())/20+(140+  power->findNode(IDPower.toInt()-1)->item1->pos().y())/20*22)+1;
    }
    if(enemiesScaping==true)
        x=randNumber();

    if(level==2)
        IDList3=bt.findShortestPath(conversionPos,x);
    else if(level==3)
        IDList3=bt1.findShortestPath(conversionPos,x);
    else if(level==4)
        IDList3=bt2.findShortestPath(conversionPos,x);
    IDList3.printId();
    came3=false;
    ended1=true;
}
/**
 * @brief Mueve al primer enemigo.
 *
 * Esta función se encarga de mover al primer enemigo en el juego.
 * Utiliza un temporizador para controlar el movimiento periódico del enemigo.
 * Si el nivel no ha sido superado, verifica si el enemigo ha llegado al final del camino
 * o si debe definir una nueva ruta. En caso contrario, verifica si el enemigo ha sido atrapado
 * por el personaje principal y realiza el movimiento correspondiente en el camino más corto.
 * @param none.
 * @return none.
 */
void widget::MoveFirstEnemy(){
    int x; int y;
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        if(!levelPased){
            if(came){
                defineRouteFirstEnemy();
            }
            else{
                if(!enemy1Catched){
                    if(IDList.numberElements!=0){
                        x=adapPosX(IDList.head->id);
                        y=adapPosY(IDList.head->id);
                        IDList.deleteFirst();
                        if(IDList.head==nullptr){
                            came=true;
                        }
                        enemy1->setPos(x, y);
                    }
                    else{
                        came=true;
                    }
                }
            }
        }
    });
    timer->start(250);
}
/**
 * @brief Mueve al segundo enemigo.
 *
 * Esta función se encarga de mover al segundo enemigo en el juego.
 * Utiliza un temporizador para controlar el movimiento periódico del enemigo.
 * Si el nivel no ha sido superado, verifica si el enemigo ha llegado al final del camino
 * o si debe definir una nueva ruta. En caso contrario, verifica si el enemigo ha sido atrapado
 * por el personaje principal y realiza el movimiento correspondiente en el camino más corto.
 * @param none.
 * @return none.
 */
void widget::MoveSecondEnemy(){
    int x; int y;
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        if(!levelPased){
            if(came1){
                defineRouteSecondEnemy();
            }
            else{
                if(!enemy2Catched){
                    if(IDList1.numberElements!=0){
                        x=adapPosX(IDList1.head->id);
                        y=adapPosY(IDList1.head->id);
                        IDList1.deleteFirst();
                        if(IDList1.head==nullptr){
                            came1=true;
                        }
                        enemy2->setPos(x, y);
                    }else{
                        came1=true;
                    }
                }
            }
        }
    });
    timer->start(200);
}
void widget::MoveThirdEnemy(){
    int x; int y;
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        if(!levelPased){
            if(came2){
                defineRouteThirdEnemy();
            }
            else{
                if(!enemy4Catched){
                    if(IDList2.numberElements!=0){
                        x=adapPosX(IDList2.head->id);
                        y=adapPosY(IDList2.head->id);
                        IDList2.deleteFirst();
                        if(IDList2.numberElements==0){
                            came2=true;
                        }
                        enemy3->setPos(x, y);
                    }
                    else{
                        came2=true;
                    }
                }
            }
        }
    });
    timer->start(200);
}
/**
 * @brief Mueve al tercer enemigo.
 *
 * Esta función se encarga de mover al tercer enemigo en el juego.
 * Utiliza un temporizador para controlar el movimiento periódico del enemigo.
 * Si el nivel no ha sido superado, verifica si el enemigo ha llegado al final del camino
 * o si debe definir una nueva ruta. En caso contrario, verifica si el enemigo ha sido atrapado
 * por el personaje principal y realiza el movimiento correspondiente en el camino más corto.
 * @param none.
 * @return none.
 */
void widget::MoveFourthEnemy(){

    int x; int y;
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        if(!levelPased){
            if(came3){
                defineRouteFourthEnemy();
            }
            else{
                if(!enemy4Catched){
                    if(IDList3.numberElements!=0){
                        x=adapPosX(IDList3.head->id);
                        y=adapPosY(IDList3.head->id);
                        IDList3.deleteFirst();
                        if(IDList3.numberElements==0){
                            came3=true;
                        }
                        enemy3->setPos(x, y);
                    }
                    else{
                        came3=true;
                    }
                }
            }
        }
    });
    timer->start(210);

}
/**
 * @brief Genera un número aleatorio.
 *
 * Esta función genera un número aleatorio dentro de un rango específico.
 * El número generado debe cumplir ciertas condiciones definidas por la función `noPutIt()`.
 * La función utiliza un bucle while para generar y verificar continuamente números hasta encontrar
 * uno que cumpla las condiciones establecidas. En caso contrario, se repite el proceso hasta encontrar
 * un número válido.
 * @param none.
 * @return El número aleatorio generado.
 */
int widget::randNumber(){
    int i=0; bool again=false;
    while(true){
        again=false;
        int rand=QRandomGenerator::global()->bounded(1, 308);
        while(i!=blocks){
            if((noPutIt(level.toInt(),rand))){
                again=true;
                break;
            } i++;
        }
        if(!again)
            return rand;
    }
}
/**
 * @brief Calcula la posición X adaptada a partir de un ID.
 *
 * Esta función recibe un ID como parámetro y calcula la posición X correspondiente.
 * La posición X se adapta en base al ID proporcionado, utilizando una fórmula que
 * considera la cantidad de columnas en el grid y el tamaño de cada celda.
 *
 * @param id El ID utilizado para calcular la posición X.
 * @return La posición X adaptada.
 */
int widget::adapPosX(int id){
    int posX=-220+(id-1)%22*20;
    return posX;
}
/**
 * @brief Calcula la posición Y adaptada a partir de un ID.
 *
 * Esta función recibe un ID como parámetro y calcula la posición Y correspondiente.
 * La posición Y se adapta en base al ID proporcionado, utilizando una fórmula que
 * considera la cantidad de columnas en el grid y el tamaño de cada celda.
 *
 * @param id El ID utilizado para calcular la posición Y.
 * @return La posición Y adaptada.
 */
int widget::adapPosY(int id){
    return -140+(id-1)/22*20;
}
/**
 * @brief Mueve al jugador en la dirección especificada.
 *
 * Esta función se encarga de mover al jugador (pacman) en la dirección especificada.
 * Utiliza un temporizador para realizar los movimientos en intervalos de tiempo regulares.
 * El movimiento se realiza de acuerdo a la dirección almacenada en la variable "direcction".
 *
 * @param none.
 * @return none.
 */
void widget::movePlayer(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        int conversionPos;
        if(direcction==1){
            conversionPos=((240+pacman->pos().x())/20+(140+pacman->pos().y())/20*22)+1;
            if (!noPutIt(level.toInt(), conversionPos))
                pacman->setPos(pacman->pos().x()+20, pacman->pos().y());
            if(pacman->pos().x()>200){
                pacman->setPos(-220, pacman->pos().y());
            }
        }
        if(direcction==2){
            conversionPos=((200+pacman->pos().x())/20+(140+pacman->pos().y())/20*22)+1;
            if (!noPutIt(level.toInt(), conversionPos))
                pacman->setPos(pacman->pos().x()-20, pacman->pos().y());
            if(pacman->pos().x()<-220){
                pacman->setPos(200, pacman->pos().y());
            }
        }
        if(direcction==3){
            conversionPos=((220+pacman->pos().x())/20+(120+pacman->pos().y())/20*22)+1;
            if (!noPutIt(level.toInt(), conversionPos))
                pacman->setPos(pacman->pos().x(), pacman->pos().y()-20);
            if(pacman->pos().y()<-140){
                pacman->setPos( pacman->pos().x(),120);
            }
        }
        if(direcction==4){
            conversionPos=((220+pacman->pos().x())/20+(160+pacman->pos().y())/20*22)+1;
            if (!noPutIt(level.toInt(), conversionPos))
                pacman->setPos(pacman->pos().x(), pacman->pos().y()+20);
            if(pacman->pos().y()>120){
                pacman->setPos(pacman->pos().x(),-140);
            }
        }
    }
    );
    timer->start(275);
}
/**
 * @brief Coloca los puntos en el escenario de juego.
 *
 * Esta función se encarga de colocar los puntos en el escenario de juego.
 * Recorre un rango de índices y verifica si se puede colocar un punto en esa posición.
 * La verificación se realiza utilizando la función noPutIt() y el nivel actual del juego.
 * Los puntos se colocan en las posiciones adecuadas utilizando las coordenadas adaptadas.
 * @param none.
 * @return none.
 */
void widget:: colocatePoints(){
    int i=0;
    int j=0;
    while(i!=309){
        bool flag=true;
        if(level.toInt()==1)
            flag=noPutIt(1,i);
        if(level.toInt()==2)
            flag=noPutIt(2,i);
        if(level.toInt()==3)
            flag=noPutIt(3,i);
        if(!flag){
            points.findNode(j)->item1->setPos(adapPosX(i),adapPosY(i));
            points.findNode(j)->item1->setZValue(-91);
            scene->addItem( points.findNode(j)->item1);
            j++;
        }
        i++;
    }
}
bool widget:: noPutIt(int level, int ID){
    int i=0;
    if(level==1){
        while(i!=blocks){
            if (adapPosX(ID)==posXL1[i] && adapPosY(ID)==posYL1[i]){
                return true;}
            i++;
        }
    }
    if(level==2){
        while(i!=blocks){
            if (adapPosX(ID)==posXL2[i] && adapPosY(ID)==posYL2[i]){
                return true;}
            i++;
        }
    }
    if(level==3){
        while(i!=blocks){
            if (adapPosX(ID)==posXL3[i] && adapPosY(ID)==posYL3[i]){
                return true;}
            i++;
        }
    }
    return false;
}
/**
 * @brief Verifica si el jugador ha recogido puntos.
 *
 * Esta función se encarga de verificar si el jugador ha recogido algún punto.
 * Utiliza un temporizador para verificar periódicamente la posición del jugador
 * en relación con la posición de los puntos. Si el jugador está en la misma posición
 * que un punto, se realiza el procesamiento correspondiente. Se cambia la imagen del punto,
 * se actualiza el contador de puntos y se realizan acciones adicionales dependiendo de la situación.
 *
 *@param none.
 *@return none.
 */
void widget:: checkPoints(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        int i=0;
        while(i!=309){
            if( !levelPased && points.findNode(i)->item1->pos()==pacman->pos()){

                points.findNode(i)->item1->setPixmap(QPixmap (":bg.png"));
                points.findNode(i)->item1->setZValue(-90);
                if(pointsVisited.findNode(i)->id!=i){
                    totalPoints=totalPoints.toInt()+10;
                    pointsVisited.insert(i);
                    if(pointsVisited.numberElements==100 && !levelPased){

                        levelPased=true;
                        if(level==1){
                            level=level.toInt()+1;
                            pacman->setPos(200,-120);
                            listID list2;
                            pointsVisited=list2;
                            pointsVisited.numberElements=0;
                            points.insert(315);
                            IDList.head=nullptr;
                            came=true;
                            int i=0;
                            blockNode *aux=list.head;
                            blockList newList;
                            while(aux!=nullptr){
                                scene->removeItem(aux->item);
                                aux=aux->next;
                            }
                            aux=list.head;
                            while(i!=330){
                                QGraphicsPixmapItem *item=new QGraphicsPixmapItem (QPixmap (":bg.png"));
                                item->setPos(adapPosX(i),adapPosY(i));
                                item->setZValue(-101);
                                scene->addItem(item);
                                i++;
                            }
                            blocks=82;
                            blockList nwList;
                            putBlocks(82);
                            colocatePoints();
                            QPixmap myPixmap(":g1.png");
                            enemy1->setPos(200, 120);
                            enemy3->setPos(200, 120);
                            scene->addItem(enemy3);
                            MoveThirdEnemy();
                            levelPased=false;
                        }
                        else if(level==2){
                            level=level.toInt()+1;
                            pacman->setPos(200,120);
                            listID list2;
                            pointsVisited=list2;
                            IDList.head=nullptr;
                            came=true;
                            IDList2.head=nullptr;
                            came2=true;

                            int i=0;
                            blockNode *aux=list.head;
                            blockList newList;
                            while(aux!=nullptr){
                                scene->removeItem(aux->item);
                                aux=aux->next;
                            }
                            aux=list.head;
                            while(i!=330){
                                QGraphicsPixmapItem *item=new QGraphicsPixmapItem (QPixmap (":bg.png"));
                                item->setPos(adapPosX(i),adapPosY(i));
                                item->setZValue(-110);
                                scene->addItem(item);
                                i++;
                            }
                            blocks=78;
                            blockList nwList;
                            putBlocks(78);
                            colocatePoints();
                            QPixmap myPixmap(":g1.png");
                            enemy1->setPos(-220, -140);
                            enemy2->setPos(-220, -140);
                            enemy3->setPos(-220, -140);
                            scene->addItem(enemy2);
                            MoveSecondEnemy();
                            levelPased=false;
                        }
                        else if(level==3){
                            level=level.toInt()+1;
                            pacman->setPos(200,120);
                            listID list2;
                            pointsVisited=list2;
                            IDList1.numberElements=0;
                            came1=true;
                            IDList2.numberElements=0;
                            came2=true;
                            IDList.numberElements=0;
                            came=true;

                            int i=0;
                            blockNode *aux=list.head;
                            blockList newList;
                            while(aux!=nullptr){
                                scene->removeItem(aux->item);
                                aux=aux->next;
                            }
                            aux=list.head;
                            while(i!=330){
                                QGraphicsPixmapItem *item=new QGraphicsPixmapItem (QPixmap (":bg.png"));
                                item->setPos(adapPosX(i),adapPosY(i));
                                item->setZValue(-110);
                                scene->addItem(item);
                                i++;
                            }
                            blocks=78;
                            blockList nwList;
                            putBlocks(78);
                            colocatePoints();
                            QPixmap myPixmap(":g1.png");
                            enemy1->setPos(-220, -140);
                            enemy2->setPos(-220, -140);
                            enemy3->setPos(-220, -140);
                            enemy4->setPos(-220, -140);
                            scene->addItem(enemy4);
                            MoveFourthEnemy();
                            levelPased=false;
                        }
                        else if(level==4){
                            QString s= "Ganaste, tus puntos: "+totalPoints.toString();
                            QLabel *label = new QLabel(s , this);
                            label->setAlignment(Qt::AlignCenter);
                            label->setFixedSize(200, 50);
                            label->show();
                            label->move(220,140);
                            label->setStyleSheet("background-color: red;");
                            QTimer::singleShot(5000, [=]() {
                                close();
                            });
                        }
                        //pointsVisited.head=nullptr;
                    }
                }
                if((totalPoints.toInt()-auxTotalPoints.toInt())>=200  && auxTotalPoints!=totalPoints && !powerTaken && !enemiesScaping){
                    power->findNode(IDPower.toInt())->item1->setPixmap(QPixmap (":fruit.png"));
                    int x=randNumber();
                    power->findNode(IDPower.toInt())->item1->setPos(adapPosX(x),adapPosY(x));
                    scene->addItem(power->findNode(IDPower.toInt())->item1);
                    IDPower=IDPower.toInt()+1;
                    auxTotalPoints=totalPoints;
                    powerTaken=true;
                }
            }
            i++;
        }
    }
    );
    timer->start(150);
}
/**
 * @brief Función del servidor para recibir y procesar las entradas del cliente.
 *
 * Esta función se encarga de establecer un temporizador para recibir y procesar las
 * entradas del cliente. Utiliza un objeto `QTimer` para realizar esta tarea de manera
 * periódica. Cuando se recibe una entrada del cliente, se verifica si el teclado del
 * juego está desbloqueado (`keyUnlocked`). Si está desbloqueado y se recibe una entrada
 * válida, se actualiza la dirección del jugador (`direcction`) según la entrada recibida.
 *@param none.
 *@return none.
 */
void widget:: server(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        QString s=Server->socket->readAll();
        if(keyUnlocked){
            if(!s.isEmpty() ){

                if(s=="\u0001" || s=="\u0001\u0001" || s=="\u0001\u0001\u0001" || s=="\u0001\u0001\u0001\u0001" || s=="\u0001\u0001\u0001\u0001\u0001"){
                    direcction=1;
                }
                else if(s=="\u0002" || s=="\u0002\u0002" || s=="\u0002\u0002\u0002" || s=="\u0002\u0002\u0002\u0002" || s=="\u0002\u0002\u0002\u0002\u0002"){
                    direcction=2;
                }
                else if(s=="\u0003" || s=="\u0003\u0003" || s=="\u0003\u0003\u0003" || s=="\u0003\u0003\u0003\u0003" || s=="\u0003\u0003\u0003\u0003\u0003"){
                    direcction=3;
                }
                else if(s=="\u0004" || s=="\u0004\u0004" || s=="\u0004\u0004\u0004" || s=="\u0004\u0004\u0004\u0004" || s=="\u0004\u0004\u0004\u0004\u0004"){
                    direcction=4;
                }
            }
        }
    });
    timer->start();
}
/**
 * @brief Función para verificar las colisiones entre el personaje y los enemigos.
 *
 * Esta función establece un temporizador para verificar periódicamente si el personaje
 * (`pacman`) ha colisionado con alguno de los enemigos (`enemy1`, `enemy2`, `enemy3`,
 * `enemy4`). Si hay una colisión y los enemigos no están escapando (`enemiesScaping`),
 * se decrementa la cantidad de vidas (`lifes`) y se reposiciona al personaje en una
 * posición aleatoria. Si las vidas llegan a cero, se muestra un mensaje de "Perdiste" y
 * se cierra la ventana del juego después de 5 segundos.
 * @param none.
 * @return none.
 */
void widget:: checkCollision(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        if(pacman->pos()==enemy1->pos() || pacman->pos()==enemy2->pos() ||pacman->pos()==enemy3->pos() || pacman->pos()==enemy4->pos()){
            if(!enemiesScaping){
                lifes=lifes.toInt()-1;
                int x=randNumber();
                pacman->setPos(adapPosX(x),adapPosY(x));
                if(lifes==0){
                    QLabel *label = new QLabel("Perdiste", this);
                    label->setAlignment(Qt::AlignCenter);
                    label->setFixedSize(200, 50);
                    label->show();
                    label->move(220,140);
                    label->setStyleSheet("background-color: red;");
                    QTimer::singleShot(5000, [=]() {
                        close();
                    });
                }
            }
            else{

                if(pacman->pos()==enemy1->pos()){
                    if(!enemy1Catched) totalPoints=totalPoints.toInt()+50;
                    enemy1Catched=true;
                    desapairEnemy1(enemy1);
                }
                else if(pacman->pos()==enemy2->pos()){
                    if(!enemy2Catched) totalPoints=totalPoints.toInt()+50;
                    enemy1Catched=true;
                    desapairEnemy2(enemy2);
                }
                else if(pacman->pos()==enemy3->pos()){
                    if(!enemy3Catched) totalPoints=totalPoints.toInt()+50;
                    enemy1Catched=true;
                    desapairEnemy3(enemy3);
                }
                else if(pacman->pos()==enemy4->pos()){
                    if(!enemy4Catched) totalPoints=totalPoints.toInt()+50;
                    enemy1Catched=true;
                    desapairEnemy4(enemy4);
                }
            }
        }
    });
    timer->start(10);
}
/**
 * @brief Función para mostrar una etiqueta con información del juego.
 *
 * Esta función establece un temporizador para actualizar periódicamente una etiqueta
 * que muestra información del juego. La etiqueta incluye la cantidad de vidas
 * (`lifes`), el nivel actual (`level`) y la cantidad total de puntos (`totalPoints`).
 *
 * @param none.
 * @return none.
 */
void widget:: label(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        QLabel *label = new QLabel("Lifes:"+lifes.toString()+" Level:"+level.toString()+" Points:"+totalPoints.toString(), this);
        label->setFixedSize(180, 10);
        label->move(120,0);
        label->show();
        label->setStyleSheet("background-color: blue;");
    });
    timer->start(10);
}
/**
 * @brief Función para verificar si el poder ha sido capturado por el jugador o ha afectado a los enemigos.
 *
 * Esta función establece un temporizador para verificar periódicamente si el poder ha sido capturado por el jugador
 * o ha afectado a los enemigos. Si el poder ha sido capturado por un enemigo, se establece la posición del poder
 * fuera de la escena. Si el jugador está en la misma posición que el poder, se activa un temporizador de escape para
 * los enemigos durante 10 segundos.
 *
 *@param none.
 *@return none.
 */
void widget:: catched(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        if(IDPower!=0){
            QGraphicsPixmapItem *item=power->findNode(IDPower.toInt()-1)->item1;
            if( item->pos()==enemy1->pos() || item->pos()==enemy2->pos() || item->pos()==enemy3->pos() || item->pos()==enemy4->pos()  ){
                power->findNode(IDPower.toInt()-1)->item1->setPos(-1000,-1000);
                powerTaken=false;
            }
            if(pacman->pos()==power->findNode(IDPower.toInt()-1)->item1->pos()){
                auxTotalPoints=totalPoints;
                enemiesScaping=true;
                power->findNode(IDPower.toInt()-1)->item1->setPos(-1000,-1000);
                powerTaken=false;
                QTimer::singleShot(10000, [=]() {
                    enemiesScaping=false;
                });
            }
        }
    });
    timer->start(10);
}
/**
 * @brief Función para hacer desaparecer al enemigo 1 temporalmente.
 *
 * Esta función oculta el objeto `item` (que representa al enemigo 1) durante 5 segundos y luego lo vuelve a mostrar.
 * Además, restablece la bandera `enemy1Catched` a `false`, indicando que el enemigo 1 no ha sido capturado.
 *
 * @param item El objeto `QGraphicsPixmapItem` que representa al enemigo 1.
 *
 * @return none.
 */
void widget:: desapairEnemy1(QGraphicsPixmapItem *item){
    int x=0;
    while(came && x!=150){
        x=x+1;
    }

    item->hide();
    QTimer::singleShot(5000, [=]() {
        item->setVisible(true);
        enemy1Catched=false;
    });
}
/**
 * @brief Función para hacer desaparecer al enemigo 2 temporalmente.
 *
 * Esta función oculta el objeto `item` (que representa al enemigo 2) durante 5 segundos y luego lo vuelve a mostrar.
 * Además, restablece la bandera `enemy1Catched` a `false`, indicando que el enemigo 1 no ha sido capturado.
 *
 * @param item El objeto `QGraphicsPixmapItem` que representa al enemigo 2.
 *
 * @return none.
 */
void widget:: desapairEnemy2(QGraphicsPixmapItem *item){
    item->hide();
    QTimer::singleShot(5000, [=]() {
        item->setVisible(true);
        enemy2Catched=false;
    });
}
/**
 * @brief Función para hacer desaparecer al enemigo 3 temporalmente.
 *
 * Esta función oculta el objeto `item` (que representa al enemigo 3) durante 5 segundos y luego lo vuelve a mostrar.
 * Además, restablece la bandera `enemy1Catched` a `false`, indicando que el enemigo 1 no ha sido capturado.
 *
 * @param item El objeto `QGraphicsPixmapItem` que representa al enemigo 3.
 *
 * @return none.
 */
void widget:: desapairEnemy3(QGraphicsPixmapItem *item){
    item->hide();
    QTimer::singleShot(5000, [=]() {
        item->setVisible(true);
        enemy3Catched=false;
    });
}
/**
 * @brief Función para hacer desaparecer al enemigo 4 temporalmente.
 *
 * Esta función oculta el objeto `item` (que representa al enemigo 4) durante 5 segundos y luego lo vuelve a mostrar.
 * Además, restablece la bandera `enemy1Catched` a `false`, indicando que el enemigo 1 no ha sido capturado.
 *
 * @param item El objeto `QGraphicsPixmapItem` que representa al enemigo 4.
 *
 * @return none.
 */
void widget:: desapairEnemy4(QGraphicsPixmapItem *item){
    item->hide();
    QTimer::singleShot(5000, [=]() {
        item->setVisible(true);
        enemy4Catched=false;
    });
}
/**
 * @brief Función para enviar los puntos y las vidas al cliente a través del socket.
 *
 * Esta función configura un temporizador que enviará periódicamente los puntos y las vidas al cliente.
 * La función `sendLifes` se conecta a la señal `timeout` del temporizador y se encargará de enviar los datos.
 * @param none.
 * @return none.
 */
void widget::sendPoints()
{
    QTimer* timer;
    timer = new QTimer(this);


    connect(timer, &QTimer::timeout, this, &widget::sendLifes);


    s:
    timer->start(50);
}
    /**
 * @brief Función para enviar las vidas y los puntos al cliente a través del socket.
 *
 * Esta función construye una cadena de texto que contiene la información de las vidas y los puntos.
 * Luego, verifica si el socket del objeto `Server1` está abierto y, en caso afirmativo, envía la cadena de texto al cliente.
 * Si el socket no está abierto, muestra un mensaje de error.
 * @param none.
 * @return none.
 */
void widget::sendLifes(){
    QString st = "lifes:"  + lifes.toString() + ";points:" + totalPoints.toString();

    if (Server1->socket->isOpen()) {
        Server1->socket->write(st.toUtf8());
        Server1->socket->flush();
    } else {
        qDebug() << "Error: El socket no está abierto";
    }
}

