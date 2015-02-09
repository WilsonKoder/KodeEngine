#ifndef _KodeEngine_cube_h_
#define _KodeEngine_cube_h_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#endif
#ifdef _WIN32
#define GLEW
#include <GL/glew.h>
#endif
#include <vector>
#include "mesh.h"

namespace KodeEngine {
	class Cube {
	public:
		Cube(GLfloat x, GLfloat y, GLfloat z);
		std::vector<KodeEngine::Vertex> cubeVerts;
	private:
		GLfloat xpos, ypos, zpos;
		void initCube();
	};
}

#endif