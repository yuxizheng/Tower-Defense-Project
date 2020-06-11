#include "firebullet.h"

#include <qmath.h>
#include <QTimer>

FireBullet::FireBullet()
{
    setPixmap(QPixmap(":/bullet/Resources/firebullet.jpg"));

    setDamage(6);
}

void FireBullet::shoot()
{
    int BULLET_INTERVAL = 6;

    double shootAngle = rotation();

    double dy = BULLET_INTERVAL * qSin(qDegreesToRadians(shootAngle));
    double dx = BULLET_INTERVAL * qCos(qDegreesToRadians(shootAngle));

    setPos(x()+dx, y()+dy);
}
