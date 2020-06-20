#include "firetower.h"
#include "firebullet.h"
#include "game.h"
#include "enemy.h"

#include <QTimer>

extern Game * game;

FireTower::FireTower(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/tower/Resources/firetower.jpg"));

    level = 1;

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
    QLineF ln(QPointF(x()+24,y()+24),aimPoint);
    int angle = -1 * ln.angle();

    FireBullet * bullet = new FireBullet();
    bullet->setPos(x()+24,y()+24);

    bullet->setRotation(angle);
    game->scene->addItem(bullet);

    if(level>1){
        FireBullet * bullet2 = new FireBullet();
        bullet2->setPos(x()+24,y()+24);

        bullet2->setRotation(angle+10);
        game->scene->addItem(bullet2);
    }

}

void FireTower::aquire_target()
{
    Tower::aquire_target();
}

void FireTower::update()
{
    if(level<2){
        level++;
        setPixmap(QPixmap(":/tower/Resources/firetower2.jpg"));
    }
}





