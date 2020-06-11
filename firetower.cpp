#include "firetower.h"
#include "firebullet.h"
#include "game.h"
#include "enemy.h"

#include <QTimer>

extern Game * game;

FireTower::FireTower(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/tower/Resources/firetower.jpg"));

    startTimer();

}

void FireTower::startTimer()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void FireTower::attack()
{
    FireBullet * bullet = new FireBullet();
    bullet->setPos(x()+24,y()+24);

    QLineF ln(QPointF(x()+24,y()+24),aimPoint);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void FireTower::aquire_target()
{
    Tower::aquire_target();
}




