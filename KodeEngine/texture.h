#ifndef _KodeEngine_Texture_
#define _KodeEngine_Texture_

#include <GL/glew.h>
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