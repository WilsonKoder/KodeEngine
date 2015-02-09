#ifndef _KodeEngine_Texture_
#define _KodeEngine_Texture_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#endif
#ifdef _WIN32
#define GLEW
#include <GL/glew.h>
#endif

#include <string>

namespace KodeEngine {
	class Texture {
	public:
		Texture(const std::string& fileName);

		void bind(GLuint unit);

		~Texture();
	private:
		GLuint m_texture;

	};
}

#endif