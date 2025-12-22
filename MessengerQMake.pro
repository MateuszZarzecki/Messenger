TEMPLATE = app
TARGET = messenger
CONFIG += console c++17 debug
CONFIG -= app_bundle qt windows

INCLUDEPATH += \
           C:/dev/libraries_cpp/HTTPRequest-master/include \
           C:/dev/libraries_cpp/json-nlohmann

include(menu/menu.pri)
include(server/server.pri)
include(shared/shared.pri)

SOURCES += messenger.cpp

LIBS += -lws2_32
