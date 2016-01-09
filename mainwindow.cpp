#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <game.h>

MainWindow::MainWindow(QApplication *app, QWidget *parent) : app(app), QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    scene = new GraphicsScene(this);
    game = new Game(this, app);

    scene->game = game;
    scene->setSceneRect(-4,-4,35,26);
    ui->graphicsView->setScene(scene);


    bsize = game->configObj["BallsSize"].toDouble();
    wbsize = game->configObj["WhiteBallSize"].toDouble();

    scene->setBackgroundBrush(Qt::white);


    QPen outline(Qt::black);
    outline.setWidth(0);


    QPolygonF polygon[6];

    polygon[0] << QPointF(0.6,1.5) << QPointF(10.4,1.5)<< QPointF(9.9,2)<< QPointF(1.1,2);
    polygon[1] << QPointF(0.6,20.5) << QPointF(10.4,20.5)<< QPointF(9.9,20)<< QPointF(1.1,20);
    polygon[2] << QPointF(0,2.1) << QPointF(0.5,2.6)<< QPointF(0.5,10.4)<< QPointF(0,10.6);
    polygon[3] << QPointF(11,2.1) << QPointF(11,10.6)<< QPointF(10.5,10.4)<< QPointF(10.5,2.6);
    polygon[4] << QPointF(0,11.4) << QPointF(0.5,11.6)<< QPointF(0.5,19.4)<< QPointF(0,19.9);
    polygon[5] << QPointF(11,11.4) << QPointF(11,19.9)<< QPointF(10.5,19.4)<< QPointF(10.5,11.6);


    for(int i = 0; i < 6; ++i)
        sides.append(scene->addPolygon(polygon[i], outline, Qt::green));

    ground.append(scene->addRect(-0.5,1,12,0.5, outline, Qt::gray));
    ground.append(scene->addRect(-0.5,1.5,0.5,19, outline, Qt::gray));
    ground.append(scene->addRect(-0.5,20.5,12,0.5, outline, Qt::gray));
    ground.append(scene->addRect(11,1.5,0.5,19, outline, Qt::gray));

    

    holes.append(scene->addEllipse(0.25 - 0.75/2, 1.75 - 0.75/2, 0.75, 0.75, outline, Qt::black));
    holes.append(scene->addEllipse(0 - 0.75/2, 11 - 0.75/2, 0.75, 0.75, outline, Qt::black));
    holes.append(scene->addEllipse(0.25 - 0.75/2, 20.25 - 0.75/2, 0.75, 0.75, outline, Qt::black));
    holes.append(scene->addEllipse(10.75 - 0.75/2, 1.75 - 0.75/2, 0.75, 0.75, outline, Qt::black));
    holes.append(scene->addEllipse(11 - 0.75/2, 11 - 0.75/2, 0.75, 0.75, outline, Qt::black));
    holes.append(scene->addEllipse(10.75 - 0.75/2, 20.25 - 0.75/2, 0.75, 0.75, outline, Qt::black));
    

    createBallsItem(outline);

    ui->graphicsView->setTransform(QTransform::fromScale(1, -1));
    ui->graphicsView->scale(23, 23);

    game->initTimer();
}

void MainWindow::buildTable()
{

}


MainWindow::~MainWindow()
{
    delete game;
    delete ui;
    delete scene;
}


void MainWindow::render()
{
    whiteBall->setPos(game->b2whiteball->getBody()->GetPosition().x-(wbsize/2) , game->b2whiteball->getBody()->GetPosition().y-(wbsize/2));

    for(int i = 0; i < 15; ++i)
        balls.at(i)->setPos(game->m_balls[i]->getBody()->GetPosition().x-(bsize/2) , game->m_balls[i]->getBody()->GetPosition().y-(bsize/2));



    ui->graphicsView->viewport()->repaint();
}


GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
}


void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    game->b2whiteball->getBody()->ApplyLinearImpulse(b2Vec2((float32)mouseEvent->scenePos().x() - game->b2whiteball->getBody()->GetPosition().x, (float32)mouseEvent->scenePos().y() - game->b2whiteball->getBody()->GetPosition().y), game->b2whiteball->getBody()->GetPosition(), true);

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}


void MainWindow::createBallsItem(QPen outline)
{
    whiteBall = scene->addEllipse(0, 0, wbsize, wbsize, outline, Qt::white);

    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::yellow));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::red));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::yellow));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::yellow));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::red));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::red));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::yellow));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::red));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::yellow));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::yellow));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::black));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::red));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::red));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::yellow));
    balls.append(scene->addEllipse(0, 0, bsize, bsize, outline, Qt::red));
}
