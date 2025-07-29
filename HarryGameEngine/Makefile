#OBJS specifies which files to compile as part of the project
OBJS = ./src/main.cpp ./imgui/*.cpp ./math/vector2D.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I/usr/include/SDL2 -I./core -I./imgui -I./math 

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L/usr/lib/x86_64-linux-gnu 

#COMPILER_FLAGS specifies the addtional compilation options we're using
#-static-libgcc -static-libstdc++
#-Wunsafe-loop-optimizations -Weffc++ -pedantic -static-libgcc -static-libstdc++ 
COMPILER_FLAGS = -g -Wall -std=c++11 -v

#LINKER_FLAGS specifies the libraries we're linking against -lSDL2_ttf -lSDL2_mixer
#-static -lpthread -lmingw32
LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = ./build/game-engine

#This is the target that compiles our executable
#Ex: g++ LoadFromFile.cpp -IC:\mingw64\include\SDL2 -LC:\mingw64\lib -g -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o LoadFromFileMingw32.exe
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
run :
	./build/game-engine
clean :
	rm ./build/game-engine
