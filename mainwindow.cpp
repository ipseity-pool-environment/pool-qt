#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new GraphicsScene(this);
    scene->game = game;
    scene->setSceneRect(-4,-4,35,26);
    ui->graphicsView->setScene(scene);

    QPen outline(Qt::black);
    outline.setWidth(0);

    scene->setBackgroundBrush(Qt::white);
    whiteBall = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::white);

    balls[0] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::yellow);
    balls[1] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::red);
    balls[2] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::yellow);
    balls[3] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::yellow);
    balls[4] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::red);
    balls[5] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::red);
    balls[6] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::yellow);
    balls[7] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::red);
    balls[8] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::yellow);
    balls[9] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::yellow);
    balls[10] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::black);
    balls[11] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::red);
    balls[12] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::red);
    balls[13] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::yellow);
    balls[14] = scene->addEllipse(0, 0, 0.5, 0.5, outline, Qt::red);

    ground[0] = scene->addRect(-0.5, 1, 1, 20, outline, Qt::white);
    ground[1] = scene->addRect(0.5, 20, 10, 1, outline, Qt::white);
    ground[2] = scene->addRect(10.5, 1, 1, 20, outline, Qt::white);
    ground[3] = scene->addRect(0.5, 1, 10, 1, outline, Qt::white);

    ui->graphicsView->setTransform(QTransform::fromScale(1, -1));
    //ui->graphicsView->scale(23,23);
    ui->graphicsView->scale(23, 23);

}



MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


void MainWindow::render()
{
    whiteBall->setPos(game->b2whiteball->GetPosition().x-0.25 , game->b2whiteball->GetPosition().y-0.25);

    for(int i = 0; i < 15; ++i)
        balls[i]->setPos(game->b2balls[i]->GetPosition().x-0.25 , game->b2balls[i]->GetPosition().y-0.25);


    //std::cout << game->b2whiteball->GetPosition().x << " " << game->b2whiteball->GetPosition().y << std::endl;

    ui->graphicsView->viewport()->repaint();
}


GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
}


void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    //game->b2whiteball->ApplyLinearImpulse(b2Vec2(0.05f, 6.5f), game->b2whiteball->GetPosition(), true);

    game->b2whiteball->ApplyLinearImpulse(b2Vec2((float32)mouseEvent->scenePos().x() - game->b2whiteball->GetPosition().x, (float32)mouseEvent->scenePos().y() - game->b2whiteball->GetPosition().y), game->b2whiteball->GetPosition(), true);
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
