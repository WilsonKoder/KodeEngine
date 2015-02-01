#version 330

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;


uniform mat4 mvp;
out vec4 fragmentColor;
uniform float time;

void main() {
    vec4 v = vec4(vertexPosition_modelspace, 1);
    gl_Position = mvp * v;
}
