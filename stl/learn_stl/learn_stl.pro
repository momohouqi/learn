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

INCLUDEPATH += "C:\Users\willchen\Install\msys\1.0\boost_1_61_0"
