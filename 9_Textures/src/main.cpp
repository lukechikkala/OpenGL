// Author: Luke Chikkala

#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "resources/stb/stb_image.h"

#include "resources/shaders/shader.h"

void processInput(GLFWwindow *window);

int main()
{
	// ----------> Start <----------
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLfloat vertices[] =
	{
	// // i		// Positions			// Colors
	// /* 0 */		-0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 1.0f,		0.0f, 0.0f,
	// /* 1 */		-0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 1.0f,		0.0f, 1.0f,
	// /* 2 */		 0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 0.0f,		1.0f, 1.0f,
	// /* 3 */		 0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,		1.0f, 0.0f
//					Positions									// Colors					// Texture
//					  X		  Y		 Z							 R		 G		 B			
	/* 0[A] */		-0.4f,	-0.4f,	0.0f,		/* Cyan */		0.0f,	1.0f,	1.0f,		0.0f, 0.0f,		//##
	/* 1[B] */		-0.4f,	 0.6f,	0.0f,		/* Cyan */		0.0f,	1.0f,	1.0f,		0.0f, 1.0f,		//##
	/* 2[C] */		-0.1f,	 0.6f,	0.0f,		/* Magenta */	1.0f,	0.0f,	1.0f,		0.3f, 1.0f,		//##
	/* 3[D] */		-0.1f,	-0.1f,	0.0f,		/* Magenta */	1.0f,	0.0f,	1.0f,		0.3f, 0.3f,
	/* 4[E] */		 0.2f,	-0.1f,	0.0f,		/* Yellow */	1.0f,	1.0f,	0.0f,		0.6f, 0.3f,
	/* 5[F] */		 0.2f,	-0.4f,	0.0f,		/* Yellow */	1.0f,	1.0f,	0.0f,		0.6f, 0.0f,
	/* 6[G] */		-0.1f,	-0.4f,	0.0f,		/* Magenta */	1.0f,	0.0f,	1.0f,		0.3f, 0.0f		//##
	};

	GLuint indices[]=
	{
		// 0, 1, 2,
		// 0, 2, 3
		0, 1, 2,
		0, 2, 6,
		6, 3, 4,
		6, 4, 5
	};

	// ---------- Creating that Window
	GLFWwindow* window = glfwCreateWindow(800, 800, "Texture Surrender", NULL, NULL); // Replace first NULL with 'glfwGetPrimaryMonitor()' to run Full Screen on First Monitor.

	// ---------- Displaying the error if the window fails to be created.
	if (window == NULL)
	{
		std::cout << "Failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	// ---------- Using the window that is created above.
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 800);

	Shader ourShader("resources/shaders/shader.vs", "resources/shaders/shader.fs");

	GLuint VAO, VBO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6* sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Texture
	int ImgW, ImgH, NumColCh;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load("resources/brikz.png", &ImgW, &ImgH, &NumColCh, 0);

	GLuint texture;
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Some comments from Victor Gordan
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ImgW, ImgH, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint tex0Uni = glGetUniformLocation(ourShader.ID, "tex0");
	glUniform1i(tex0Uni, 0);

	// ---------- Creating a loop so that the window is displayed until a close action is performed
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();
		glBindVertexArray(VAO);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteTextures(1, &texture);

	// ----------> End <----------
	glfwTerminate();
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}