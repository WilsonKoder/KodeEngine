#include <SDL\SDL.h>
#include <GL\glew.h>
//#include <Windows.h>
#include "KodeEngine.h"
#include <iostream>

void processInput(KodeEngine::FPSCam& fpsCam);

int main(int argc, char** argv)
{
	GLfloat time = 0.0f;
	int windowSize[2] = { 960, 540 };
	GLfloat clearColor[3] = { 0.0f, 0.0f, 0.0f };
	KodeEngine::Window window(windowSize, "Hello!", clearColor);
	KodeEngine::Shader shader;
	std::string img = "img/grass.png";
	KodeEngine::Image image(img);
	GLuint tex = image.tex;

	GLuint vertexShader = shader.compile(GL_VERTEX_SHADER, "shader/image.vert"); // xcode path issue.
	GLuint fragShader = shader.compile(GL_FRAGMENT_SHADER, "shader/image.frag"); // xcode path issue.
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

	std::vector<KodeEngine::Cube> cubes;
	std::vector<std::vector<GLuint>> buffers;

	for (GLfloat x = 0; x < 32; x += 2.5)
	{
		for (GLfloat y = 0; y < 32; y += 2.5)
		{
			for (GLfloat z = 0; z < 32; z += 2.5)
			{
				std::cout << "created cube at coords: " << x << ", " << y << ", " << z << std::endl;
				KodeEngine::Cube cube(x, y, z);
				cubes.push_back(cube);
			}
		}
	}

	for (auto &cube : cubes)
	{
		GLuint buffer = KodeEngine::Shape::setupShape(cube.cubeVerts.data(), 36);
		GLuint colorBuffer = KodeEngine::Shape::setupShapeColor(colorData, 36, sizeof(colorData));
		std::vector<GLuint> bufferList = { buffer, colorBuffer };
		buffers.push_back(bufferList);
	}

    // So we can get relative mouse motion
    SDL_SetRelativeMouseMode(SDL_TRUE);

	fpsCam.setPos(glm::vec3(34, 34, 34));
	fpsCam.sendMatrix(program);

	while (!window.isClosed())
	{
		time += 0.01f;
		
		window.clear();

		shader.useShader(program);

        processInput(fpsCam);

		for (auto &bufferList : buffers)
		{
			image.bind(0);
			KodeEngine::Shape::shapeDrawBufferWithColor(bufferList[0], 36, bufferList[1], 1, 0, 0, 1, GL_TRIANGLES);
		}

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