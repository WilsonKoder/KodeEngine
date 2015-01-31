//
//  FPSCamera.cpp
//  KodeEngine
//
//  Created by Wilson Koder on 20/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#include "FPSCamera.h"
#include <glm/gtc/matrix_transform.hpp>

KodeEngine::FPSCam::FPSCam(GLfloat FoV, GLfloat aspectRatio)
{
    if(FoV != 0)
    {
        Projection = glm::perspective(FoV, aspectRatio, 0.01f, 1000.0f);
        fov = FoV;
    }
    else
    {
        Projection = glm::perspective(90.0f, aspectRatio, 0.01f, 1000.0f);
        fov = 90.0f;
    }
    View = glm::lookAt(pos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    Model = glm::mat4(15.0f);
}

void KodeEngine::FPSCam::setPos(glm::vec3 position)
{
    pos = position;
}

void KodeEngine::FPSCam::update(GLuint program)
{
    dir = glm::vec3(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle), cos(verticalAngle) * cos(horizontalAngle));
    right = glm::vec3(sin(horizontalAngle - 3.14 / 2.0f), 0, cos(horizontalAngle - 3.14f / 2.0f));
    up = glm::cross(right, dir);
    
    View = glm::lookAt(pos, pos + dir, up);
    MVP = Projection * View * Model;
    sendMatrix(program);
}

void KodeEngine::FPSCam::sendMatrix(GLuint program)
{
    GLuint mvpID = glGetUniformLocation(program, "mvp");
    glUniformMatrix4fv(mvpID, 1, GL_FALSE, &MVP[0][0]);
}

void KodeEngine::FPSCam::onMouseMotion(float relX, float relY) {
    horizontalAngle -= mouseSpeed * 0.2f * relX;
    verticalAngle += mouseSpeed * 0.2f * relY;
}

void KodeEngine::FPSCam::onKeyDown(SDL_Event& e) {

    if (e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_UP) {
        pos += dir * 0.05f * playerSpeed;
    } else if (e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_DOWN) {
        pos -= dir * 0.05f * playerSpeed;
    }
    if (e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_LEFT) {
        pos -= right * 0.05f * playerSpeed;
    } else if (e.key.keysym.sym == SDLK_d || e.key.keysym.sym == SDLK_RIGHT) {
        pos += right * 0.05f * playerSpeed;
    }
    if (e.key.keysym.sym == SDLK_SPACE) {
        pos += up * 0.05f * playerSpeed;
    } else if (e.key.keysym.sym == SDLK_LSHIFT) {
        pos -= up * 0.05f * playerSpeed;
    }
    
    View = glm::lookAt(pos, pos + dir, up);
    MVP = Projection * View * Model;
}
