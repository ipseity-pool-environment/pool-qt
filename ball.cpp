#include "ball.h"


Ball::Ball(Game *game, QJsonObject configObj, int index, std::map<QString, Balls::BallsColor> *colorMap)
{
    m_body = NULL;

    m_contact = false;
    double radius;

    if(index == 15)
        radius = configObj["WhiteBallSize"].toDouble() / 2;
    else
        radius = configObj["BallsSize"].toDouble() / 2;

    b2BodyDef ballDef;
    b2CircleShape ballShape;
    b2FixtureDef ballFixDef;
    ballDef.type = b2_dynamicBody;
    ballDef.linearDamping = 0.5f;
    ballDef.angularDamping = 0.5f;
    ballShape.m_p.Set(0.0f, 0.0f);
    ballShape.m_radius = radius;
    ballFixDef.shape = &ballShape;
    ballFixDef.density = 1.0f;
    ballFixDef.friction = 0.9f;
    ballFixDef.restitution = 0.8f;
    ballDef.bullet = true;

    ballDef.position.Set(configObj["BallsProperties"].toArray()[index].toObject()["x"].toDouble(), configObj["BallsProperties"].toArray()[index].toObject()["y"].toDouble());
    m_body = game->m_world->CreateBody(&ballDef);
    m_body->CreateFixture(&ballFixDef);

    m_body->SetGravityScale(0);

    userData = new UserData;
    userData->game = game;
    userData->ball = this;
    userData->type = Type::Ball;
    userData->hole = NULL;

    m_body->SetUserData(userData);

    m_color = colorMap->at(configObj["BallsProperties"].toArray()[index].toObject()["color"].toString());

}

Ball::~Ball()
{
    delete userData;
}
