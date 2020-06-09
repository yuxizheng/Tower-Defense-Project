#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
public slots:
    void shoot();
    double getMaxRange ();
    double getDistanceTravelled();
    void setMaxRange (double rng);
    void setDistanceTravelled(double dist);
private:
    double maxRange;
    double distanceTravelled;

};

#endif // BULLET_H
