#pragma once

#include <QPixmap>

class Map
{
public:
    Map();

    void mapPosition();

    const QPixmap& map1() const;
    const QPixmap& map2() const;

    int map1PoxY();
    int map2PoxY();

    void draw(QPainter & painter);

private:
    QPixmap map1_;
    QPixmap map2_;

    int map1PoxY_;
    int map2PoxY_;

    int scrollSpeed_;
};

