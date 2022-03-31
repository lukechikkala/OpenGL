// ############### Vertex Shader ###############

#version 330 core

// Position Coordinates
layout (location = 0) in vec3 aPos;

// Color Coordinates
layout (location = 1) in vec3 aColor;

// Texture Coordinates
layout (location = 2) in vec2 aTex;

out vec3 ourColor;
out vec2 texCoord;

uniform float scale;


void main()
{
	gl_Position = vec4(aPos, 1.0);
	ourColor	= aColor;
	texCoord	= aTex;
}
