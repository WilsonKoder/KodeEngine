#version 330

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 mvp;
smooth out vec3 vUV;

void main() {
    vec4 v = vec4(vertexPosition_modelspace, 1);
    vUV = vertexPosition_modelspace;
    gl_Position = mvp * v;
}