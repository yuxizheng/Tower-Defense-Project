#include "icebullet.h"
#include "game.h"
#include "enemy.h"

#include <QMediaPlayer>
#include <qmath.h>
#include <QTimer>

extern Game * game;

IceBullet::IceBullet()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/Resources/ice.wav"));
    bulletsound->play();

    setPixmap(QPixmap(":/bullet/Resources/icebullet.jpg"));

    maxRange = 300;
    slow = 1;
}

void IceBullet::ifCollideWithEnemy()
{
    QList<QGraphicsItem * > colliding_item = this->collidingItems();
    for( size_t i=0, n=colliding_item.size(); i < n ; i++){
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_item[i]);
        if (enemy){
            enemy->setRate(slow);

            game->scene->removeItem(this);

            return;
        }
    }
}

void IceBullet::shoot()
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
