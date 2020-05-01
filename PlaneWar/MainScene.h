#pragma once

#include <QtWidgets/QWidget>
#include <QTimer>
#include "Map.h"
#include "HeroPlane.h"
#include "EnemyPlane.h"
#include "Bomb.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = Q_NULLPTR);

    void initScene();

    void playGame();

    void updatePosition();

    void paintEvent(QPaintEvent * ev) override;
    void mouseMoveEvent(QMouseEvent * ev) override;

    void collisionDetection();

private:
    void borderCheck(int &x, int &y);

private:
    QTimer timer_;
    Map map_;

    HeroPlane heroPlane_;
    Enemy enemy_;
    BombEffect bombEffect_;
};
