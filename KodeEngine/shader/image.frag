#version 330 core
out vec4 color;
smooth in vec3 vUV;
uniform sampler2D texMap;

void main()
{
    color = texture(texMap, 1.0f);
}