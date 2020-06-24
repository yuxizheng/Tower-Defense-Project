#include "buildtowericon.h"
#include "game.h"

extern Game * game;

BuildTowerIcon::BuildTowerIcon(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{

}

void BuildTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void BuildTowerIcon::soundEmit()
{
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/Resources/clickButton.wav"));
    sound->play();
}
