#include "MainScene.h"
#include "config.h"
#include <qicon>
#include <QPainter>
#include <QMouseEvent>
#include <QSound>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
    playGame();
}

void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));

    timer_.setInterval(GAME_RATE);
}

void MainScene::playGame()
{
    QSound::play(SOUND_BACKGROUND);

    timer_.start();
    connect(&timer_, &QTimer::timeout, [=]() {
        enemy_.enemyToScene();
        updatePosition();
        update();
        collisionDetection();
    });

}

void MainScene::updatePosition()
{
    map_.updatePosition();
    heroPlane_.shoot();
    enemy_.updatePosition();
    bombEffect_.update();
}

void MainScene::paintEvent(QPaintEvent* ev)
{
    QPainter painter(this);

    map_.draw(painter);
    heroPlane_.draw(painter);
    enemy_.draw(painter);
    bombEffect_.draw(painter);
} 

void MainScene::mouseMoveEvent(QMouseEvent* ev)
{
    int x = ev->x() - heroPlane_.border().width() * 0.5;
    int y = ev->y() - heroPlane_.border().height() * 0.5;
    borderCheck(x, y);
    heroPlane_.setPosition(x, y);
}

void MainScene::collisionDetection()
{
    for (auto& enemyPlane : enemy_.enemyPlanes()) 
    {
        if (enemyPlane.is_free())
            continue;

        for (auto& bullet : heroPlane_.bullets()) 
        {
            if (bullet.is_free())
                continue;

            if (enemyPlane.border().intersects(bullet.border())) 
            {
                enemyPlane.is_free() = true;
                bullet.is_free() = true;
                bombEffect_.show(enemyPlane.x(), enemyPlane.y());
                QSound::play(SOUND_BOMB);
            }
        }
    }
}

void MainScene::borderCheck(int& x, int& y)
{
    if (x <= 0) 
    {
        x = 0;
    }
    if (x >= GAME_WIDTH - heroPlane_.border().width()) 
    {
        x = GAME_WIDTH - heroPlane_.border().width();
    }

    if (y <= 0)
    {
        y = 0;
    }
    if (y >= GAME_HEIGHT - heroPlane_.border().height())
    {
        y = GAME_HEIGHT - heroPlane_.border().height();
    }
}
