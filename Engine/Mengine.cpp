#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Mengine.hpp"

namespace Mengine {

    int init() {
        //Initialize SDL
        SDL_Init(SDL_INIT_EVERYTHING);

        //Tell SDL that we want a double buffered window so we dont get
        //any flickering
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        return 0;
    }

}