#include <SDL\SDL.h>
#include <GL\glew.h>
#include "KodeEngine.h"
#include <iostream>
#include "voxelWorld.h"

void processInput(KodeEngine::FPSCam& fpsCam);


int main(int argc, char** argv)
{

	GLfloat clearColor[3] = { 0.2f, 0.3f, 0.8f };
	int windowSize[2] = { 960, 540 };
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
		KodeEngine::Vertex(glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f))
	};

	//KodeEngine::Cube cube1(1, 1, 1);
	//KodeEngine::Mesh mesh(cube1.cubeVerts.data(), 36);

	VoxelWorld::World world(10, 10, 10, 10);

	KodeEngine::Texture texture("img/wood.jpg");

	KodeEngine::FPSCam fpsCam(45.0f, 16.0f / 9.0f);
	fpsCam.setPos(glm::vec3(4, 3, 3));
	fpsCam.lookAt(glm::vec3(0, 0, 0));
	
	while (!window.isClosed())
	{
		fpsCam.update(program);
		window.clear();

		processInput(fpsCam);

		shader.useShader(program);
		
		texture.bind(0);

		world.draw();

		window.swapBuffers();
	}
	return 0;
}

// Handles SDL events
void processInput(KodeEngine::FPSCam& fpsCam) {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_MOUSEMOTION:
                fpsCam.onMouseMotion(e.motion.xrel, -e.motion.yrel);
                break;
            case SDL_KEYDOWN:
                fpsCam.onKeyDown(e);
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