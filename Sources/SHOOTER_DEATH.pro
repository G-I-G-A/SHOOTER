TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

##WINDOWS##

# SFML file in the same location as project #

LIBS += -L"..\SFML-2.5.1\lib"
LIBS += -L"..\SFML-2.5.1\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "..\SFML-2.5.1\include"
DEPENDPATH += "..\SFML-2.5.1\include"

SOURCES += \
        Assets/assets.cpp \
        Bullet/bullet.cpp \
        Enemy/enemy.cpp \
        Field/field.cpp \
        Field/renderfield.cpp \
        Game/game.cpp \
        Menu/menu.cpp \
        Player/player.cpp \
        main.cpp

HEADERS += \
    Assets/assets.h \
    Bullet/bullet.h \
    Enemy/enemy.h \
    Field/field.h \
    Field/renderfield.h \
    Game/game.h \
    Menu/menu.h \
    Player/player.h