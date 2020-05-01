#pragma once
#include <QPainter>
#include <QPixmap>
#include <array>
#include "config.h"

class EnemyPlane
{
public:
    EnemyPlane();

    void updatePosition();
    void draw(QPainter& painter);

    int& x();
    int& y();
    bool& is_free();
    QRect border();

private:
    QPixmap enemyPlane_;

    int x_;
    int y_;
    int speed_;
    bool isFree_;

    QRect border_;
};


// --------------------------

class Enemy 
{
public:
    using EnemyPlaneType = std::array<EnemyPlane, ENEMY_PLANE_NUM>;

    Enemy();

    void draw(QPainter& painter);

    void enemyToScene();
    void updatePosition();
    EnemyPlaneType& enemyPlanes();

private:
    EnemyPlaneType enemyPlanes_;

    int recorder_;
};
