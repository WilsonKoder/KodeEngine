#version 120

attribute vec3 position;
varying vec2 texCoord0;
attribute vec2 texCoord;

void main() {
	gl_Position.xyz = position;
	gl_Position.w = 1.0;
	texCoord0 = texCoord;
}