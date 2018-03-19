#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"

const int width = 800;
const int height = 800;

float red=0.0f, green=0.0f, blue=0.0f;
int color=0;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
	{
		int temp = color;
		while (color == temp)
		{
			color = rand() % 3;
		}

		switch (color)
		{
		case 0: red = 1.0f, green = 0.0f, blue = 0.0f; break;
		case 1: red = 0.0f, green = 1.0f, blue = 0.0f; break;
		case 2: red = 0.0f, green = 0.0f, blue = 1.0f; break;
		}
	}
		
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		int temp = color;
		while (color == temp)
		{
			color = rand() % 3;
		}

		switch (color)
		{
		case 0: red = 1.0f, green = 0.0f, blue = 0.0f; break;
		case 1: red = 0.0f, green = 1.0f, blue = 0.0f; break;
		case 2: red = 0.0f, green = 0.0f, blue = 1.0f; break;
		}
	}
}

int main(void)
{
	GLFWwindow *window = nullptr;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */

	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

	float px = 0.0f, py = 0.0f;

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		//upadate data
			px += 0.001f;
		
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		//glRotatef(45.0f, 0.0f, 0.0f,1.0f);
		//TODO: draw here
		glBegin(GL_TRIANGLE_FAN);

	
	

		glColor3f(red, green, blue);//Basiclly 3D
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		
		glPopMatrix();
		glEnd();
		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	return 0;
}
