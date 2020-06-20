#include "buildicetowericon.h"
#include "game.h"
#include "icetower.h"

extern Game * game;

BuildIceTowerIcon::BuildIceTowerIcon(QGraphicsItem *parent){
    setPixmap(QPixmap(":/icons/Resources/buildIceTowericon.jpg"));
}

void BuildIceTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->build){
        game->build = new IceTower();
        game->setCursor(QString(":/tower/Resources/icetower.jpg"),QPoint(720,128));
    }
}

