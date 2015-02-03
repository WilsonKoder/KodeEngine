// cube.cpp

#include "cube.h"
#include "mesh.h"
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
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(0, 0)), // triangle 1 : begin
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + 1.0f), glm::vec2(1, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(1, 1)),// triangle 1 : end
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + -1.0f), glm::vec2(1, 1)),// triangle 2 : begin
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + -1.0f), glm::vec2(0, 1)),// triangle 2 : end

		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + 1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(1, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + -1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(0, 1)),

		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(1, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + -1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + 1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + 1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(0, 1)),

		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + -1.0f, zpos + 1.0f), glm::vec2(1, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + 1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + -1.0f), glm::vec2(0, 1)),

		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + -1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(1, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + 1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + -1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + -1.0f), glm::vec2(0, 1)),

		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + -1.0f), glm::vec2(1, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(1, 1)),
		KodeEngine::Vertex(glm::vec3(xpos + -1.0f, ypos + 1.0f, zpos + 1.0f), glm::vec2(0, 0)),
		KodeEngine::Vertex(glm::vec3(xpos + 1.0f, ypos + -1.0f, zpos + 1.0f), glm::vec2(0, 1))
	};
}