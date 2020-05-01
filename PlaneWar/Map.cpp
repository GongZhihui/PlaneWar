#include "Map.h"
#include "config.h"
#include <QPainter>

Map::Map()
{
    map1_.load(MAP_PATH);
    map2_.load(MAP_PATH);
    map1PoxY_ = -GAME_HEIGHT;
    map2PoxY_ = 0;

    scrollSpeed_ = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    map1PoxY_ += scrollSpeed_;
    if (map1PoxY_ > 0) 
    {
        map1PoxY_ = -GAME_HEIGHT;
    }

    map2PoxY_ += scrollSpeed_;
    if (map2PoxY_ > GAME_HEIGHT)
    {
        map2PoxY_ = 0;
    }
}

const QPixmap& Map::map1() const
{
    return map1_;
}

const QPixmap& Map::map2() const
{
    return map2_;
}

int Map::map1PoxY()
{
    return map1PoxY_;
}

int Map::map2PoxY()
{
    return map2PoxY_;
}

void Map::draw(QPainter& painter)
{
    painter.drawPixmap(0, map1PoxY_, map1_);
    painter.drawPixmap(0, map2PoxY_, map2_);
}
