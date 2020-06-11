#include "game.h"
#include "enemy.h"
#include "buildfiretowericon.h"
#include "buildwatertowericon.h"
#include "enemyteam.h"

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

    QList<QPointF> points;
    points<< QPointF(0,0) << QPointF(450,450) << QPointF(0,600);
    EnemyTeam * team = new EnemyTeam();
    team->setEnemyTeam(1500, 5, ":/enemy/Resources/enemy.jpg", points);

    BuildFireTowerIcon * FireIcon = new BuildFireTowerIcon;
    scene->addItem(FireIcon);
    FireIcon->setPos(720,0);

    BuildWaterTowerIcon * WaterIcon = new BuildWaterTowerIcon;
    scene->addItem(WaterIcon);
    WaterIcon->setPos(720,80);
}

void Game::setCursor(QString filename,QPoint p)
{
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    cursor->setPos(p);
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(build){
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = nullptr;
        build = nullptr;
    }
    else{
        QGraphicsView::mousePressEvent(event);
    }
}


