#ifndef FIRETOWER_H
#define FIRETOWER_H

#include "tower.h"

class FireTower: public Tower
{
    Q_OBJECT
public:
    FireTower(QGraphicsItem *parent = 0);
    void startTimer();
    void attack() override;
    void update() override;
    int level;
public slots:
    void aquire_target() override;
};

#endif // FIRETOWER_H
