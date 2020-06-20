#ifndef ENEMYTEAMCONTROLLER_H
#define ENEMYTEAMCONTROLLER_H

#include <QTimer>
#include <QObject>

#include "enemyteam.h"

class EnemyTeamController: public QObject
{
    Q_OBJECT
public:
    EnemyTeamController(int inter,int init, int increase, int speed, int wav);
public slots:
    void createEnemy();
private:
    int interval_time;
    int init_num;
    int increase_num;
    int enemy_speed;
    int wave;
    int count;
};

#endif // ENEMYTEAMCONTROLLER_H
