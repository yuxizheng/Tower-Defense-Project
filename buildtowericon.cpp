#include "buildtowericon.h"
#include "game.h"

extern Game * game;

BuildTowerIcon::BuildTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/icons/Resources/buildTowericon.jpg"));

}

void BuildTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->build){
        game->build = new Tower();
        game->setCursor(QString(":/tower/Resources/tower.jpg"));
    }
}
