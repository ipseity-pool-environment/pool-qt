#include "game.h"

Game::Game()
{

}

Game::Game(MainWindow* w, QApplication *a) : window(w),a(a),  gravity(0.0f, -10.0f), timeStep(1.0f / 60.0f), velocityIterations(6), positionIterations(2)
{
    world = new b2World(gravity);

    groundBodyDef.position.Set(0.0f, -10.0f);
    groundBody = world->CreateBody(&groundBodyDef);

    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);

    body = world->CreateBody(&bodyDef);

    dynamicBox.SetAsBox(1.0f, 1.0f);
    fixtureDef.shape = &dynamicBox;

    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body->CreateFixture(&fixtureDef);
}

Game::~Game()
{
    delete world;
}


void Game::initTimer()
{
    connect(&myTimer, SIGNAL(timeout()), this, SLOT(update()));


    myTimer.start(16);
}



void Game::update()
{
    world->Step(timeStep, velocityIterations, positionIterations);
    position = body->GetPosition();
    angle = body->GetAngle();
    a->processEvents();
    window->render();
}

