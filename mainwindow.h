#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "game.h"

namespace Ui {
class MainWindow;
}

class Game;


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Game *game;

public slots:
    void render();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsRectItem *ball;


};




#endif // MAINWINDOW_H
