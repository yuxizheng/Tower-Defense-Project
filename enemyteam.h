#ifndef ENEMYTEAM_H
#define ENEMYTEAM_H

#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QTimer>

class EnemyTeam: public QObject
{
    Q_OBJECT
public:
    EnemyTeam();
    void setEnemyTeam(int spe,int num, int heal,QString pix, QList<QPointF> rou);
public slots:
    void reproduceEnemy();
private:
    int speed;
    int number;
    int health;
    int enemySpawned;
    QList<QPointF> route;
    QString pixmap;
    QTimer * timer;
};

#endif // ENEMYTEAM_H
