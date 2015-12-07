#ifndef GAME_H
#define GAME_H

#include <QApplication>

#include <QObject>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMainWindow>
#include "mainwindow.h"

#define TIMESTEP (1.0f / 60.0f)
#define V_ITERATIONS 8 //velocity iterations
#define P_ITERATIONS 3 //position iterations

class MainWindow;

class Game : public QObject
{
    Q_OBJECT

public:

    Game();
    Game(MainWindow *w, QApplication *app);
    ~Game();
    bool createWorld();


    QApplication *app;

    void initTimer();

    b2Body* b2whiteball;
    b2Body* b2balls[15];
    b2CircleShape ballShape;

private:
    QTimer m_myTimer;
    b2Body* cushions[4]; //bandes
    b2World* m_world;
    MainWindow *m_window;
    b2Vec2 m_gravity;
    b2BodyDef cushionBodyDef[4];
    b2PolygonShape cushionsShape[4];
    b2BodyDef ballDef;
    b2FixtureDef fixtureDef;
    b2Vec2 boxposition;
    float32 angle;



public slots:
    void update();

};



/////////////////////////////////////
/*
class Tablebody
{
    vector<b2BodyDef> cushionsBodyDef;

};*/


#endif // GAME_H
