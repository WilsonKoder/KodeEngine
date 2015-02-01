#version 330 core

in vec4 fragmentColor;
out vec4 color;

uniform float time;

void main() {
    color = fragmentColor + vec(1.0 * (cos(time) + 1.0) * 0.5,
                                1.0 * (cos(time + 2.0) + 1.0) * 0.5,
                                1.0 * (sin(time + 1.0) + 1.0) * 0.5
}
