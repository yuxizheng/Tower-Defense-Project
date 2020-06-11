#ifndef FIREBULLET_H
#define FIREBULLET_H

#include "bullet.h"

class FireBullet: public Bullet
{
public:
    FireBullet();
public slots:
    void shoot() override;

};

#endif // FIREBULLET_H
