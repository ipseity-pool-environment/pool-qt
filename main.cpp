#include "game.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{

    
    QApplication a(argc, argv);
    MainWindow w(&a);

    w.show();


    B2_NOT_USED(argc);
    B2_NOT_USED(argv);



    return a.exec();
}
