#include "bullet.h"
#include "game.h"
#include "enemy.h"

#include <QPixmap>
#include <QTimer>
#include <qmath.h>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    setData(1,"bullet");

    maxRange = 100;
    distanceTravelled = 0;

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(50);

}

void Bullet::shoot(){
    int BULLET_INTERVAL = 30;

    double shootAngle = rotation();

    double dy = BULLET_INTERVAL * qSin(qDegreesToRadians(shootAngle));
    double dx = BULLET_INTERVAL * qCos(qDegreesToRadians(shootAngle));

    setPos(x()+dx, y()+dy);

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





