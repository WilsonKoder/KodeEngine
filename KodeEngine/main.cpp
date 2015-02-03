#include <SDL\SDL.h>
#include <GL\glew.h>
#include "KodeEngine.h"
#include <iostream>

void processInput();


int main(int argc, char** argv)
{
	//glFrontFace(GL_CW);
	GLfloat clearColor[3] = { 0.2f, 0.3f, 0.8f };
	int windowSize[2] = { 800, 600 };
	KodeEngine::Window window(windowSize, "Hello!", clearColor);
	
	KodeEngine::Shader shader;
	GLuint vert = shader.compile(GL_VERTEX_SHADER, "shader/image.vert");
	GLuint frag = shader.compile(GL_FRAGMENT_SHADER, "shader/image.frag");
	std::vector<GLuint> shaders = { vert, frag };
	GLuint program = shader.linkShader(shaders);
	
	KodeEngine::Input input;

	KodeEngine::Vertex verts[] = {
		KodeEngine::Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)),
		KodeEngine::Vertex(glm::vec3(0.5, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f)),
		KodeEngine::Vertex(glm::vec3(0.0f, 1.5f, 0.0f), glm::vec2(0.5f, 1.0f))
	};

	KodeEngine::Mesh mesh(verts, sizeof(verts) / sizeof(verts[0]));
	KodeEngine::Texture texture("img/grass.png");
	
	while (!window.isClosed())
	{
		window.clear();

		processInput();

		shader.useShader(program);
		texture.bind(0);
		mesh.draw();

		window.swapBuffers();
	}
	return 0;
}

// Handles SDL events
//KodeEngine::FPSCam& fpsCam
void processInput() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_MOUSEMOTION:
                //fpsCam.onMouseMotion(e.motion.xrel, -e.motion.yrel);
                break;
            case SDL_KEYDOWN:
                //fpsCam.onKeyDown(e);
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    // Stop getting relative mouse movements
                    SDL_SetRelativeMouseMode(SDL_FALSE);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                // Start getting relative mouse motion
                SDL_SetRelativeMouseMode(SDL_TRUE);
                break;
            case SDL_KEYUP:
                break;
            case SDL_QUIT:
                SDL_Quit();
                exit(1);
            default:
                break;
        }
    }
}