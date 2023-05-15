#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <blocklist.h>
#include <pathfindinglist.h>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <listid.h>
#include <localserver.h>
#include <listback.h>
#include <backtraking.h>


class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);

    blockList *power;
    QGraphicsPixmapItem *pacman;
    void bL1_Clicked();
    int adapPosX(int id);
    int adapPosY(int id);
    void MoveFirstEnemy();
    void MoveSecondEnemy();
    void MoveThirdEnemy();
    void MoveFourthEnemy();
    void defineRouteFirstEnemy();
    void defineRouteSecondEnemy();
    void defineRouteThirdEnemy();
    void defineRouteFourthEnemy();
    void movePlayer();
    void colocatePoints();
    void checkCollision();
    void label();
    void catched();
    void defineBlokedPositions();
    void checkPoints();
    void server();
    void desapairEnemy1(QGraphicsPixmapItem *item);
    void desapairEnemy2(QGraphicsPixmapItem *item);
    void desapairEnemy3(QGraphicsPixmapItem *item);
    void desapairEnemy4(QGraphicsPixmapItem *item);
    void putBlocks(int amount);

    QVariant direcction=1;
    bool noPutIt(int level, int ID);


    int determinateDirecction(QString comas);
    blockList points;
    listID poinstGotten;
    int randNumber();
    int randNumber(int range);
    listID pointsVisited;


    int posxE1=0;
    int posYE1=0;
    QVariant blocks=53;
    bool inPower=false;
    bool powerTaken=false;

    int *vecMove;
    LocalServer *Server;
    QVariant level=1;
    QVariant lifes=3;
    QVariant totalPoints=0;
    QVariant auxTotalPoints=0;
    QVariant IDPower=1;

    QVariant counter=0;
    bool came=true;
    bool came1=true;
    bool came2=true;
    bool came3=true;
    bool controler=true;
    listID IDList;
    listID IDList1;
    listBack IDList2;
    listBack IDList3;




    bool tryToFixTheBug=false;
    bool keyUnlocked=false;

    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton *b_LevelI = new QPushButton("Level I");
    QGraphicsProxyWidget *L1;
    blockList list;
    pathFindingList listMatL1;

    QGraphicsPixmapItem *enemy1;
    QGraphicsPixmapItem *enemy2;
    QGraphicsPixmapItem *enemy3;
    QGraphicsPixmapItem *enemy4;

protected:
    void keyPressEvent(QKeyEvent *event) override;



};

#endif // CUSTOMWIDGET_H
