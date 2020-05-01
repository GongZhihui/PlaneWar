#pragma once
#include <QPixmap>
#include <qvector>
#include <array>
#include <QPainter>
#include "config.h"
#include <mutex>

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
    int x_ = 0;
    int y_ = 0;

    QVector<QPixmap> bombPix_;

    bool isFree_ = true ;
    int recorder_ = 0 ;
    int index_ = 0 ;

    std::mutex mtx_;
};


//--------------------------------------------

class BombEffect 
{
public:
    BombEffect();

    void show(int x, int y);
    void update();
    void draw(QPainter& painter);

private:
    std::array<Bomb, BOMB_MAX> bombs_;
};
