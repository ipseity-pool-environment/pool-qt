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
    game.cpp

HEADERS  += mainwindow.h \
    game.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/lib"
LIBS += -lBox2D

FLAGS *= fPIC
