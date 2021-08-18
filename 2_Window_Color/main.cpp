//	Luke
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	// ----------> Initialise GLFW Library <----------
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// ---------- Creating that Window
	GLFWwindow* window = glfwCreateWindow(800, 800, "Luke", NULL, NULL);

	// ---------- Displaying the error if the window fails to be created.
	if (window == NULL)
	{
		std::cout << "Failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	// ---------- Using the window that is created above.
	// Make the window's context as current
	glfwMakeContextCurrent(window);

	// ---------- Loading GLAD
	gladLoadGL();

	// ---------- Area of the window that OpenGL needs to render.
	glViewport(0, 0, 800, 800);

	// ---------- Using RGB colors
	int R = 34;
	int G = 43;
	int B = 53;
	float R_normalised = (float)R/255;
	float G_normalised = (float)G/255;
	float B_normalised = (float)B/255;

	// ---------- Clearing the current buffer's color and use the following color.
	glClearColor(R_normalised, G_normalised, B_normalised, 1.0f); // (R, G, B, A)
	glClear(GL_COLOR_BUFFER_BIT);

	// ---------- Swapping front & back buffers.
	// Currently the front buffer is still the default color, black, in my case.
	// We now ask OpenGL to swap those that front buffer with the back buffer, which is where our color information is stored.
	glfwSwapBuffers(window);

	// ---------- Creating a loop so that the window is displayed until a close action is performed
	while (!glfwWindowShouldClose(window))
	{
		// ---------- "Polling" of process events: Appearing, Resizing, etc.
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	// ----------> End <----------
	glfwTerminate();
}