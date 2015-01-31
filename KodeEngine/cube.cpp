// cube.cpp

#include "cube.h"
#include <vector>

KodeEngine::Cube::Cube(GLfloat x, GLfloat y, GLfloat z)
{
	xpos = x;
	ypos = y;
	zpos = z;

	initCube();
}

void KodeEngine::Cube::initCube()
{
	cubeVerts = {
		xpos + -1.0f, ypos + -1.0f, zpos + -1.0f, // triangle 1 : begin
		xpos + -1.0f, ypos + -1.0f, zpos + 1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + 1.0f, // triangle 1 : end
		xpos + 1.0f, ypos + 1.0f, zpos + -1.0f, // triangle 2 : begin
		xpos + -1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + -1.0f, // triangle 2 : end
		xpos + 1.0f, ypos + -1.0f, zpos + 1.0f,
		xpos + -1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + 1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + 1.0f, ypos + 1.0f, zpos + -1.0f,
		xpos + 1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + -1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + -1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + -1.0f,
		xpos + 1.0f, ypos + -1.0f, zpos + 1.0f,
		xpos + -1.0f, ypos + -1.0f, zpos + 1.0f,
		xpos + -1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + -1.0f, ypos + -1.0f, zpos + 1.0f,
		xpos + 1.0f, ypos + -1.0f, zpos + 1.0f,
		xpos + 1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + 1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + 1.0f, ypos + 1.0f, zpos + -1.0f,
		xpos + 1.0f, ypos + -1.0f, zpos + -1.0f,
		xpos + 1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + 1.0f, ypos + -1.0f, zpos + 1.0f,
		xpos + 1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + 1.0f, ypos + 1.0f, zpos + -1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + -1.0f,
		xpos + 1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + -1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + 1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + -1.0f, ypos + 1.0f, zpos + 1.0f,
		xpos + 1.0f, ypos + -1.0f, zpos + 1.0f
	};
}