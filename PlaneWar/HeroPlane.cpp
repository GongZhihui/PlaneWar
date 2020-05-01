#include "HeroPlane.h"
#include "config.h"

HeroPlane::HeroPlane()
    : plane_{ HERO_PATH }
    , x_{ (GAME_WIDTH - plane_.width()) / 2 }
    , y_{ GAME_HEIGHT - plane_.height() }
    , border_{x_, y_, plane_.width(),plane_.height() }
{
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

        // 找到一个空闲的子弹就break
        for (auto& it : bullets_)
        {
            if (it.is_free())
            {
                it.setPosition(x_ + border_.width() / 2 - 10, y_ - 25);
                break;
            }
        }

    } while (0);
    
    // 更新所有子弹的位置
    for (auto& it : bullets_)
    {
        it.updatePosition();
    }
}

void HeroPlane::setPosition(int x, int y)
{
    x_ = x;
    y_ = y;
    border_.moveTo(x_, y_);
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
    return border_;
}

int HeroPlane::x()
{
    return x_;
}

int HeroPlane::y()
{
    return y_;
}
