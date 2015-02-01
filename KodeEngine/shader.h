//
//  shader.h
//  KodeEngine
//
//  Created by Wilson Koder on 15/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#ifndef __KodeEngine__shader__
#define __KodeEngine__shader__

#include <string>
#include <GL\glew.h>
#include <vector>

namespace KodeEngine {
    class Shader {
    public:
        GLuint compile(GLenum shaderType, std::string filePath);
        GLuint linkShader(std::vector<GLuint> shaderIDs);
        void useShader(GLuint program);
		GLuint getUniformLocation(GLuint program, const std::string uniformName);
		void sendVec3Layout(GLuint loc, GLuint buffer, GLuint index);
    private:
        GLuint programID;
    };
}

#endif /* defined(__KodeEngine__shader__) */
