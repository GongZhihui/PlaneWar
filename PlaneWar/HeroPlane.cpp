#include "HeroPlane.h"
#include "config.h"

HeroPlane::HeroPlane()
{
    plane_.load(HERO_PATH);

    x_ = (GAME_WIDTH - plane_.width()) / 2;
    y_ = (GAME_HEIGHT - plane_.height());
    
    rect_.setWidth(plane_.width());
    rect_.setHeight(plane_.height());
    rect_.moveTo(x_, y_);
}

void HeroPlane::shoot()
{
    do
    {
        recorder_++;
        if (recorder_ < BULLET_INTERVAL)
        {
            break;
        }

        recorder_ = 0;

        for (auto& it : bullets_)
        {
            if (it.is_free())
            {
                it.is_free() = false;
                it.x() = x_ + rect_.width() / 2 - 10;
                it.y() = y_ - 25;
                break;
            }
        }

    } while (0);
    
    for (auto& it : bullets_)
    {
        if (!it.is_free())
        {
            it.updatePosition();
        }
    }

}

void HeroPlane::setPosition(int x, int y)
{
    x_ = x;
    y_ = y;
    rect_.moveTo(x_, y_);
}

void HeroPlane::draw(QPainter& painter)
{
    painter.drawPixmap(x_, y_, plane_);

    for (auto& it : bullets_)
    {
        it.draw(painter);
    }
}

const QPixmap& HeroPlane::heroPlane() const
{
    return plane_;
}

HeroPlane::BulletType& HeroPlane::bullets()
{
    return bullets_;
}

QRect HeroPlane::border()
{
    return rect_;
}

int HeroPlane::x()
{
    return x_;
}

int HeroPlane::y()
{
    return y_;
}
