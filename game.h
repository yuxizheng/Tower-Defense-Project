#ifndef GAME_H
#define GAME_H

#include "tower.h"
#include "bullet.h"
#include "buildtowericon.h"
#include "score.h"
#include "health.h"
#include "towerposition.h"
#include "button.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QVector>
#include <QObject>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent=NULL);

    void init();
    void init2();
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
    void recordWave();

    QVector<QPointF> position;
    QVector<TowerPosition*> tower_position;

    Tower * build;
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Score * score;
    Health * health;
    QGraphicsPixmapItem * back;

    bool towerPositionVerify;

    int enemyWaveRecorder;
    int level;

public slots:
    void home();
    void leveltwo();
};

#endif // GAME_H
