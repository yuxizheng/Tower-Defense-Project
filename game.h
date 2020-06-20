#ifndef GAME_H
#define GAME_H

#include "tower.h"
#include "bullet.h"
#include "buildtowericon.h"
#include "score.h"
#include "health.h"
#include "towerposition.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QVector>

class Game: public QGraphicsView
{
public:
    Game();
    void setCursor(QString filename,QPoint p);
    void mouseMoveEvent(QMouseEvent *event);

    void positionClicked(QPointF p, int i);
    void setTowerPosition();
    void resetPositionStatus(int i);

    bool upgrade;
    bool remove;
    void resetTowerStatus();

    QVector<QPointF> position;
    QVector<TowerPosition*> tower_position;

    Tower * build;
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Score * score;
    Health * health;

    bool towerPositionVerify;

};

#endif // GAME_H
