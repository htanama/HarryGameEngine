# HarryGameEngine
Video Game Engine - Develop your 2D &amp; 3D games, cross-platform projects.

Compiling for Windows:
- Use the MSVC solution "HarryGameEngine.sln"
- SDL2 library for Win64

Compiling for Linux: 
- Install SDL2 library with your Linux Distribution Package Example Below:
- `libsdl2-dev` - SDL2 development library.
- `libsdl2-image-dev` - SDL2 image development library (for loading images).
- `libsdl2-mixer-dev` - SDL2 mixer development library (for playing sounds and music).
- `libsdl2-ttf-dev` - SDL2 TrueType fonts development library (for rendering text).
- `libsdl2-net-dev` - SDL2 network development library. (Optional)
- `libsdl2-gfx-dev` - SDL2 graphics development library.(Optional)

The Makefile script already prepared and developer can run the make command from HarryGameEngine directory:
```
make
```
The binary executable 'game-engine'  will located inside the ./build folder
To run the game-engine application:
```
./build/game-engine
```
