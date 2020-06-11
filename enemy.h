#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy (QList<QPointF> route, QString pix, int healthlevel);
    void rotateToPoint(QPointF p);
    int getHealth();
    void healthDecrease(int damage);
    void ifCollideWithBullet();
public slots:
    void move_forward();
private:
    QList<QPointF> points;
    QPointF aim;
    int point_index;
    int health;
    QTimer * timer;
};

#endif // ENEMY_H
