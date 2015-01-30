#include <SDL\SDL.h>
#include <GL\glew.h>
#include <Windows.h>
#include "KodeEngine.h"

int main(int argc, char** argv)
{
	int windowSize[2] = { 800, 600 };
	GLfloat clearColor[3] = { 0.0f, 0.0f, 0.0f };
	KodeEngine::Window window(windowSize, "Hello!", clearColor);
	KodeEngine::Shader shader;

	//std::string pathToImage = "/Users/WilsonKoder/Desktop/dp.png";
	//KodeEngine::Image image(pathToImage);
	//GLuint tex = image.tex;

	GLuint vertexShader = shader.compile(GL_VERTEX_SHADER, "C:/Users\Wilson\Desktop\Programming\Projects\KodeEngine\KodeEngine\shader\basic.vert"); // xcode path issue.
	GLuint fragShader = shader.compile(GL_FRAGMENT_SHADER, "C:/Users\Wilson\Desktop\Programming\Projects\KodeEngine\KodeEngine\shader\basic.frag"); // xcode path issue.
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
	GLfloat aspectRatio = 1280.0f / 720.0f;

	KodeEngine::FPSCam fpsCam(FoV, aspectRatio);
	fpsCam.setPos(glm::vec3(4, 3, 3));
	fpsCam.sendMatrix(program);

	while (!window.isClosed())
	{
		window.clear();

		fpsCam.checkInput();

		KodeEngine::Shape::shapeDrawBufferWithColor(cubeBuffer, 36, colorBuffer, 1, 0, 0, 1, GL_TRIANGLES);

		KodeEngine::Shape::shapeDrawBuffer(cubeBuffer, 0, 3, GL_TRIANGLES, 0);

		fpsCam.update(window, program);

		window.swapBuffers();
	}

	return 0;
}