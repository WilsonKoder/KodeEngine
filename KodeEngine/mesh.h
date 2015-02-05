#ifndef __KodeEngine_mesh__
#define __KodeEngine_mesh__

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "vertex.h"

namespace KodeEngine {

	class Mesh {
	public:
		Mesh(Vertex* verticies, GLuint numVerticies);
		~Mesh();
		void draw();
	private:

		enum {
			POSITION_VB,
			TEXCOORD_VB,
			NUM_BUFFERS
		};
		
		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		GLuint m_drawCount;
	};
}

#endif