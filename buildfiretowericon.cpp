#include "buildfiretowericon.h"
#include "game.h"
#include "firetower.h"

extern Game * game;

BuildFireTowerIcon::BuildFireTowerIcon(QGraphicsItem *parent){
    setPixmap(QPixmap(":/icons/Resources/buildFireTowericon.jpg"));
}

void BuildFireTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->build){
        game->build = new FireTower();
        game->setCursor(QString(":/tower/Resources/firetower.jpg"),QPoint(720,0));
    }
}
