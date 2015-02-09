//
//  camera.h
//  KodeEngine
//
//  Created by Wilson Koder on 18/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#ifndef __KodeEngine__camera__
#define __KodeEngine__camera__

#include <glm/glm.hpp>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#endif
#ifdef _WIN32
#define GLEW
#include <GL/glew.h>
#endif

namespace KodeEngine {
    class Camera {
    public:
        Camera(GLfloat fov, GLfloat aspectRatio);
        void setCameraPosition(glm::vec3 position, glm::vec3 up);
        void cameraLookAt(glm::vec3 point, glm::vec3 up);
        void uploadMatrix(GLuint program);
        void rotate(GLfloat amount, glm::vec3 axis);
        void scale(glm::vec3 amount);
        void updateFoV(GLfloat fov);
        glm::mat4& getMVP();
        glm::mat4 getProjection();
        glm::mat4 getView();
        glm::mat4 getModel();
    private:
        GLfloat ar;
        GLfloat rotation = 0;
        GLfloat currentRot;
        glm::vec3 look;
        glm::vec3 currentPosition;
        glm::mat4 Projection;
        glm::mat4 View;
        glm::mat4 Model;
        glm::mat4 MVP;
    };
}

#endif /* defined(__KodeEngine__camera__) */
