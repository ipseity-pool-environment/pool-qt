#ifndef GAME_H
#define GAME_H

#include <QApplication>

#include <QObject>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMainWindow>
#include "mainwindow.h"

class MainWindow;

class Game : public QObject
{
    Q_OBJECT

public:

    Game();
    Game(MainWindow *w, QApplication *a);
    ~Game();
    bool isRunning;
    QApplication *a;

    void initTimer();
    float32 timeStep, velocityIterations, positionIterations;
    b2Vec2 gravity;
    b2BodyDef groundBodyDef;
    b2Body* groundBody;
    b2PolygonShape groundBox;
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixtureDef;
    b2Vec2 position;
    float32 angle;

private:
    QTimer myTimer;
    b2World* world;
    MainWindow *window;



public slots:
    void update();

};



#endif // GAME_H
