INCLUDEPATH += \
    $$PWD/include/core \
    $$PWD/include/menus

SOURCES += \
    # core
    $$PWD/source/core/command.cpp \
    $$PWD/source/core/input.cpp \
    $$PWD/source/core/interactionManager.cpp \
    $$PWD/source/core/menuBase.cpp \
    $$PWD/source/core/menuManager.cpp \
    $$PWD/source/core/output.cpp \
    #menus
    $$PWD/source/menus/authenticationMenu.cpp \
    $$PWD/source/menus/chatMenu.cpp \
    $$PWD/source/menus/mainMenu.cpp

HEADERS += \
    #core
    $$PWD/include/core/command.hpp \
    $$PWD/include/core/input.hpp \
    $$PWD/include/core/interactionManager.hpp \
    $$PWD/include/core/menuBase.hpp \
    $$PWD/include/core/menuManager.hpp \
    $$PWD/include/core/output.hpp \
    #$$PWDs
    $$PWD/include/menus/authenticationMenu.hpp \
    $$PWD/include/menus/chatMenu.hpp \
    $$PWD/include/menus/mainMenu.hpp
