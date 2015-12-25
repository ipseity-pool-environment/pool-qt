#ifndef GAME_H
#define GAME_H

#include <ball.h>
#include <QObject>
#include <QApplication>
#include <QTimer>
#include <QFile>

#define TIMESTEP (1.0f / 60.0f)
#define V_ITERATIONS 8 //velocity iterations
#define P_ITERATIONS 3 //position iterations



namespace Type{
typedef enum{
    Hole,
    Ball
}Type;
}



class Ball;
class MainWindow;
class Game;
class Hole;



struct UserData
{
    Type::Type type;
    Game *game;
    Ball *ball;
    Hole *hole;
};



class moveBodyTask{
public:
    moveBodyTask(Ball *ball, int i);
    void move();

private:
    Ball* m_ball;
    int m_index;
};




class holeContactListener : public b2ContactListener
{
public:
    void BeginContact(b2Contact* contact);
};





class Game : public QObject
{
    Q_OBJECT

public:

    Game();
    Game(MainWindow *w, QApplication *app);
    ~Game();
    //bool createWorld();
    void createBallsBody();
    void createHoles();

    void buildTable();
    void potBall(Ball *ball);


    holeContactListener listener;

    QApplication *app;

    void initTimer();

    Ball* b2whiteball;

    QList<Ball*> m_balls;
    QList<Ball*> m_pottedBalls;
    QJsonObject configObj;

    b2World* m_world;
    //QList<Ball*> pottedBalls;

private:
    std::map<QString, Balls::BallsColor> colorMap;
    QList<Hole*> m_hole;

    QTimer m_myTimer;
    b2Body* cushions[10]; //bandes
    MainWindow *m_window;
    b2Vec2 m_gravity;
    b2BodyDef cushionBodyDef[10];
    b2PolygonShape cushionsShape[10];


    QString config;
    QFile configFile;
    QJsonDocument configDoc;

    QList<moveBodyTask*> m_task;

public slots:
    void update();

};


bool cfgFileExists();
bool getBallAndHole(b2Contact* contact, Ball *&ball);


/////////////////////////////////////
/*
class Tablebody
{
    vector<b2BodyDef> cushionsBodyDef;

};*/


#endif // GAME_H
