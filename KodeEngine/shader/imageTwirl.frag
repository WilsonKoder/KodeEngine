#version 430
out vec3 color;
in vec2 texCoord0;
uniform sampler2D diffuse;
uniform float twirl;

void main() {
    vec2 twirlVec = vec2(2, 1) * vec2(cos(twirl), sin(twirl));
    vec2 texCoords = texCoord0 * twirlVec;
    gl_FragColor = texture2D(diffuse, (texCoords + 0.5f));
}
