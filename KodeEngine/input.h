//
//  input.h
//  KodeEngine
//
//  Created by Wilson Koder on 18/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#ifndef __KodeEngine__input__
#define __KodeEngine__input__

#include <SDL/SDL.h>
#include "window.h"
#include <glm/glm.hpp>

namespace KodeEngine {
    class Input {
    public:
        void handleEvents(KodeEngine::Window window, GLfloat *fov);
    private:
        void quit(SDL_Window* window);
    };
}


#endif /* defined(__KodeEngine__input__) */
