#include "waterbullet.h"
#include "game.h"

#include <qmath.h>
#include <QTimer>

extern Game * game;

WaterBullet::WaterBullet()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/Resources/water.wav"));
    bulletsound->play();

    setPixmap(QPixmap(":/bullet/Resources/waterbullet.jpg"));

    maxRange = 150;
    setDamage(10);
}

void WaterBullet::shoot()
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
