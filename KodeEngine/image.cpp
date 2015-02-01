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
#include <picopng.h>
#include <picopng.cpp>
#include "IOManager.h"
#include <cassert>

KodeEngine::Image::Image(std::string &fileName)
{
    KodeEngine::IOManager iomanager;
    
    if (iomanager.readFileToBuffer(fileName, imgData) == false)
    {
        std::cerr << "Couldn't open file: " << fileName << std::endl;
        exit(2);
    }

    std::vector<unsigned char> resultPixels;
    unsigned long width;
    unsigned long height;
    int errorCode = KodeEngine::decodePNG(resultPixels, width, height, imgData.data(), imgData.size());
    
    if (errorCode != 0)
    {
        std::cerr << "Could not decode PNG: " << fileName << std::endl;
        exit(3);
    }
    
    texWidth = width;
    texHeight = height;

	glGenTextures(1, &tex);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex);

	// set up attributes
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData.data());

	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // handle minification linearly
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // handle magnification linearly
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // repeat texture on x
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // repeat texture on y

}

KodeEngine::Image::~Image()
{
    std::cout << "destroyed image" << std::endl;
}

void KodeEngine::Image::bind(GLuint unit)
{
	assert(unit >= 0 && unit <= 31);
	glActiveTexture(0 + unit);
	glBindTexture(GL_TEXTURE_2D, tex);
}

void KodeEngine::Image::destroyTexture()
{
    glDeleteTextures(1, &tex);
}

unsigned long KodeEngine::Image::getWidth()
{
    return texWidth;
}

unsigned long KodeEngine::Image::getHeight()
{
    return texHeight;
}

unsigned long KodeEngine::Image::getChannels()
{
    return texChannels;
}