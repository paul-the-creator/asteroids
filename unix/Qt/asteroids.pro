BASEPATH = ../..
SOURCEPATH = $$BASEPATH/source
3RD_LIBRARIES_PATH = $$BASEPATH/3rdLibraries

OBJECTS_DIR = obj
DESTDIR = bin

QMAKE_CXXFLAGS = -std=c++0x
#CONFIG += c++11
CONFIG -= qt

LIBS += -L$$3RD_LIBRARIES_PATH/GL -lglut
LIBS += -L$$3RD_LIBRARIES_PATH/SOIL -lSOIL
INCLUDEPATH += $$3RD_LIBRARIES_PATH

HEADERS += \
        $$SOURCEPATH/Game.h \
        $$SOURCEPATH/Point.h \
        $$SOURCEPATH/ObjectManager.h \
        $$SOURCEPATH/Renderer.h \
        $$SOURCEPATH/Object.h \
        $$SOURCEPATH/Asteroid.h \
        $$SOURCEPATH/SpaceShip.h \
        $$SOURCEPATH/EngineTrack.h \
        $$SOURCEPATH/Bullet.h \
        $$SOURCEPATH/Laser.h \
        $$SOURCEPATH/FlyingSaucer.h \

SOURCES += \
        $$SOURCEPATH/main.cpp \
        $$SOURCEPATH/Game.cpp \
        $$SOURCEPATH/ObjectManager.cpp \
        $$SOURCEPATH/Renderer.cpp \
        $$SOURCEPATH/Object.cpp \
        $$SOURCEPATH/Asteroid.cpp \
        $$SOURCEPATH/SpaceShip.cpp \
        $$SOURCEPATH/EngineTrack.cpp \
        $$SOURCEPATH/Bullet.cpp \
        $$SOURCEPATH/Laser.cpp \
        $$SOURCEPATH/FlyingSaucer.cpp \
