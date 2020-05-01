#pragma once
#include <QPixmap>
#include "config.h"
#include <QPainter>

class Bullet
{
public:
    Bullet();

    void setPosition(int x, int y);
    void updatePosition();

    int& x();
    int& y();
    int speed() const;
    bool& is_free();

    void draw(QPainter &painter);
    QRect border();

private:
    QPixmap bullet_;
    int x_;
    int y_;
    QRect border_;

    int speed_{ BULLET_SPEED };
    bool isFree_{ true };
};

