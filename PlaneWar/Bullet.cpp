#include "Bullet.h"

Bullet::Bullet()
    : bullet_{ BULLET_PATH }
    , x_{ (GAME_WIDTH - bullet_.width()) / 2 }
    , y_{ GAME_HEIGHT }
    , border_{x_, y_, bullet_.width(), bullet_.height()}
{
}

void Bullet::setPosition(int x, int y)
{
    isFree_ = false;
    x_ = x;
    y_ = y;
}

void Bullet::updatePosition()
{
    if (isFree_) 
    {
        return;
    }

    y_ -= speed_;
    border_.moveTo(x_, y_);

    if (y_ < -border_.height()) 
    {
        isFree_ = true;
    }
}

int& Bullet::x()
{
    return x_;
}

int& Bullet::y() 
{
    return y_;
}

int Bullet::speed() const
{
    return speed_;
}

bool& Bullet::is_free()
{
    return isFree_;
}

void Bullet::draw(QPainter& painter)
{
    if (!isFree_) 
    {
        painter.drawPixmap(x_, y_, bullet_);
    }
}

QRect Bullet::border()
{
    return border_;
}
