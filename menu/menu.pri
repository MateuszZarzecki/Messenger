INCLUDEPATH += \
    $$PWD/include/core \
    $$PWD/include/menus

SOURCES += \
    # core
    $$PWD/source/core/command.cpp \
    $$PWD/source/core/effect.cpp \
    $$PWD/source/core/input.cpp \
    $$PWD/source/core/interactionManager.cpp \
    $$PWD/source/core/key.cpp \
    $$PWD/source/core/menuBase.cpp \
    $$PWD/source/core/menuManager.cpp \
    $$PWD/source/core/menuRepository.cpp \
    $$PWD/source/core/message.cpp \
    $$PWD/source/core/output.cpp \
    #menus
    $$PWD/source/menus/authenticationMenu.cpp \
    $$PWD/source/menus/chatMenu.cpp \
    $$PWD/source/menus/mainMenu.cpp

HEADERS += \
    #core
    $$PWD/include/core/command.hpp \
    $$PWD/include/core/effect.hpp \
    $$PWD/include/core/input.hpp \
    $$PWD/include/core/interactionManager.hpp \
    $$PWD/include/core/key.hpp \
    $$PWD/include/core/menuBase.hpp \
    $$PWD/include/core/menuManager.hpp \
    $$PWD/include/core/menuRepository.hpp \
    $$PWD/include/core/message.hpp \
    $$PWD/include/core/output.hpp \
    #menus
    $$PWD/include/menus/authenticationMenu.hpp \
    $$PWD/include/menus/chatMenu.hpp \
    $$PWD/include/menus/mainMenu.hpp
