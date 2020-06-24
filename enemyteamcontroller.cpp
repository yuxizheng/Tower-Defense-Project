#include "enemyteamcontroller.h"
#include "game.h"

extern Game * game;

EnemyTeamController::EnemyTeamController(int inter, int init, int increase, int speed, int wav ,int heal,QList <QPointF> points,QString pixx)
{
    route = points;
    interval_time = inter;
    init_num = init;
    increase_num = increase;
    enemy_speed = speed;
    wave = wav;
    count = 0;
    health = heal;
    pix = pixx;

    timer = new QTimer(this);
    timer->start(inter);
    connect(timer,SIGNAL(timeout()),this,SLOT(createEnemy()));

}

void EnemyTeamController::createEnemy()
{
    if(count<wave){
        EnemyTeam * team = new EnemyTeam();
        team->setEnemyTeam( enemy_speed, init_num, health ,pix, route);
        init_num += increase_num;
        count+=1;
    }
    else{
        timer->stop();
    }
}


