#-------------------------------------------------
#
# Project created by QtCreator 2018-04-15T19:45:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blockschema
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    blockscene.cpp \
    blockarrow.cpp \
    block.cpp \
    port.cpp \
    blockodcitanie.cpp \
    blocknasobenie.cpp \
    blockdelenie.cpp \
    blockmocnina.cpp \
    blockcislo6.cpp \
    blockcislo7.cpp \
    blockcislo5.cpp \
    blockscitanie.cpp \
    onhoverlabel.cpp

HEADERS += \
        mainwindow.h \
    blockscene.h \
    blockarrow.h \
    block.h \
    port.h \
    blockodcitanie.h \
    blocknasobenie.h \
    blockdelenie.h \
    blockmocnina.h \
    blockcislo6.h \
    blockcislo7.h \
    blockcislo5.h \
    blockscitanie.h \
    onhoverlabel.h

FORMS += \
        mainwindow.ui
