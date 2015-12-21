#include "game.h"



Game::Game()
{

}

Game::Game(MainWindow* w, QApplication *app) : m_window(w), app(app),  m_gravity(0.0f, 0.0f)
{
    if(!cfgFileExists())
    {
        std::cerr << "ERROR: could not find config.json configuration file\n";
        std::terminate();
    }
    
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





    m_ballDef.type = b2_dynamicBody;
    m_ballDef.linearDamping = 0.5f;
    ballShape.m_p.Set(0.0f, 0.0f);
    ballShape.m_radius = 0.25;
    m_fixtureDef.shape = &ballShape;
    m_fixtureDef.density = 1.0f;
    m_fixtureDef.friction = 0.1f;
    m_fixtureDef.restitution = 0.8f;



    m_ballDef.bullet = true;

    configFile.setFileName(QString("../pool-qt/res/config.json"));
    configFile.open(QIODevice::ReadOnly | QIODevice::Text);

    configDoc = QJsonDocument::fromJson(configFile.readAll());

    configFile.close();

    configObj = configDoc.object();

    ballsPosition = configObj["Positions"].toArray();



    for(int i = 0; i < 15; ++i)
    {
        m_ballDef.position.Set(ballsPosition[i].toObject()["x"].toDouble(), ballsPosition[i].toObject()["y"].toDouble());
        b2balls[i] = m_world->CreateBody(&m_ballDef);
        b2balls[i]->CreateFixture(&m_fixtureDef);
    }


    m_ballDef.position.Set(5.5f, 5.5f);
    b2whiteball = m_world->CreateBody(&m_ballDef);
    b2whiteball->CreateFixture(&m_fixtureDef);
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



bool cfgFileExists() {
    QFileInfo checkFile("../pool-qt/res/config.json");
    if (checkFile.exists() && checkFile.isFile()) {
        return true;
    } else {
        return false;
    }
}
