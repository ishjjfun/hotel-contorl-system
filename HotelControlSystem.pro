#-------------------------------------------------
#
# Project created by QtCreator 2019-06-03T15:08:49
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotelControlSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    modelcontrol.cpp \
    equipmentcontrol.cpp \
    call.cpp \
    home.cpp

HEADERS  += mainwindow.h \
    modelcontrol.h \
    equipmentcontrol.h \
    call.h \
    home.h

FORMS    += mainwindow.ui \
    modelcontrol.ui \
    equipmentcontrol.ui \
    call.ui \
    home.ui

RESOURCES += \
    resource.qrc
