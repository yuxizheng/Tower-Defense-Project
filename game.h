#ifndef GAME_H
#define GAME_H

#include "tower.h"
#include "bullet.h"
#include "buildtowericon.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class Game: public QGraphicsView
{
public:
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * build;

};

#endif // GAME_H
