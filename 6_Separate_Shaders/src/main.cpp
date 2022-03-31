// Author: Luke Chikkala

#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaders/shader.h"

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
		// Positions									// Colors
		-0.5f, -0.5f * float(sqrt(3))     / 3, 0.0f,	1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f * float(sqrt(3))     / 3, 0.0f,	0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,	0.0f, 0.0f, 1.0f
	};

	// ---------- Creating that Window
	GLFWwindow* window = glfwCreateWindow(800, 800, "Cause, Traditions :-)", NULL, NULL); // Replace first NULL with 'glfwGetPrimaryMonitor()' to run Full Screen on First Monitor.

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

	Shader ourShader("shaders/shader.vs", "shaders/shader.fs");

	GLuint VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1);

	// ---------- Creating a loop so that the window is displayed until a close action is performed
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

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