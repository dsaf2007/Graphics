#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <iostream>
#include "math.h"

const int width_window = 640;
const int height_window = 640;

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
	//�ӿ� ���� �� ���� �׸���.
	int i;
	int triangleAmount = 200; //���� �׸��µ� ����� �ﰢ�� ����.

							 
	GLfloat twicePi = 2.0f * 3.141592f;//������ �ι�

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // �߽� ��ǥ.
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}
void drawFilledEllipse(GLfloat x, GLfloat y, GLfloat radius) {
	//�ﰢ���� �̿��Ͽ� Ÿ���� �׸��� �Լ�
	//���� �׸��� �Լ����� x��ǥ�� ������ ������ �������� �ϰ� y��ǥ�� ������ ������ 90���η� �Ͽ���.
	int i;
	int triangleAmount = 200; 

							  
	GLfloat twicePi = 2.0f * 3.141592f;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); 
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius / 2 * cos(i *  twicePi / triangleAmount)),
			y + (radius*0.9 * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}

void parabola() {
	//�Ը���� �׸��� �Լ�.
	//�������� �̿��Ͽ���.
	GLfloat midY = -0.25;
	GLfloat midX = 0.0;

	GLfloat y = 0;

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);//������ ���� �̿��Ͽ�, ������ �� ���� ���� ��´�.
	for (float a = 0; a < 0.025; a += 0.0005)
	{
		for (GLfloat x = -0.25; x <= 0.25; x += 0.0005) {
			y = x * x;
			glVertex2f(midX + x, midY + y + a);
		}
	}
	glEnd();
	glFlush();
}
int main(void)
{
	GLFWwindow *window = nullptr;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width_window, height_window, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// callbacks here
	

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	//glOrtho(0, 1, 0, 1, -1.0, 1.0);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//TODO: draw here
		//glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f);
		drawFilledCircle(0, 0, 0.5);
		glColor3f(1.0f, 1.0f, 0.0f);
		drawFilledCircle(0, 0, 0.48);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawFilledEllipse(0.15, 0.15, 0.1);
		drawFilledEllipse(-0.15, 0.15, 0.1);
		parabola();

		//glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	return 0;
}

