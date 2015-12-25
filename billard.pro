#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T01:52:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = billard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        game.cpp \
    ball.cpp

HEADERS  += mainwindow.h \
        game.h \
    ball.h

FORMS    += mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Box2D/Box2D/Build/Box2D/ -lBox2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Box2D/Box2D/Build/Box2D/ -lBox2d

win32{
INCLUDEPATH += $$PWD/Box2D/Box2D
DEPENDPATH += $$PWD/Box2D/Box2D
}

linux-g++ | linux-g++-64 | linux-g++-32 {
INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/lib"
LIBS += -lBox2D
}

FLAGS *= fPIC
