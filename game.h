#ifndef GAME_H
#define GAME_H

#include <QApplication>

#include <QObject>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMainWindow>
#include "mainwindow.h"
#include <iostream>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

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
    b2BodyDef m_ballDef;
    b2FixtureDef m_fixtureDef;

    QString config;
    QFile configFile;
    QJsonDocument configDoc;
    QJsonObject configObj;
    QJsonArray ballsPosition;


public slots:
    void update();

};


bool cfgFileExists();


/////////////////////////////////////
/*
class Tablebody
{
    vector<b2BodyDef> cushionsBodyDef;

};*/


#endif // GAME_H
