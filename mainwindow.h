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
    explicit MainWindow(QApplication *app, QWidget *parent = 0);
    ~MainWindow();
    void createBallsItem(QPen outline);
    void buildTable();

    QGraphicsEllipseItem *whiteBall;
    QList<QGraphicsEllipseItem*> balls;
    QList<QGraphicsRectItem*> ground;
    QList<QGraphicsPolygonItem*> sides;
    QList<QGraphicsEllipseItem*> holes;



    GraphicsScene *scene;
public slots:
    void render();

private:
    Ui::MainWindow *ui;
    float bsize;
    Game *game;
    QApplication *app;


};




#endif // MAINWINDOW_H
