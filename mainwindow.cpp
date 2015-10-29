#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(100,100,100,100);
    ui->graphicsView->setScene(scene);

    QBrush green(Qt::green);
    QPen outline(Qt::white);
    outline.setWidth(0);

    ball = scene->addRect(0,0,20,20, outline, green);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::render()
{
    ball->setPos(game->position.x, -game->position.y*50+150);

    printf("%4.2f %4.2f\n", game->position.x, game->position.y);
    ui->graphicsView->viewport()->repaint();
}

