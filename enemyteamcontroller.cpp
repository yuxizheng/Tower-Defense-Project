#include "enemyteamcontroller.h"

EnemyTeamController::EnemyTeamController(int inter, int init, int increase, int speed, int wav)
{
    interval_time = inter;
    init_num = init;
    increase_num = increase;
    enemy_speed = speed;
    wave = wav;
    count = 0;

    QTimer * timer = new QTimer(this);
    timer->start(inter);
    connect(timer,SIGNAL(timeout()),this,SLOT(createEnemy()));

}

void EnemyTeamController::createEnemy()
{
    if(count<wave){
        QList<QPointF> points;
        points<< QPointF(0,0) << QPointF(450,450) << QPointF(0,600);
        EnemyTeam * team = new EnemyTeam();
        team->setEnemyTeam( enemy_speed, init_num, increase_num, ":/enemy/Resources/enemy.jpg", points);
        init_num += increase_num;
        count++;
    }
}


