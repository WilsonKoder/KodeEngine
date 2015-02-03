#ifndef _KodeEngine_cube_h_
#define _KodeEngine_cube_h_

#include <GL\glew.h>
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