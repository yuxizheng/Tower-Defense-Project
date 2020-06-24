#include "buildwatertowericon.h"
#include "game.h"
#include "watertower.h"

extern Game * game;

BuildWaterTowerIcon::BuildWaterTowerIcon(QGraphicsItem *parent){
    setPixmap(QPixmap(":/icons/Resources/BuildWaterTowericon.jpg"));
}

void BuildWaterTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    soundEmit();
    if (!game->build){
        game->build = new WaterTower();
        game->setCursor(QString(":/tower/Resources/watertower.jpg"),QPoint(720,80));
    }
}
