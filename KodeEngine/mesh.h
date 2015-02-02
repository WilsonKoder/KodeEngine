#ifndef __KodeEngine_mesh__
#define __KodeEngine_mesh__

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

namespace KodeEngine {

	class Vertex {
	public:
		Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
		{
			this->position = pos;
			this->texCoord = texCoord;
		}
		
		inline glm::vec3* getPos() { return &position; };
		inline glm::vec2* getTexCoord() { return &texCoord; };

	private:
		glm::vec3 position;
		glm::vec2 texCoord;
	};

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