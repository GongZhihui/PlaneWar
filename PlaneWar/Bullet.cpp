#include "Bullet.h"

Bullet::Bullet()
{
    int ret = bullet_.load(BULLET_PATH);
    x_ = (GAME_WIDTH - bullet_.width()) / 2;
    y_ = GAME_HEIGHT;
    isFree_ = true;
    speed_ = BULLET_SPEED;

    border_.setWidth(bullet_.width());
    border_.setHeight(bullet_.height());
    border_.moveTo(x_, y_);
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

const QPixmap& Bullet::bullet() const
{
    return bullet_;
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
