##########
#asteroids
#made by paul_the_creator (10/2013)
##########

CC            = gcc
CXX           = g++
CFLAGS        = -pipe -O2 -Wall -W $(DEFINES)
CXXFLAGS      = -std=c++0x -O2 -Wall -W $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I../3rdLibraries
LFLAGS        =
LIBS          = $(SUBLIBS)   -L./../3rdLibraries/GL -lglut#   -L./../3rdLibraries/SOIL -lSOIL
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
DEL_FILE      = rm -f
DEL_DIR       = rm -rf
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

SOURCE_DIR    = ../source
OBJECTS_DIR   = obj
TARGET_DIR    = bin
TARGET        = $(TARGET_DIR)/asteroids

SOURCES       = $(SOURCE_DIR)/main.cpp \
		$(SOURCE_DIR)/Game.cpp \
		$(SOURCE_DIR)/Renderer.cpp \
		$(SOURCE_DIR)/ObjectManager.cpp \
		$(SOURCE_DIR)/Object.cpp \
		$(SOURCE_DIR)/Asteroid.cpp \
		$(SOURCE_DIR)/Bullet.cpp \
		$(SOURCE_DIR)/EngineTrack.cpp \
		$(SOURCE_DIR)/FlyingSaucer.cpp \
		$(SOURCE_DIR)/Laser.cpp \
		$(SOURCE_DIR)/SpaceShip.cpp 

OBJECTS=$(SOURCES:.cpp=.o)

all : $(SOURCES) $(TARGET)

$(TARGET): obj_dir $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(CXX) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

obj_dir:
	@$(CHK_DIR_EXISTS) $(OBJECTS_DIR)/ || $(MKDIR) $(OBJECTS_DIR)/ 

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

$(OBJECTS_DIR)/main.o: $(SOURCE_DIR)/main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/main.o $(SOURCE_DIR)/main.cpp

$(OBJECTS_DIR)/Game.o: $(SOURCE_DIR)/Game.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/Game.o $(SOURCE_DIR)/Game.cpp

$(OBJECTS_DIR)/Renderer.o: $(SOURCE_DIR)/Renderer.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/Renderer.o $(SOURCE_DIR)/Renderer.cpp

$(OBJECTS_DIR)/ObjectManager.o: $(SOURCE_DIR)/ObjectManager.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/ObjectManager.o $(SOURCE_DIR)/ObjectManager.cpp

$(OBJECTS_DIR)/Object.o: $(SOURCE_DIR)/Object.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/Object.o $(SOURCE_DIR)/Object.cpp

$(OBJECTS_DIR)/Asteroid.o: $(SOURCE_DIR)/Asteroid.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/Asteroid.o $(SOURCE_DIR)/Asteroid.cpp

$(OBJECTS_DIR)/Bullet.o: $(SOURCE_DIR)/Bullet.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/Bullet.o $(SOURCE_DIR)/Bullet.cpp

$(OBJECTS_DIR)/EngineTrack.o: $(SOURCE_DIR)/EngineTrack.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/EngineTrack.o $(SOURCE_DIR)/EngineTrack.cpp

$(OBJECTS_DIR)/FlyingSaucer.o: $(SOURCE_DIR)/FlyingSaucer.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/FlyingSaucer.o $(SOURCE_DIR)/FlyingSaucer.cpp

$(OBJECTS_DIR)/Laser.o: $(SOURCE_DIR)/Laser.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/Laser.o $(SOURCE_DIR)/Laser.cpp

$(OBJECTS_DIR)/SpaceShip.o: $(SOURCE_DIR)/SpaceShip.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJECTS_DIR)/SpaceShip.o $(SOURCE_DIR)/SpaceShip.cpp

clean:
	$(DEL_DIR) $(OBJECTS_DIR) $(TARGET_DIR)
