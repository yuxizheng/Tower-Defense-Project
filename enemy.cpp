#include "enemy.h"

#include <QTimer>
#include "qmath.h"

Enemy::Enemy(QGraphicsItem *parents)
{
    setPixmap(QPixmap(":/enemy/Resources/enemy.jpg"));

    points<< QPointF(200,200) << QPointF(400,200); //down right
    point_index = 0;
    aim = points[0];

    rotateToPoint(aim);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation( -1 * ln.angle());
}

void Enemy::move_forward()
{
    QLineF ln(pos(),aim);
    if (ln.length()<5){
        point_index++;
        if(point_index>=points.size()){
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
