#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(640, 480, "Triangle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);

		glVertex2f(-0.5f, -0.5);
		glVertex2f( 0.0f,  0.5);
		glVertex2f( 0.5f, -0.5);

		glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}