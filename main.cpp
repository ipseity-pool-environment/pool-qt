#include "game.h"


int main(int argc, char *argv[])
{

    
    QApplication a(argc, argv);
    MainWindow w;
    Game game(&w, &a);
    w.game = &game;
    w.scene->game = &game;
    game.initTimer();

    w.show();




    B2_NOT_USED(argc);
    B2_NOT_USED(argv);



    return a.exec();
}
