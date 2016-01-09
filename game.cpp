#include "game.h"
#include "mainwindow.h"
#include <iostream>
#include <QFileInfo>

class Ball;

moveBodyTask::moveBodyTask(Ball *ball, int i) : m_ball(ball), m_index(i)
{}


bool moveBodyTask::process()
{
    if(m_ball->getColor() == Balls::White || m_ball->getColor() == Balls::Black)
    {
        replaceBall();
        return false;
    }
    else
    {
        pot();
        return true;
    }
}


void moveBodyTask::pot()
{
    m_ball->getBody()->SetTransform(b2Vec2(m_index, 0), 0);
}

void moveBodyTask::replaceBall()
{
    m_ball->userData->game->fault();

    if(m_ball->getColor() == Balls::White)
        m_ball->getBody()->SetTransform(b2Vec2(5.5, 5.5), 0);
    else
        m_ball->getBody()->SetTransform(b2Vec2(5.5, 16.875), 0);

    std::cerr << "FAULT\n";
}


Game::Game()
{

}


Game::Game(MainWindow* w, QApplication *app) : m_window(w), app(app), m_gravity(0.0f, -9.7f)
{
    faults = 0;
    m_win = false;
    m_lose = false;


    if(!cfgFileExists())
    {
        std::cerr << "ERROR: could not find config.json configuration file\n";
        std::terminate();
    }

    configFile.setFileName(QString("../pool-qt/res/config.json"));

    if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cerr << "ERROR: could not open config.json configuration file" << std::endl;
        std::terminate();
    }



    configDoc = QJsonDocument::fromJson(configFile.readAll());

    configFile.close();

    configObj = configDoc.object();

    m_world = new b2World(m_gravity);
    m_world->SetContactListener(&listener);




    cushionBodyDef[0].position.Set(-0.25f, 11.0f);
    cushions[0] = m_world->CreateBody(&cushionBodyDef[0]);
    cushionBodyDef[1].position.Set(5.5f, 20.75f);
    cushions[1] = m_world->CreateBody(&cushionBodyDef[1]);
    cushionBodyDef[2].position.Set(11.25f, 11.0f);
    cushions[2] = m_world->CreateBody(&cushionBodyDef[2]);
    cushionBodyDef[3].position.Set(5.5f, 1.25f);
    cushions[3] = m_world->CreateBody(&cushionBodyDef[3]);



    cushions[4] = m_world->CreateBody(&cushionBodyDef[4]);
    cushions[5] = m_world->CreateBody(&cushionBodyDef[5]);
    cushions[6] = m_world->CreateBody(&cushionBodyDef[6]);
    cushions[7] = m_world->CreateBody(&cushionBodyDef[7]);
    cushions[8] = m_world->CreateBody(&cushionBodyDef[8]);
    cushions[9] = m_world->CreateBody(&cushionBodyDef[9]);


    cushionsShape[0].SetAsBox(0.25f, 10.0f);
    cushions[0]->CreateFixture(&cushionsShape[0], 0.0f);
    cushionsShape[1].SetAsBox(5.0f, 0.25f);
    cushions[1]->CreateFixture(&cushionsShape[1], 0.0f);
    cushionsShape[2].SetAsBox(0.25f, 10.0f);
    cushions[2]->CreateFixture(&cushionsShape[2], 0.0f);
    cushionsShape[3].SetAsBox(5.0f, 0.25f);
    cushions[3]->CreateFixture(&cushionsShape[3], 0.0f);

    b2Vec2 vertices4[4];
    vertices4[0].Set(0.6f, 1.5f);
    vertices4[1].Set(10.4f, 1.5f);
    vertices4[2].Set(9.9f, 2.0f);
    vertices4[3].Set(1.1f, 2.0f);

    b2Vec2 vertices5[4];
    vertices5[0].Set(0.0f, 2.1f);
    vertices5[1].Set(0.5f, 2.6f);
    vertices5[2].Set(0.5f, 10.4f);
    vertices5[3].Set(0.0f, 10.6f);

    b2Vec2 vertices6[4];
    vertices6[0].Set(0.0f, 11.4f);
    vertices6[1].Set(0.5f, 11.6f);
    vertices6[2].Set(0.5f, 19.4f);
    vertices6[3].Set(0.0f, 19.9f);

    b2Vec2 vertices7[4];
    vertices7[0].Set(11.0f, 2.1f);
    vertices7[1].Set(11.0f, 10.6f);
    vertices7[2].Set(10.5f, 10.4f);
    vertices7[3].Set(10.5f, 2.6f);

    b2Vec2 vertices8[4];
    vertices8[0].Set(11.0f, 11.4f);
    vertices8[1].Set(11.0f, 19.9f);
    vertices8[2].Set(10.5f, 19.4f);
    vertices8[3].Set(10.5f, 11.6f);

    b2Vec2 vertices9[4];
    vertices9[0].Set(0.6f, 20.5f);
    vertices9[1].Set(1.1f, 20.0f);
    vertices9[2].Set(9.9f, 20.0f);
    vertices9[3].Set(10.4f, 20.5f);


    int32 count = 4;

    cushionsShape[4].Set(vertices4, count);
    cushions[4]->CreateFixture(&cushionsShape[4], 0.0f);
    cushionsShape[5].Set(vertices5, count);
    cushions[5]->CreateFixture(&cushionsShape[5], 0.0f);
    cushionsShape[6].Set(vertices6, count);
    cushions[6]->CreateFixture(&cushionsShape[6], 0.0f);
    cushionsShape[7].Set(vertices7, count);
    cushions[7]->CreateFixture(&cushionsShape[7], 0.0f);
    cushionsShape[8].Set(vertices8, count);
    cushions[8]->CreateFixture(&cushionsShape[8], 0.0f);
    cushionsShape[9].Set(vertices9, count);
    cushions[9]->CreateFixture(&cushionsShape[9], 0.0f);

    colorMap["White"] = Balls::White;
    colorMap["Black"] = Balls::Black;
    colorMap["Red"] = Balls::Red;
    colorMap["Yellow"] = Balls::Yellow;

    createBallsBody();
    createHoles();

}


void Game::lose()
{

}


Game::~Game()
{
    delete m_world;
    delete b2whiteball;

    for(int i = 0; i < 6; ++i)
    {
        delete m_hole.at(i)->userData;
        delete m_hole.at(i);
    }

    for(int i = 0; i < 15; ++i)
        delete m_balls[i];
}


void Game::potBall(Ball *ball)
{
    //m_balls.erase(m_balls.indexOf(ball));
    ball->getBody()->SetLinearVelocity(b2Vec2(0,0));

    m_task.append(new moveBodyTask(ball, m_pottedBalls.size() + 1));

    //ball->m_body->SetGravityScale(1);
}

void Game::initTimer()
{
    connect(&m_myTimer, SIGNAL(timeout()), this, SLOT(update()));


    m_myTimer.start(16);
}




void Game::update()
{
    while(m_task.size() != 0)
    {
        if(m_task.back()->process())
            m_pottedBalls.append(m_task.back()->getBall());

        delete m_task.back();
        m_task.pop_back();
    }

    m_world->Step(TIMESTEP, V_ITERATIONS, P_ITERATIONS);
    //app->processEvents(QEventLoop::AllEvents);
    m_window->render();
}





bool cfgFileExists() {
    QFileInfo checkFile("../pool-qt/res/config.json");
    if (checkFile.exists() && checkFile.isFile()) {
        return true;
    } else {
        return false;
    }
}

void Game::createBallsBody()
{

    Ball *ball;

    for(int i = 0; i < 15; ++i)
    {
        ball = new Ball(this, configObj, i, &colorMap);
        m_balls.append(ball);
    }

    b2whiteball = new Ball(this, configObj, 15, &colorMap);

}

void Game::createHoles()
{
    b2CircleShape holeShape;
    b2FixtureDef holeFixDef;
    b2BodyDef holeBodyDef;

    for(int i = 0; i < 6; ++i)
    {
        m_hole.append(new Hole);
        m_hole.at(i)->userData = new UserData;
        m_hole.at(i)->userData->game = this;
        m_hole.at(i)->userData->type = Type::Hole;
        m_hole.at(i)->userData->ball = NULL;

    }

    holeBodyDef.position.Set(0.25f, 1.75f);
    m_hole.at(0)->m_body = m_world->CreateBody(&holeBodyDef);
    holeBodyDef.position.Set(0.f, 11.f);
    m_hole.at(1)->m_body = m_world->CreateBody(&holeBodyDef);
    holeBodyDef.position.Set(0.25f, 20.25f);
    m_hole.at(2)->m_body = m_world->CreateBody(&holeBodyDef);
    holeBodyDef.position.Set(10.75f, 1.75f);
    m_hole.at(3)->m_body = m_world->CreateBody(&holeBodyDef);
    holeBodyDef.position.Set(11.f, 11.f);
    m_hole.at(4)->m_body = m_world->CreateBody(&holeBodyDef);
    holeBodyDef.position.Set(10.75f, 20.25f);
    m_hole.at(5)->m_body = m_world->CreateBody(&holeBodyDef);


    holeShape.m_radius = 0.2f;
    holeFixDef.shape = &holeShape;
    holeFixDef.isSensor = true;

    for(int i = 0; i < 6; ++i)
        m_hole.at(i)->m_body->CreateFixture(&holeFixDef);
}


bool getBallAndHole(b2Contact *contact, Ball*& ball)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    bool sensorA = fixtureA->IsSensor();
    bool sensorB = fixtureB->IsSensor();
    if ( ! (sensorA ^ sensorB) ) //if neither is a sensor then contact is a collision between 2 balls, or a ball and a cushion
              return false;


    UserData *dataA = static_cast<UserData*>(fixtureA->GetBody()->GetUserData());
    UserData *dataB = static_cast<UserData*>(fixtureB->GetBody()->GetUserData());

    if(sensorA) //if A is a sensor then B is a ball
    {
        ball = dataB->ball;
    }
    else
    {
        ball = dataA->ball;
    }

    return true;
}


void holeContactListener::BeginContact(b2Contact *contact)
{
    /*void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();*/
    Ball *ball;


    if(getBallAndHole(contact, ball))
        ball->userData->game->potBall(ball);


}

