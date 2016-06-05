TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    learnstl.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    learnstl.h

INCLUDEPATH += /usr/local/boost_1_61_0

