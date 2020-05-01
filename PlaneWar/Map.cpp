#include "Map.h"
#include "config.h"
#include <QPainter>

Map::Map()
    : map1_{ MAP_PATH }
    , map2_{ MAP_PATH }
{
}

void Map::updatePosition()
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

void Map::draw(QPainter& painter)
{
    painter.drawPixmap(0, map1PoxY_, map1_);
    painter.drawPixmap(0, map2PoxY_, map2_);
}
