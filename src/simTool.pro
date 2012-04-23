#-------------------------------------------------
#
# Project created by QtCreator 2012-01-27T09:43:19
#
#-------------------------------------------------

QT      += core gui
QT      += opengl
QT      += xml
TARGET   = simTool
TEMPLATE = app
SOURCES += main.cpp\
        mainwindow.cpp \
        node.cpp \
        edge.cpp \
        mechanicalnode.cpp \
        socialnode.cpp \
        search.cpp \
        feeder.cpp \
        astargraphsearch.cpp \
        offlinefeeder.cpp \
    simulator.cpp \
    heuristic.cpp \
    xmlwriter.cpp \
    xmlreader.cpp \
    graphfactory.cpp \
    geometricobject.cpp \
    graphicalnode.cpp \
    graphicaledge.cpp \
    observer.cpp \
    observable.cpp \
    dialog.cpp \
    rrtsearch.cpp \
    searchnode.cpp \
    environment.cpp \
    xmlread.cpp \
    simulatedannealing.cpp
    surfex.cpp \
    optimize.cpp
HEADERS += mainwindow.h \
        node.hpp \
        edge.hpp \
        mechanicalnode.hpp \
        socialnode.hpp \
        search.hpp \
        feeder.hpp \
        astargraphsearch.hpp \
        offlinefeeder.hpp \
    simulator.hpp \
    heuristic.hpp \
    rapidxml_utils.hpp \
    rapidxml_print.hpp \
    rapidxml_iterators.hpp \
    rapidxml.hpp \
    xmlreader.hpp \
    xmlwriter.hpp \
    graphfactory.hpp \
    geometricobject.hpp \
    graphicalnode.hpp \
    graphicaledge.hpp \
    observer.hpp \
    observable.hpp \
    dialog.hpp \
    rrtsearch.h \
    environment.h \
    searchnode.h \
    xmlread.hpp \
    simulatedannealing.hpp \
    surfex.hpp \
    optimize.h
FORMS   += mainwindow.ui \
    dialog.ui \
    optimize.ui
CONFIG  += console





