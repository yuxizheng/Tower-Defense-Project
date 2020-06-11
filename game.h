#ifndef GAME_H
#define GAME_H

#include "tower.h"
#include "bullet.h"
#include "buildtowericon.h"
#include "score.h"
#include "health.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class Game: public QGraphicsView
{
public:
    Game();
    void setCursor(QString filename,QPoint p);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    Tower * build;
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Score * score;
    Health * health;

};

#endif // GAME_H
