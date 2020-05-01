#include "EnemyPlane.h"
#include "config.h"

EnemyPlane::EnemyPlane()
    : enemyPlane_{ ENEMY_PLANE_PATH }
    , border_{ x_, y_ , enemyPlane_.width(), enemyPlane_.height() }
{
}

void EnemyPlane::updatePosition()
{
    if (isFree_)
    {
        return;
    }

    y_ += speed_;
    border_.moveTo(x_, y_);

    if (y_ >=  GAME_HEIGHT + border_.height())
    {
        isFree_ = true;
    }
}

void EnemyPlane::draw(QPainter& painter)
{
    if (!isFree_)
    {
        painter.drawPixmap(x_, y_, enemyPlane_);
    }
}

int& EnemyPlane::x()
{
    return x_;
}

int& EnemyPlane::y()
{
    return y_;
}

bool& EnemyPlane::is_free()
{
    return isFree_;
}

QRect EnemyPlane::border()
{
    return border_;
}

//------------------------------------

Enemy::Enemy()
{
    recorder_ = 0;
    srand(time(NULL));
}

void Enemy::draw(QPainter& painter)
{
    for (auto& it : enemyPlanes_) 
    {
        it.draw(painter);
    }
}

void Enemy::enemyToScene()
{
    recorder_++;

    if (recorder_ < ENEMY_PLANE_INTERVAL) 
    {
        return;
    }

    recorder_ = 0;

    for (auto& it : enemyPlanes_) 
    {
        if (it.is_free()) 
        {
            it.is_free() = false;
            it.x() = rand() % (GAME_WIDTH - it.border().width());
            it.y() = -it.border().height();
            break;
        }
    }
}

void Enemy::updatePosition()
{
    for (auto& it : enemyPlanes_) 
    {
        if (!it.is_free()) 
        {
            it.updatePosition();
        }
    }
}

Enemy::EnemyPlaneType& Enemy::enemyPlanes()
{
    return enemyPlanes_;
}
