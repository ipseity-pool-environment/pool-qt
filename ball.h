#ifndef BALL_H
#define BALL_H

namespace Balls {

typedef enum{
    Red,
    Yellow,
    Black,
    White
}BallsColor;
}

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <map>
#include <Box2D/Box2D.h>
#include "game.h"

class Game;
struct UserData;

class Ball
{
public:
    Ball(Game *game, QJsonObject configObj, int index, std::map<QString, Balls::BallsColor> *colorMap);
    ~Ball();
    b2Body* m_body;

    void startContact() { m_contact = true; }
    void endContact() { m_contact = false; }
    UserData *userData;
private:
    Balls::BallsColor m_color;
    float m_radius;
    bool m_contact;

};

class Hole
{
public:
    Hole() {m_body = NULL; userData = NULL;}
    ~Hole() {}
    b2Body *m_body;
    UserData *userData;
};


#endif // BALL_H
