//
//  FPSCamera.h
//  KodeEngine
//
//  Created by Wilson Koder on 20/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#ifndef __KodeEngine__FPSCamera__
#define __KodeEngine__FPSCamera__

#include <stdio.h>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

namespace KodeEngine {
    class FPSCam {
    public:
        FPSCam(GLfloat FoV, GLfloat aspectRatio);
        void setPos(glm::vec3 position);
        void update(GLuint program);
		void sendMatrix(GLuint program);

        void onMouseMotion(float relX, float relY);
        void onKeyDown(SDL_Event& e);

    private:
        glm::mat4 Projection;
        glm::mat4 View;
        glm::mat4 Model;
        glm::mat4 MVP;
        
        glm::vec3 pos = glm::vec3(4, 3, 3);
        glm::vec3 dir;
        glm::vec3 up;
        glm::vec3 right;
        
        GLfloat horizontalAngle = 3.14f;
        GLfloat verticalAngle = 0.0f;
        GLfloat fov = 45.0f;
        GLfloat playerSpeed = 3.0f;
        GLfloat mouseSpeed = 0.005f;
        
        GLint mouseX;
        GLint mouseY;
    };
}

#endif /* defined(__KodeEngine__FPSCamera__) */
