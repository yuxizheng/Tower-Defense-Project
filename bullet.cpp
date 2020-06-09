#include "bullet.h"
#include "game.h"

#include <QPixmap>
#include <QTimer>
#include <qmath.h>

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/bullet/Resources/bullet.jpg"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(50);

    maxRange = 100;
    distanceTravelled = 0;
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





