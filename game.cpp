#include "game.h"



Game::Game()
{

}

Game::Game(MainWindow* w, QApplication *app) : m_window(w), app(app),  m_gravity(0.0f, 0.0f)
{
    m_world = new b2World(m_gravity);

    cushionBodyDef[0].position.Set(0.0f, 11.0f);
    cushions[0] = m_world->CreateBody(&cushionBodyDef[0]);
    cushionBodyDef[1].position.Set(5.5f, 20.5f);
    cushions[1] = m_world->CreateBody(&cushionBodyDef[1]);
    cushionBodyDef[2].position.Set(11.0f, 11.0f);
    cushions[2] = m_world->CreateBody(&cushionBodyDef[2]);
    cushionBodyDef[3].position.Set(5.5f, 1.5f);
    cushions[3] = m_world->CreateBody(&cushionBodyDef[3]);

    cushionsShape[0].SetAsBox(0.5f, 10.0f);
    cushions[0]->CreateFixture(&cushionsShape[0], 0.0f);
    cushionsShape[1].SetAsBox(5.0f, 0.5f);
    cushions[1]->CreateFixture(&cushionsShape[1], 0.0f);
    cushionsShape[2].SetAsBox(0.5f, 10.0f);
    cushions[2]->CreateFixture(&cushionsShape[2], 0.0f);
    cushionsShape[3].SetAsBox(5.0f, 0.5f);
    cushions[3]->CreateFixture(&cushionsShape[3], 0.0f);





    ballDef.type = b2_dynamicBody;
    ballDef.linearDamping = 0.5f;
    ballShape.m_p.Set(0.0f, 0.0f);
    ballShape.m_radius = 0.25;
    fixtureDef.shape = &ballShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.1f;
    fixtureDef.restitution = 0.8f;



    ballDef.bullet = true;
    ballDef.position.Set(4.5f, 17.75f);
    b2balls[0] = m_world->CreateBody(&ballDef);
    b2balls[0]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.0f, 17.75f);
    b2balls[1] = m_world->CreateBody(&ballDef);
    b2balls[1]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.5f, 17.75f);
    b2balls[2] = m_world->CreateBody(&ballDef);
    b2balls[2]->CreateFixture(&fixtureDef);

    ballDef.position.Set(6.0f, 17.75f);
    b2balls[3] = m_world->CreateBody(&ballDef);
    b2balls[3]->CreateFixture(&fixtureDef);

    ballDef.position.Set(6.5f, 17.75f);
    b2balls[4] = m_world->CreateBody(&ballDef);
    b2balls[4]->CreateFixture(&fixtureDef);

    ballDef.position.Set(4.75f, 17.75f - (7.0f/8.0f)/2.0f);
    b2balls[5] = m_world->CreateBody(&ballDef);
    b2balls[5]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.25f, 17.75f - (7.0f/8.0f)/2.0f);
    b2balls[6] = m_world->CreateBody(&ballDef);
    b2balls[6]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.75f, 17.75f - (7.0f/8.0f)/2.0f);
    b2balls[7] = m_world->CreateBody(&ballDef);
    b2balls[7]->CreateFixture(&fixtureDef);

    ballDef.position.Set(6.25f, 17.75f - (7.0f/8.0f)/2.0f);
    b2balls[8] = m_world->CreateBody(&ballDef);
    b2balls[8]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.0f, 17.75f - (7.0f/8.0f));
    b2balls[9] = m_world->CreateBody(&ballDef);
    b2balls[9]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.5f, 17.75f - (7.0f/8.0f));
    b2balls[10] = m_world->CreateBody(&ballDef);
    b2balls[10]->CreateFixture(&fixtureDef);

    ballDef.position.Set(6.0f, 17.75f - (7.0f/8.0f));
    b2balls[11] = m_world->CreateBody(&ballDef);
    b2balls[11]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.25f, 17.75f - ((7.0f/8.0f)/2.0f)*3.0f);
    b2balls[12] = m_world->CreateBody(&ballDef);
    b2balls[12]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.75f, 17.75f - ((7.0f/8.0f)/2.0f)*3.0f);
    b2balls[13] = m_world->CreateBody(&ballDef);
    b2balls[13]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.5f, 17.75f - ((7.0f/8.0f)*2.0f));
    b2balls[14] = m_world->CreateBody(&ballDef);
    b2balls[14]->CreateFixture(&fixtureDef);

    ballDef.position.Set(5.5f, 5.5f);
    b2whiteball = m_world->CreateBody(&ballDef);
    b2whiteball->CreateFixture(&fixtureDef);
}

Game::~Game()
{
    delete m_world;
}


void Game::initTimer()
{
    connect(&m_myTimer, SIGNAL(timeout()), this, SLOT(update()));


    m_myTimer.start(16);
}



void Game::update()
{
    m_world->Step(TIMESTEP, V_ITERATIONS, P_ITERATIONS);
    app->processEvents(QEventLoop::AllEvents);
    m_window->render();
}
