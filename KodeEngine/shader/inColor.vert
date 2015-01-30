#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;

uniform mat4 mvp;

out vec3 fragmentColor;

void main() {
    vec4 v = vec4(vertexPosition_modelspace, 1);
    gl_Position = mvp * v;
    fragmentColor = vertexColor;
}