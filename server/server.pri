INCLUDEPATH += \
    $$PWD/include/core \
    $$PWD/include/modules

SOURCES += \
    #core
    $$PWD/source/core/crypto.cpp \
    $$PWD/source/core/serverBase.cpp \
    #modules
    $$PWD/source/modules/chatApi.cpp \
    $$PWD/source/modules/friendApi.cpp \
    $$PWD/source/modules/localUserApi.cpp \
    $$PWD/source/modules/webUserApi.cpp

HEADERS += \
    #core
    $$PWD/include/core/crypto.hpp \
    $$PWD/include/core/serverBase.hpp \
    #modules
    $$PWD/include/modules/chatApi.hpp \
    $$PWD/include/modules/friendApi.hpp \
    $$PWD/include/modules/localUserApi.hpp \
    $$PWD/include/modules/webUserApi.hpp
