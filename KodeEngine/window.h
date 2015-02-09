//
//  window.h
//  KodeEngine
//
//  Created by Wilson Koder on 15/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#ifndef __KodeEngine__window__
#define __KodeEngine__window__

#include <SDL/SDL.h>
//#include <SDL2/SDL_types.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#endif
#ifdef _WIN32
#define GLEW
#include <GL/glew.h>
#endif

namespace KodeEngine {
    class Window {
    public:
        Window(int res[2], const char* title, GLfloat clearColor[3]);
        SDL_Window* getWindow();
        void clear();
        void swapBuffers();
        bool isClosed();
        bool quit = false;
        int resX;
        int resY;
    private:
        SDL_Window* m_window;
    };
}

#endif /* defined(__KodeEngine__window__) */
