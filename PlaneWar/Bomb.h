#pragma once
#include <QPixmap>
#include <vector>
#include <array>
#include <QPainter>
#include "config.h"

class Bomb
{
public:
    Bomb();
    void updateInfo();
    bool& is_free();
    int& x();
    int& y();

    void draw(QPainter& painter);

private:
    std::vector<QPixmap> bombPix_;

    int x_{ 0 };
    int y_{ 0 };

    bool isFree_{ true };
    int recorder_{ 0 };
    int index_{ 0 };
};

//--------------------------------------------

class BombEffect 
{
public:
    BombEffect() = default;

    void show(int x, int y);
    void update();
    void draw(QPainter& painter);

private:
    std::array<Bomb, BOMB_MAX> bombs_;
};
