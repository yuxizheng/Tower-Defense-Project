#include "enemyteam.h"
#include "game.h"

extern Game * game;

EnemyTeam::EnemyTeam()
{

}

void EnemyTeam::setEnemyTeam(int spe, int num, QString pix, QList<QPointF> rou)
{
    speed = spe;
    pixmap = pix;
    number = num;
    route = rou;
    enemySpawned = 0;

    timer = new QTimer(this);
    timer->start(speed);
    connect(timer,SIGNAL(timeout()),this,SLOT(reproduceEnemy()));
}

void EnemyTeam::reproduceEnemy()
{
   Enemy * enemy = new Enemy(route, pixmap, 3);
   game->scene->addItem(enemy);
   enemy->setPos(route[0]);
   enemySpawned += 1;
   if (enemySpawned >= number){
            timer->disconnect();
   }

}
