//
//  2DShape.cpp
//  KodeEngine
//
//  Created by Wilson Koder on 17/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#include "Shape.h"
#include <GL\glew.h>

GLuint KodeEngine::Shape::setupShape(GLfloat vertexData[], GLuint numberOfVerts)
{
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, numberOfVerts * sizeof(GLfloat) * 3, vertexData, GL_STATIC_DRAW);
    return vertexBuffer;
}

GLuint KodeEngine::Shape::setupShapeColor(GLfloat *colorData, GLuint numberOfColors, GLuint size)
{
    GLuint colorBuffer;
    glGenBuffers(1, &colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, size, colorData, GL_STATIC_DRAW);
    return colorBuffer;
}

void KodeEngine::Shape::shapeDrawBuffer(GLuint vertexBuffer, GLuint shaderLayoutLoc, GLuint numberOfVerts, GLenum shapeType, GLuint index)
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(shaderLayoutLoc, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glDrawArrays(shapeType, 0, numberOfVerts);
    glEnableVertexAttribArray(0);
}

void KodeEngine::Shape::shapeDrawBufferWithColor(GLuint shapeBuffer, GLuint numOfShapeVerts, GLuint colorBuffer, GLuint colorLayoutLoc, GLuint vertLayoutLoc, GLuint vertIndex, GLuint colorIndex, GLuint shapeType)
{
    glEnableVertexAttribArray(vertIndex);
    glBindBuffer(GL_ARRAY_BUFFER, shapeBuffer);
    glVertexAttribPointer(vertLayoutLoc, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);
    glEnableVertexAttribArray(colorIndex);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(colorLayoutLoc, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glDrawArrays(shapeType, 0, numOfShapeVerts);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}