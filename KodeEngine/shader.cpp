//
//  shader.cpp
//  KodeEngine
//
//  Created by Wilson Koder on 15/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#include "shader.h"
#include "IOManager.h"
#include <iostream>
#include <GL\glew.h>
#include <algorithm>

GLuint KodeEngine::Shader::compile(GLenum shaderType, std::string filePath)
{
    KodeEngine::IOManager io;
    GLuint shaderID = glCreateShader(shaderType);
    
    std::string shaderCode = io.readFileToString(filePath);
    
    GLint result = GL_FALSE;
    int infoLogLength;
    
    // compile
    std::cout << "compiling shader " << filePath << std::endl;
    char const* sourcePointer = shaderCode.c_str();
    glShaderSource(shaderID, 1, &sourcePointer, NULL);
    glCompileShader(shaderID);
    
    //check compile
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    std::vector<char> shaderErrorMsg(infoLogLength);
    glGetShaderInfoLog(shaderID, infoLogLength, NULL, &shaderErrorMsg[0]);
    if (result != GL_TRUE) {
        std::cout << shaderErrorMsg.data() << std::endl;
    }

    return shaderID;
}

GLuint KodeEngine::Shader::linkShader(std::vector<GLuint> shaderIDs)
{
    GLint result = GL_FALSE;
    int infoLogLength;
    
    programID = glCreateProgram();
    for (auto &shaderID : shaderIDs)
    {
        glAttachShader(programID, shaderID);
    }
    glLinkProgram(programID);
    glGetProgramiv(programID, GL_LINK_STATUS, &result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
    std::vector<char> ProgramErrorMessage(std::max(infoLogLength, int(1)));
    glGetProgramInfoLog(programID, infoLogLength, NULL, &ProgramErrorMessage[0]);
    
    if (result != GL_TRUE) {
        std::cout << ProgramErrorMessage.data() << std::endl;
    }

    for(auto &shaderID : shaderIDs)
    {
        glDeleteShader(shaderID);
    }
    
    return programID;
}

void KodeEngine::Shader::useShader(GLuint program)
{
    glUseProgram(program);
}

