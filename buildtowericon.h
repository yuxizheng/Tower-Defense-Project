#ifndef BUILDTOWERICON_H
#define BUILDTOWERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildTowerIcon: public QGraphicsPixmapItem
{
public:
    BuildTowerIcon(QGraphicsItem * parent = 0);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILDTOWERICON_H
