//
//  input.cpp
//  KodeEngine
//
//  Created by Wilson Koder on 18/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#include "input.h"
#include <iostream>

void KodeEngine::Input::handleEvents(KodeEngine::Window window, GLfloat *fov)
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                window.quit = true;
                KodeEngine::Input::quit(window.getWindow());
                break;
            case SDL_MOUSEWHEEL:
                std::cout << "scroll: " << event.wheel.y << std::endl;
                
                if (event.wheel.y > 0)
                {
                    *fov -= 0.1;
                }
                else
                {
                    *fov += 0.1;
                }
                
            default:
                break;
        }
    }
}

void KodeEngine::Input::quit(SDL_Window *window)
{
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(0);
}