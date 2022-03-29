// Author: Luke Chikkala

#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaders/shader.h"

void processInput(GLFWwindow *window);

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLfloat vertices[] =
	{
//		Positions									// Colors
//		  X		  Y		 Z							 R		 G		 B
		-0.4f,	-0.4f,	0.0f,		/* Cyan */		0.0f,	1.0f,	1.0f,	//	0	A
		-0.4f,	 0.6f,	0.0f,		/* Cyan */		0.0f,	1.0f,	1.0f,	//	1	B
		-0.1f,	 0.6f,	0.0f,		/* Magenta */	1.0f,	0.0f,	1.0f,	//	2	C
		-0.1f,	-0.1f,	0.0f,		/* Magenta */	1.0f,	0.0f,	1.0f,	//	3	D
		 0.2f,	-0.1f,	0.0f,		/* Yellow */	1.0f,	1.0f,	0.0f,	//	4	E
		 0.2f,	-0.4f,	0.0f,		/* Yellow */	1.0f,	1.0f,	0.0f,	//	5	F
		-0.1f,	-0.4f,	0.0f,		/* Magenta */	1.0f,	0.0f,	1.0f	//	6	G
	};

	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 6,
		6, 3, 4,
		6, 4, 5
	};

	GLFWwindow* window = glfwCreateWindow(800, 800, "Here I Am, Will You Send Me (Tri)angle", NULL, NULL); // Replace first NULL with 'glfwGetPrimaryMonitor()' to run Full Screen on First Monitor.

	if (window == NULL)
	{
		std::cout << "Failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 800);

	Shader ourShader("shaders/shader.vs", "shaders/shader.fs");

	GLuint VAO, VBO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwTerminate();
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}