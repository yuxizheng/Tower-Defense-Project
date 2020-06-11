#ifndef BUILDFIRETOWERICON_H
#define BUILDFIRETOWERICON_H

#include "buildtowericon.h"

class BuildFireTowerIcon: public BuildTowerIcon
{
public:
    BuildFireTowerIcon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILDFIRETOWERICON_H
