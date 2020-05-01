#include "Bomb.h"
#include "config.h"

Bomb::Bomb()
{
    for (int i = 1; i <= BOMB_MAX; i++)
    {
        QString path = QString(BOMB_PATH).arg(i);
        bombPix_.push_back(QPixmap(path));
    }
}

void Bomb::updateInfo()
{
    if (isFree_)
    {
        return;
    }

    recorder_++;

    if (recorder_ < BOMB_INTERVAL)
    {
        return;
    }

    recorder_ = 0;
    index_++;
    
    if (index_ > BOMB_MAX - 1)
    {
        index_ = 0;
        isFree_ = true;
    }

}

bool& Bomb::is_free()
{
    return isFree_;
}

int& Bomb::x()
{
    return x_;
}

int& Bomb::y()
{
    return y_;
}

void Bomb::draw(QPainter& painter)
{
    if (!isFree_) 
    {
        painter.drawPixmap(x_, y_, bombPix_[index_]);
    }
}

void BombEffect::show(int x, int y)
{
    for (auto& it : bombs_) 
    {
        if (it.is_free()) 
        {
            it.is_free() = false;
            it.x() = x;
            it.y() = y;
            break;
        }
    }
}

void BombEffect::update()
{
    for (auto& it : bombs_) 
    {
        if (!it.is_free()) 
        {
            it.updateInfo();
        }
    }
}

void BombEffect::draw(QPainter& painter)
{
    for (auto& it : bombs_) 
    {
        it.draw(painter);
    }
}

