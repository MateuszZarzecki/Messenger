QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "C:/SFML-2.6.1-mingw/include"
LIBS += -L"C:/SFML-2.6.1-mingw/lib"
LIBS += -L"C:/SFML-2.6.1-mingw/bin"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

INCLUDEPATH += "libraries/json-develop/include"

SOURCES += \
    services/apihandler.cpp \
    main.cpp \
    mainwindow.cpp \
    services/connection.cpp

HEADERS += \
    mainwindow.h \
    services/apihandler.hpp \
    services/atomicadv.hpp \
    services/connection.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc




