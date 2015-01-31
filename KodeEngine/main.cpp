#include <SDL\SDL.h>
#include <GL\glew.h>
#include <Windows.h>
#include "KodeEngine.h"

void processInput(KodeEngine::FPSCam& fpsCam);

int main(int argc, char** argv)
{
	int windowSize[2] = { 960, 540 };
	GLfloat clearColor[3] = { 0.0f, 0.0f, 0.0f };
	KodeEngine::Window window(windowSize, "Hello!", clearColor);
	KodeEngine::Shader shader;

	//std::string pathToImage = "/Users/WilsonKoder/Desktop/dp.png";
	//KodeEngine::Image image(pathToImage);
	//GLuint tex = image.tex;

	GLuint vertexShader = shader.compile(GL_VERTEX_SHADER, "shader/inColor.vert"); // xcode path issue.
	GLuint fragShader = shader.compile(GL_FRAGMENT_SHADER, "shader/inColor.frag"); // xcode path issue.
	std::vector<GLuint> shaders = { vertexShader, fragShader };
	GLuint program = shader.linkShader(shaders);
	shader.useShader(program);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);

	GLfloat colorData[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
	};
	GLuint cubeBuffer = KodeEngine::Shape::setupShape(KodeEngine::cubeVerts, 36);
	GLuint colorBuffer = KodeEngine::Shape::setupShapeColor(colorData, 36, sizeof(colorData));

	GLfloat FoV = 45.0f;
	GLfloat aspectRatio = 960.0f / 540.0f;

	KodeEngine::FPSCam fpsCam(FoV, aspectRatio);

    // So we can get relative mouse motion
    SDL_SetRelativeMouseMode(SDL_TRUE);

	fpsCam.setPos(glm::vec3(4, 3, 3));
	fpsCam.sendMatrix(program);

	while (!window.isClosed())
	{
		window.clear();

        processInput(fpsCam);

		KodeEngine::Shape::shapeDrawBufferWithColor(cubeBuffer, 36, colorBuffer, 1, 0, 0, 1, GL_TRIANGLES);

		KodeEngine::Shape::shapeDrawBuffer(cubeBuffer, 0, 3, GL_TRIANGLES, 0);

		fpsCam.update(program);

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