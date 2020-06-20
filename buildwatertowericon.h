#ifndef BUILDWATERTOWERICON_H
#define BUILDWATERTOWERICON_H

#include "buildtowericon.h"

class BuildWaterTowerIcon: public BuildTowerIcon
{
public:
    BuildWaterTowerIcon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILDWATERTOWERICON_H
