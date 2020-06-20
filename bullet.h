#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
    QTimer * timer;
    double getMaxRange ();
    double getDistanceTravelled();
    void setMaxRange (double rng);
    void setDistanceTravelled(double dist);
    void setDamage(int damage);
    int getDamage();
    virtual void ifCollideWithEnemy();
public slots:
    virtual void shoot();

protected:
    int damage;
    double maxRange;
    double distanceTravelled;
};

#endif // BULLET_H
