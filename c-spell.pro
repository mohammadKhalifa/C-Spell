#-------------------------------------------------
#
# Project created by QtCreator 2015-03-25T22:28:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

CONFIG +=qt

SOURCES += wordbreaker.cpp \
    mainwindow.cpp \
    edit_distance.cpp \
    main.cpp \
    lexicon.cpp

HEADERS +=edit_distance.h \
    mainwindow.h \
    wordbreaker.h \
    lexicon.h
TARGET = c_spell

FORMS += \
    mainwindow.ui
