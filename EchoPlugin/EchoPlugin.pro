
TEMPLATE = lib
CONFIG += plugin

HEADERS += \
    echointerface.h \
    echoplugin.h

SOURCES += \
    echoplugin.cpp

TARGET          = $$qtLibraryTarget(EchoPlugin)
DESTDIR         = ../plugins
