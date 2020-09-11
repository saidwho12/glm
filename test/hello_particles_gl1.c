#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <Windows.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <gl/GL.h>

#include <glm/glm.h>

#define PI 3.14159

void update_viewport(GLFWwindow *win)
{
	int width, height;
	double aspect;
	glfwGetFramebufferSize(win, &width, &height);
	aspect = (double)width / (double)height;
	glViewport(0, 0, width, height);
	glLoadIdentity();
	glOrtho(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);
}

typedef struct
{
	glm_vec3 pos;
	glm_vec3 vel;
	glm_vec3 col;
	float scale;
} particle;

float random_uniform(void)
{
	//return (float)(rand() % 0xFFFFFFFF) / (float)0xFFFFFFFF;
	return (float)rand() / (float)RAND_MAX;
}

glm_vec3 random_velocity(float magnitude)
{
	float U1 = random_uniform();
	float U2 = random_uniform();
	float U3 = random_uniform();
	float theta = U1 * 2.0f * PI;
	float phi = U2 * PI;
	float sinTheta = sinf(theta);
	float sinPhi = sinf(phi);
	float cosTheta = cosf(theta);
	float cosPhi = cosf(phi);
	float r = (0.01f + 0.9f * U3) * magnitude;
	glm_vec3 w = glm_vec3( sinPhi * sinTheta, sinPhi * cosTheta, cosPhi );
	glm_muleqs_vec3(&w, r);
	return w;
}

glm_vec3 color_hsv(float hue, float saturation, float value)
{
	glm_vec3 wave = glm_sin_vec3( glm_muls_vec3(glm_adds_vec3(glm_vec3(0,0.333f, 0.666f), hue), 2.0f * PI));
	glm_vec3 rgb = glm_adds_vec3( glm_muls_vec3( wave, 0.5f ), 0.5f);
	return glm_muls_vec3(glm_mixs_vec3( glm_vec3(1), rgb, saturation), value);
}

void update_particle(particle *p, float dt)
{
	p->pos = glm_add_vec3(p->pos, glm_muls_vec3(p->vel, dt));
}

int main(int argc, char *argv[])
{
	srand( time(NULL) );
	particle         particles[100];

	for (unsigned int i = 0; i < 100; ++i)
	{
		particles[i].pos   = glm_vec3(0.0, 0.0, 0.0);
		particles[i].vel   = random_velocity(0.8f);
		particles[i].scale = 0.25f + 0.5f * random_uniform();
		particles[i].col   = color_hsv(random_uniform(), random_uniform(), random_uniform());
	}


	if(!glfwInit())
	{
		/* Failed to initialize GLFW */
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow *win = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
	if(win == NULL)
	{
		/* Failed to create window */
	}

	glfwMakeContextCurrent(win);

	update_viewport(win);

	bool isQuit = false;
	float currTime = (float)glfwGetTime();
	float lastTime;

	glClearColor(0.5f, 0.5f, 0.75f, 1.0f);

	while(!isQuit)
	{
		lastTime = currTime;
		currTime = (float)glfwGetTime();
		float deltaTime = currTime - lastTime;

		glfwPollEvents();
		isQuit = glfwWindowShouldClose(win);
		update_viewport(win);


		for(unsigned int i = 0; i < 100; ++i)
		{
			update_particle(&particles[i], deltaTime);
		}

		glClear(GL_COLOR_BUFFER_BIT);
		for(unsigned int i = 0; i < 100; ++i)
		{
			glPushMatrix();

			particle const *p = &particles[i];
			glm_vec3 const *pos = &p->pos;
			
			glScalef(p->scale, p->scale, p->scale);
			glTranslatef(pos->x, pos->y, pos->z);
			
			// Draw triangle
			glColor3f(p->col.r, p->col.g, p->col.b);

			glBegin(GL_TRIANGLES);
			glVertex3f(-0.5f, -0.5f, 0.0f);
			glVertex3f(0.5f, -0.5f, 0.0f);
			glVertex3f(0.0f, 0.5f, 0.0f);
			glEnd();

			glPopMatrix();
		}
		

		glfwSwapBuffers(win);
	}


	glfwDestroyWindow(win);

	glfwTerminate();
	return 0;
}