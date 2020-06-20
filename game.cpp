#include "game.h"
#include "enemy.h"
#include "buildfiretowericon.h"
#include "buildwatertowericon.h"
#include "buildicetowericon.h"
#include "enemyteam.h"
#include "towerposition.h"
#include "enemyteamcontroller.h"
#include "upgradeicon.h"
#include "removeicon.h"

Game::Game()
{
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    score = new Score();
    scene->addItem(score);
    score->setPos(0,0);

    health = new Health();
    scene->addItem(health);
    health->setPos(0,20);

    upgrade = false;
    remove = false;

    BuildFireTowerIcon * FireIcon = new BuildFireTowerIcon;
    scene->addItem(FireIcon);
    FireIcon->setPos(720,0);

    BuildWaterTowerIcon * WaterIcon = new BuildWaterTowerIcon;
    scene->addItem(WaterIcon);
    WaterIcon->setPos(720,64);

    BuildIceTowerIcon * IceIcon = new BuildIceTowerIcon;
    scene->addItem(IceIcon);
    IceIcon->setPos(720,128);

    UpgradeIcon * upgrade_icon = new UpgradeIcon;
    scene->addItem(upgrade_icon);
    upgrade_icon->setPos(720,192);

    RemoveIcon * remove_icon = new RemoveIcon;
    scene->addItem(remove_icon);
    remove_icon->setPos(756,192);

    towerPositionVerify = false;

    EnemyTeamController * controller = new EnemyTeamController(3000,3,1,2000,4);

    setTowerPosition();

}

void Game::setCursor(QString filename,QPoint p)
{
    if(cursor){
        scene->removeItem(cursor);
        cursor = nullptr;
    }
    else{
        cursor = new QGraphicsPixmapItem();
        cursor->setPixmap(QPixmap(filename));
        cursor->setPos(p);
        scene->addItem(cursor);
    }
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}



void Game::positionClicked(QPointF p, int i)
{
    if(build){
        scene->addItem(build);
        build->setPos(p);
        build->setLocation(i);
        scene->removeItem(cursor);
        cursor = nullptr;
        build = nullptr;
        towerPositionVerify = false;
    }


}

void Game::setTowerPosition()
{
    position << QPoint(50,100) << QPoint(400,50) << QPoint(300,500) << QPoint(450,400) ;
    int n = position.size();
    for(int i=0; i<n ; i++){
        TowerPosition * pos = new TowerPosition(position[i],i);
        tower_position.append(pos);
        scene->addItem(pos);
        pos->setPos(position[i]);
    }
}

void Game::resetPositionStatus(int i)
{
    tower_position[i]->clearTowerPosition();
}

void Game::resetTowerStatus()
{
    remove = false;
    upgrade = false;
}


