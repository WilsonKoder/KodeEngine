//
//  image.cpp
//  KodeEngine
//
//  Created by Wilson Koder on 22/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#include "image.h"
#include <GL\glew.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "IOManager.h"
#include <cassert>

KodeEngine::Image::Image(std::string &fileName)
{
	glEnable(GL_TEXTURE_2D);

	int numComponents;
	unsigned char* imageData = stbi_load(fileName.c_str(), &texWidth, &texHeight, &numComponents, 4);
	
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(imageData);
}

KodeEngine::Image::~Image()
{
	glDeleteTextures(1, &tex);
    std::cout << "destroyed image" << std::endl;
}

void KodeEngine::Image::bind(GLuint unit)
{
	assert(unit >= 0 && unit <= 31);
	glActiveTexture(0 + unit);
	glBindTexture(GL_TEXTURE_2D, tex);
}

int KodeEngine::Image::getWidth()
{
    return texWidth;
}

int KodeEngine::Image::getHeight()
{
    return texHeight;
}

int KodeEngine::Image::getChannels()
{
    return texChannels;
}