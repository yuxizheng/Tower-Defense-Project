#include "firebullet.h"
#include "game.h"

#include <qmath.h>
#include <QTimer>

extern Game * game;

FireBullet::FireBullet()
{
    setPixmap(QPixmap(":/bullet/Resources/firebullet.jpg"));

    maxRange = 200;
    setDamage(6);
}

void FireBullet::shoot()
{
    ifCollideWithEnemy();

    int BULLET_INTERVAL = 6;

    double shootAngle = rotation();

    double dy = BULLET_INTERVAL * qSin(qDegreesToRadians(shootAngle));
    double dx = BULLET_INTERVAL * qCos(qDegreesToRadians(shootAngle));

    setPos(x()+dx, y()+dy);

    distanceTravelled += 6;

    if(distanceTravelled >= maxRange){
        game->scene->removeItem(this);
        delete this;
        return;
    }
}

