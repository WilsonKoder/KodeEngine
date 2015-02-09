//
//  2DShape.h
//  KodeEngine
//
//  Created by Wilson Koder on 17/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#ifndef __KodeEngine___DShape__
#define __KodeEngine___DShape__

#include <stdio.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#endif
#ifdef _WIN32
#define GLEW
#include <GL/glew.h>
#endif

namespace KodeEngine {
    class Shape {
    public:
        static GLuint setupShape(GLfloat vertexData[], GLuint numberOfVerts);
        static GLuint setupShapeColor(GLfloat colorData[], GLuint numberOfColors, GLuint size);
        static void shapeDrawBuffer(GLuint vertexBuffer, GLuint shaderLayoutLoc, GLuint numberOfVerts, GLenum shapeType, GLuint index);
        static void shapeDrawBufferWithColor(GLuint shapeBuffer, GLuint numOfShapeVerts, GLuint colorBuffer, GLuint colorLayoutLoc, GLuint vertLayoutLoc, GLuint vertIndex, GLuint colorIndex, GLuint shapeType);
		static void shapeDrawWithTexture(GLuint shapeBuffer, GLuint numVerts, GLuint tex, GLuint texLayoutLoc, GLuint vertLayoutLoc, GLuint vertIndex, GLuint texIndex, GLuint shapeType);
    };
}


#endif /* defined(__KodeEngine___DShape__) */
