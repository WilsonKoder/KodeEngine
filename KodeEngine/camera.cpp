//
//  camera.cpp
//  KodeEngine
//
//  Created by Wilson Koder on 18/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#endif
#ifdef _WIN32
#define GLEW
#include <GL/glew.h>
#endif

KodeEngine::Camera::Camera(GLfloat fov, GLfloat aspectRatio)
{
    Projection = glm::perspective(fov, aspectRatio, 0.1f, 100.0f);
    ar = aspectRatio;
    View = glm::lookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    Model = glm::mat4(1.0f);
    MVP = Projection * View * Model;
}

void KodeEngine::Camera::updateFoV(GLfloat fov)
{
    Projection = glm::perspective(fov, ar, 0.1f, 100.0f);
    MVP = Projection * View * Model;
}

glm::mat4& KodeEngine::Camera::getMVP()
{
    return MVP;
}

glm::mat4 KodeEngine::Camera::getProjection()
{
    return Projection;
}

glm::mat4 KodeEngine::Camera::getView()
{
    return View;
}
glm::mat4 KodeEngine::Camera::getModel()
{
    return Model;
}

void KodeEngine::Camera::cameraLookAt(glm::vec3 point, glm::vec3 up)
{
    View = glm::lookAt(currentPosition, point, up);
    MVP = Projection * View * Model;
    look = point;
}

void KodeEngine::Camera::setCameraPosition(glm::vec3 position, glm::vec3 up)
{
    View = glm::lookAt(position, look, up);
    MVP = Projection * View * Model;
    currentPosition = position;
}

void KodeEngine::Camera::rotate(GLfloat amount, glm::vec3 axis)
{
    View = glm::rotate(View, amount, axis);
    MVP = Projection * View * Model;
    rotation += amount;
    currentRot = rotation;
}

void KodeEngine::Camera::scale(glm::vec3 amount)
{
    View = glm::scale(View, amount);
    MVP = Projection * View * Model;
}

void KodeEngine::Camera::uploadMatrix(GLuint program)
{
    GLuint mvpID = glGetUniformLocation(program, "mvp");
    glUniformMatrix4fv(mvpID, 1, GL_FALSE, &MVP[0][0]);
}