#ifndef BUILDICETOWERICON_H
#define BUILDICETOWERICON_H

#include "buildtowericon.h"

class BuildIceTowerIcon: public BuildTowerIcon
{
public:
    BuildIceTowerIcon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILDICETOWERICON_H
