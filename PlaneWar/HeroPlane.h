#pragma once
#include <QPixmap>
#include <array>
#include "Bullet.h"
#include <QPainter>

class HeroPlane
{
public:
    using BulletType = std::array<Bullet, BULLET_NUM>;

    HeroPlane();

    void shoot();
    void setPosition(int x, int y);
    
    void draw(QPainter &painter);

    const QPixmap& heroPlane() const;
    BulletType& bullets();

    QRect border();
    int x();
    int y();

private:
    QPixmap plane_;

    int x_;
    int y_;

    QRect rect_;

    BulletType bullets_;
    int recorder_;
};

