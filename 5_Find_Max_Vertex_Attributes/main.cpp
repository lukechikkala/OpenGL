// Author: Luke Chikkala
#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	GLFWwindow* window = glfwCreateWindow(800, 800, "Cause, Traditions :-)", NULL, NULL); // Replace first NULL with 'glfwGetPrimaryMonitor()' to run Full Screen on First Monitor.
	glfwMakeContextCurrent(window);
	gladLoadGL();

	int nrAttribs;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttribs);
	std::cout << "This hardware supports a maximum number of \"" << nrAttribs << "\" vertex attributes." << std::endl;

	glfwDestroyWindow(window);
	glfwTerminate();
}