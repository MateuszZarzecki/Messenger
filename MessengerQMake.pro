TARGET = messenger
CONFIG += console c++17
CONFIG += debug

CONFIG -= app_bundle
CONFIG -= qt

SOURCES += $$files(*.cpp,true) \
    source/menu/output.cpp
HEADERS += $$files(include/*.h*,true) \
    include/menu/output.hpp

INCLUDEPATH += "$$PWD/include/menu"\
           "$$PWD/include/server"\
           "$$PWD/include/shared"\
           "C:/dev/libraries_cpp/HTTPRequest-master/include" \
           "C:/dev/libraries_cpp/json-nlohmann"

LIBS += -lws2_32



