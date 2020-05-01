#pragma once

#include <QPixmap>

class Map
{
public:
    Map();

    void updatePosition();

    const QPixmap& map1() const;
    const QPixmap& map2() const;

    void draw(QPainter & painter);

private:
    QPixmap map1_;
    QPixmap map2_;

    int map1PoxY_{ -GAME_HEIGHT };
    int map2PoxY_{ 0 };

    int scrollSpeed_{ MAP_SCROLL_SPEED };
};

