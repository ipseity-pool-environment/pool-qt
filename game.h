#ifndef GAME_H
#define GAME_H

#include <QApplication>

#include <QObject>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMainWindow>
#include <iostream>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <vector>

#define TIMESTEP (1.0f / 60.0f)
#define V_ITERATIONS 8 //velocity iterations
#define P_ITERATIONS 3 //position iterations

namespace Balls {

typedef enum{
    Red,
    Yellow,
    Black,
    White
}BallsColor;

}


class MainWindow;


class holeContactListener : public b2ContactListener
{
public:
    void BeginContact(b2Contact* contact);
};



class Ball
{
public:
    Ball(b2World *world, QJsonObject configObj, int index, std::map<std::__cxx11::string, Balls::BallsColor> *colorMap);
    b2Body* m_body;
    ~Ball() {}
    
private:
    Balls::BallsColor m_color;
    float m_radius;
    
};




class Game : public QObject
{
    Q_OBJECT

public:

    Game();
    Game(MainWindow *w, QApplication *app);
    ~Game();
    bool createWorld();
    void createBallsBody();
    void buildTable();


    QApplication *app;

    void initTimer();

    Ball* b2whiteball;

    QList<Ball*> m_balls;
    
    QJsonObject configObj;

    //QList<Ball*> pottedBalls;

private:
    std::map<std::string, Balls::BallsColor> colorMap;
    QTimer m_myTimer;
    b2Body* cushions[10]; //bandes
    b2World* m_world;
    MainWindow *m_window;
    b2Vec2 m_gravity;
    b2BodyDef cushionBodyDef[10];
    b2PolygonShape cushionsShape[10];

    b2CircleShape m_holeShape;
    b2FixtureDef m_holeFixDef;
    //b2Body m_holeBody;
    b2BodyDef m_holeBodyDef;

    QString config;
    QFile configFile;
    QJsonDocument configDoc;


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
