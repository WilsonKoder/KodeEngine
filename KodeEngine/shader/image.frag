#version 330 core
out vec4 color;

uniform sampler2D diffuse;

void main() {
    color = texture2D(diffuse, vec2(0.2, 0.2));
}