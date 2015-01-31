#ifndef _KodeEngine_cube_h_
#define _KodeEngine_cube_h_

#include <GL\glew.h>
#include <vector>

namespace KodeEngine {
	class Cube {
	public:
		Cube(GLfloat x, GLfloat y, GLfloat z);
		std::vector<GLfloat> cubeVerts;
	private:
		GLfloat xpos, ypos, zpos;
		void initCube();
	};
}

#endif