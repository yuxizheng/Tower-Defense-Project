#include "enemy.h"
#include "game.h"

#include <QTimer>
#include "qmath.h"

extern Game * game;

Enemy::Enemy(QList<QPointF> route, QString pix, int healthlevel)
{
    setData(1,"enemy");

    setPixmap(QPixmap(pix));

    health=healthlevel;

    points = route;

    point_index = 0;
    aim = points[0];

    rotateToPoint(aim);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation( -1 * ln.angle());
}

int Enemy::getHealth()
{
    return health;
}

void Enemy::healthDecrease(int damage)
{
    health -= damage;
    if(health<=0){
        game->score->increase();
        timer->disconnect();
        game->scene->removeItem(this);
        //delete this;
        return;
    }
}

void Enemy::ifCollideWithBullet()
{
    QList<QGraphicsItem * > colliding_item = this->collidingItems();

    for( size_t i=0, n=colliding_item.size(); i < n ; i++){
        Bullet * bullet = dynamic_cast<Bullet *>(colliding_item[i]);
        if (bullet){
            healthDecrease(bullet->getDamage());
            game->scene->removeItem(bullet);

        }
    }
}


void Enemy::move_forward()
{
    ifCollideWithBullet();

    QLineF ln(pos(),aim);
    if (ln.length()<5){
        point_index++;
        if(point_index>=points.size()){
            game->health->decrease();
            game->scene->removeItem(this);
            delete this;
            return;
        }
        aim = points[point_index];
        rotateToPoint(aim);
    }

    int ENEMY_INTERVAL = 5;

    double shootAngle = rotation();

    double dy = ENEMY_INTERVAL * qSin(qDegreesToRadians(shootAngle));
    double dx = ENEMY_INTERVAL * qCos(qDegreesToRadians(shootAngle));

    setPos(x()+dx, y()+dy);

}
