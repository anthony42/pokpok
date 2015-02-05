#-------------------------------------------------
#
# Project created by QtCreator 2015-02-01T10:10:22
#
#-------------------------------------------------

QT       += core gui\
			widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tracker
TEMPLATE = app

SOURCES	+= main.cpp\
        mainwindow.cpp\
        screenshot.cpp

HEADERS	+= mainwindow.h\
                screenshot.hpp

FORMS	+= mainwindow.ui
