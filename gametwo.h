#ifndef GAMETWO_H
#define GAMETWO_H

#include "game.h"

class GameTwo:
{
public:
    GameTwo(QWidget* parent=NULL);

    void init();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void gameOver();
    void displayGameOverWindow(QString textToDisplay);
    void displayLeveltwoWindow();

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
    QGraphicsPixmapItem * back;


    bool towerPositionVerify;


};

#endif // GAMETWO_H
