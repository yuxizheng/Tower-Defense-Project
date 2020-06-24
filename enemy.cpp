#include "enemy.h"
#include "game.h"

#include <QTimer>
#include "qmath.h"

extern Game * game;

Enemy::Enemy(QList<QPointF> route, QString pix, int healthlevel)
{

    originalRate = 5;

    rate = 5;

    rateChanged = false;
    rateChangeCount = 0;

    setPixmap(QPixmap(pix));

    health = healthlevel;
    init_health = healthlevel;

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
        game->score->increase(init_health);
        game->recordWave();
        timer->stop();
        game->scene->removeItem(this);
        delete this;
        return;
    }
}



void Enemy::setRate(int rate)
{
    this->rate = rate;
    rateChanged = true;

}


void Enemy::move_forward()
{
    if(rateChanged==true){
        rateChangeCount++;
        if(rateChangeCount>20){
            setRate(originalRate);
            rateChangeCount=0;
            rateChanged=false;
        }
    }

    QLineF ln(pos(),aim);
    if (ln.length()<5){
        point_index++;
        if(point_index>=points.size()){
            game->health->decrease();
            if(game->health->getHealth()<0){
                game->displayGameOverWindow("you lose");
            }
            game->scene->removeItem(this);
            delete this;
            return;
        }
        aim = points[point_index];
        rotateToPoint(aim);
    }



    double shootAngle = rotation();

    double dy = rate * qSin(qDegreesToRadians(shootAngle));
    double dx = rate * qCos(qDegreesToRadians(shootAngle));

    setPos(x()+dx, y()+dy);

}
