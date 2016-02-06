LIBS += -L/usr/local/lib/ -lX11  -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -lGL -lGLU -lEA_for_AntipodGameEngine

INCLUDEPATH += /usr/include/boost /usr/SFML-2.1/include /usr/local/include/ea4age


CONFIG += c++11
QT += widgets
#QT += phonon

SOURCES += ai_player.cpp \
    animatedmanager.cpp \
    animatedsprite.cpp \
    bullet.cpp \
    carte.cpp \
    datamanager.cpp \
    displaymanager.cpp \
    ea_test.cpp \
    entite.cpp \
    environment.cpp \
    imagemanager.cpp \
    ingame.cpp \
    ingameui.cpp \
    lightsource.cpp \
    main.cpp \
    mob.cpp \
    player.cpp \
    qsfcanvas.cpp \
    qsfml.cpp \
    soundmanager.cpp \
    stormblink.cpp \
    texturemanager.cpp \
    tzellipse.cpp

HEADERS += \
    ai_player.h \
    animatedmanager.h \
    animatedsprite.h \
    bullet.h \
    carte.h \
    datamanager.h \
    displaymanager.h \
    entite.h \
    environment.h \
    gleffect.hpp \
    imagemanager.h \
    ingame.h \
    ingameui.h \
    lightsource.h \
    mob.h \
    player.h \
    qsfcanvas.h \
    qsfml.h \
    soundmanager.h \
    stormblink.h \
    texturemanager.h \
    tzellipse.h

