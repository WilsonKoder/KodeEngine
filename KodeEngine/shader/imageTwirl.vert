#version 430

layout(location = 0) in vec3 position;
out vec2 texCoord0;
in vec2 texCoord;

uniform mat4 mvp;

void main() {
    vec4 v = vec4(position, 1.0f);
    gl_Position = mvp * v;
    texCoord0 = texCoord;
}
