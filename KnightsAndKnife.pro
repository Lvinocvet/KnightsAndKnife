#-------------------------------------------------
#
# Project created by QtCreator 2020-08-13T15:16:23
#
#-------------------------------------------------
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KnightsAndKnife
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    arbitr.cpp \
    knight.cpp \
    knife.cpp

HEADERS  += mainwindow.h \
    arbitr.h \
    knight.h \
    knife.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resource.qrc
