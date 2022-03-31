// ############### Fragment Shader ###############

#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

// Inputs Vertex Coordinates from Vertex Shader
in  vec3 ourColor;

// Inputs Texture Coordinates from Vertex Shader
in vec2 texCoord;

uniform sampler2D tex0;



void main()
{

//	FragColor = vec4(ourColor, 1.0);
	FragColor = texture(tex0, texCoord);

}
