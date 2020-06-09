#include "game.h"
#include "enemy.h"

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

    Enemy * enemy = new Enemy();
    scene->addItem(enemy);

    BuildTowerIcon * icon = new BuildTowerIcon;
    scene->addItem(icon);
}

void Game::setCursor(QString filename)
{
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
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


