#ifndef ENEMYTEAMCONTROLLER_H
#define ENEMYTEAMCONTROLLER_H

#include <QTimer>
#include <QObject>

#include "enemyteam.h"

class EnemyTeamController: public QObject
{
    Q_OBJECT
public:
    EnemyTeamController(int inter, int init, int increase, int speed, int wav ,int health, QList <QPointF> points,QString pixx);
public slots:
    void createEnemy();
private:
    QList <QPointF> route;
    int interval_time;
    int init_num;
    int increase_num;
    int enemy_speed;
    int wave;
    int count;
    int health;
    QString pix;
    QTimer * timer;
};

#endif // ENEMYTEAMCONTROLLER_H
