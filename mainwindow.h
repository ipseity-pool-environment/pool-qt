#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>

#include "game.h"

namespace Ui {
class MainWindow;
}

class Game;

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    Game *game;
    explicit GraphicsScene(QObject *parent = 0);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
signals:

public slots:

private:
};


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Game *game;

    QGraphicsEllipseItem *whiteBall;
    QList<QGraphicsEllipseItem*> balls;
    QList<QGraphicsRectItem*> ground;



    GraphicsScene *scene;
public slots:
    void render();

private:
    Ui::MainWindow *ui;


};




#endif // MAINWINDOW_H
