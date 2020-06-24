#ifndef BUILDTOWERICON_H
#define BUILDTOWERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class BuildTowerIcon: public QGraphicsPixmapItem
{
public:
    BuildTowerIcon(QGraphicsItem * parent = 0);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void soundEmit();
};

#endif // BUILDTOWERICON_H
