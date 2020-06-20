#include "bullet.h"
#include "game.h"
#include "enemy.h"

#include <QPixmap>
#include <QTimer>
#include <qmath.h>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    maxRange = 100;
    distanceTravelled = 0;

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(50);

}

void Bullet::shoot(){




}



double Bullet::getMaxRange()
{
    return maxRange;
}

double Bullet::getDistanceTravelled()
{
    return distanceTravelled;
}

void Bullet::setMaxRange(double rng)
{
    maxRange = rng;
}

void Bullet::setDistanceTravelled(double dist)
{
    distanceTravelled = dist;
}



void Bullet::setDamage(int damage)
{
    this->damage = damage;
}

int Bullet::getDamage()
{
    return damage;
}

void Bullet::ifCollideWithEnemy()
{
    QList<QGraphicsItem * > colliding_item = this->collidingItems();
    for( size_t i=0, n=colliding_item.size(); i < n ; i++){
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_item[i]);
        if (enemy){
            enemy->healthDecrease(getDamage());

            game->scene->removeItem(this);

            return;
        }
    }
}






