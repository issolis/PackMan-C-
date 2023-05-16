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
    points.insert(300);
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
void widget::bL1_Clicked(){
    b_LevelI->hide();
    b_LevelI->setEnabled(false);
    putBlocks(53);
    scene->addItem(enemy1);
    scene->addItem(pacman);
    pacman->setPos(-120,0);
    colocatePoints();
    enemy1->setPos(-200, -120);
    //MoveFirstEnemy();
    movePlayer();
    checkPoints();
    sendPoints();
    checkCollision();
    label();
    server();
    catched();
}
void widget:: defineRouteFirstEnemy(){
    pathFindingList *list=new pathFindingList;
    list->buildMatrix(14,22);
    list->makeItTrue();
    int i=0;
    if(level==1){
        while(i!=blocks){
            list->findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->closed=true;
            i++;
        }
    }
    else if(level==2){
        while(i!=blocks){
            list->findNode (((220+posXL2[i])/20+(140+posYL2[i])/20*22)+1)->closed=true;
            i++;
        }
    }
    else if(level==3){
        while(i!=blocks){
            list->findNode (((220+posXL3[i])/20+(140+posYL3[i])/20*22)+1)->closed=true;
            i++;
        }
    }
    else if(level==4){
        while(i!=blocks){
            list->findNode (((220+posXL4[i])/20+(140+posYL4[i])/20*22)+1)->closed=true;
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
void widget:: defineRouteSecondEnemy(){
    pathFindingList *list=new pathFindingList;
    list->buildMatrix(15,22);
    list->makeItTrue();
    int i=0;
    if(level==1){
        while(i!=blocks){
            list->findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->closed=true;
            i++;
        }
    }
    else if(level==2){
        while(i!=blocks){
            list->findNode (((220+posXL2[i])/20+(140+posYL2[i])/20*22)+1)->closed=true;
            i++;
        }
    }
    else if(level==3){
        while(i!=blocks){
            list->findNode (((220+posXL3[i])/20+(140+posYL3[i])/20*22)+1)->closed=true;
            i++;
        }
    }
    else if(level==4){
        while(i!=blocks){
            list->findNode (((220+posXL4[i])/20+(140+posYL4[i])/20*22)+1)->closed=true;
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
void widget::defineRouteFourthEnemy(){
    const int N = 22;
    const int m = 15;

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
    backTraking *bt;

    int conversionPos=((220+enemy3->pos().x())/20+(140+enemy3->pos().y())/20*22)+1;
    int x = 0;
    if(!powerTaken){
        x=((220+pacman->pos().x())/20+(140+pacman->pos().y())/20*22)+1;
    }else{
        x=((220+  power->findNode(IDPower.toInt()-1)->item1->pos().x())/20+(140+  power->findNode(IDPower.toInt()-1)->item1->pos().y())/20*22)+1;
    }
    if(enemiesScaping==true)
        x=randNumber();
    IDList3=bt->findShortestPath(conversionPos,x);
    IDList3.printId();
    came3=false;
    ended1=true;
}
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
int widget::adapPosX(int id){
    int posX=-220+(id-1)%22*20;
    return posX;
}
int widget::adapPosY(int id){
    return -140+(id-1)/22*20;
}
void widget::movePlayer(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        int conversionPos; qDebug()<<level;
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
void widget:: checkPoints(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        int i=0;
        while(i!=309-blocks.toInt()){
            if(points.findNode(i)->item1->pos()==pacman->pos()){
                //qDebug()<<"s[i";
                points.findNode(i)->item1->setPixmap(QPixmap (":bg.png"));
                points.findNode(i)->item1->setZValue(-90);
                if(pointsVisited.findNode(i)->id!=i){
                    totalPoints=totalPoints.toInt()+10;
                    pointsVisited.insert(i);
                    if(pointsVisited.numberElements==1000 && !levelPased){

                        levelPased=true;
                        if(level==1){
                            level=level.toInt()+1;
                            pacman->setPos(200,120);
                            listID list2;
                            pointsVisited=list2;
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
                            enemy1->setPos(-220, -140);
                            enemy3->setPos(200, 120);
                            scene->addItem(enemy3);
                            //MoveThirdEnemy();
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
                            //MoveThirdEnemy();
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
                            MoveSecondEnemy();
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
void widget:: server(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        QString s=Server->socket->readAll();
        if(keyUnlocked){
            if(!s.isEmpty() ){
                qDebug()<<s;
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
void widget:: desapairEnemy2(QGraphicsPixmapItem *item){
    item->hide();
    QTimer::singleShot(5000, [=]() {
         item->setVisible(true);
        enemy2Catched=false;
    });
}
void widget:: desapairEnemy3(QGraphicsPixmapItem *item){
   item->hide();
    QTimer::singleShot(5000, [=]() {
         item->setVisible(true);
        enemy3Catched=false;
    });
}
void widget:: desapairEnemy4(QGraphicsPixmapItem *item){
    item->hide();
    QTimer::singleShot(5000, [=]() {
         item->setVisible(true);
        enemy4Catched=false;
    });
}
void widget::sendPoints()
{
    QTimer* timer;
    timer = new QTimer(this);

    // Conectar el temporizador al método sendLifes()
    connect(timer, &QTimer::timeout, this, &widget::sendLifes);

    // Establecer el intervalo de tiempo en milisegundos (por ejemplo, 1000 ms = 1 segundo)

    timer->start(50);
}

void widget::sendLifes()
{




    QString st="lifes: "+lifes.toString()+" Puntos: "+totalPoints.toString();


    if (Server1->socket->isOpen()) {
        Server1->socket->write(st.toUtf8());
        Server1->socket->flush();

    } else {
        qDebug() << "Error: El socket no está abierto";
    }
}
