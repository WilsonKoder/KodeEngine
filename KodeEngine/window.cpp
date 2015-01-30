//
//  window.cpp
//  KodeEngine
//
//  Created by Wilson Koder on 15/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#include "window.h"
#include <iostream>

KodeEngine::Window::Window(int res[2], const char* title, GLfloat clearColor[3])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, res[0], res[1], SDL_WINDOW_OPENGL);
        if (m_window != nullptr)
        {

            SDL_ShowCursor(false);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_CreateContext(m_window);

			glewExperimental = GL_TRUE;
			GLint result = glewInit();

			if (GLEW_OK != result)
			{
				std::cout << "couldn't init gl: " << glewGetErrorString(result) << std::endl;
				std::cin.get();
				exit(3);
			}

			std::cout << glGetString(GL_VERSION) << std::endl;
            GLuint VertexArrayID = 0;
            glGenVertexArrays(1, &VertexArrayID); // we kinda have to do this, code doesnt work if you don't do this. Go, delete the this and the next one
            glBindVertexArray(VertexArrayID);
            glClearColor(clearColor[0], clearColor[1], clearColor[2], 1.0f);
            resX = res[0];
            resY = res[1];
        }
    }
}

void KodeEngine::Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void KodeEngine::Window::swapBuffers()
{
    SDL_GL_SwapWindow(m_window);
}

SDL_Window* KodeEngine::Window::getWindow()
{
    return m_window;
}

bool KodeEngine::Window::isClosed()
{
    return quit;
}