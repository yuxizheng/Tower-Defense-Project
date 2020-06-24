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
    void setRate(int rate);
public slots:
    void move_forward();
private:
    int init_health;
    bool rateChanged;
    int rateChangeCount;
    int rate;
    int originalRate; //the width of each step
    QList<QPointF> points;
    QPointF aim;
    int point_index;
    int health;
    QTimer * timer;
    int rateChangerCount;
};

#endif // ENEMY_H
