#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <Windows.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <GL/gl.h>

#include <glm/glm.h>

struct Vertex
{
	glm_vec3 position;
	glm_vec3 normal;
	glm_vec2 uv;
};

struct Extents3D
{
	glm_vec3 x0;
	glm_vec3 x1;
};

struct Model
{
	uint32_t drawCount;
	size_t vertexCount;
	size_t indexCount;
	struct Vertex *vertexArray;
	uint64_t *indexArray;
	bool hasNormals;
	bool hasTexCoords;
	bool isIndexed;
	struct Extents3D bounds;
};

unsigned char *load_entire_file(const char *filename, size_t *data_size)
{
	FILE *file = fopen(filename, "rb");
	unsigned char *data = NULL;
	size_t size;

	if (file)
	{
		fseek(file, 0, SEEK_END);
		size = (size_t)ftell(file);
		fseek(file, 0, SEEK_SET);

		data = (unsigned char *)malloc(size);
		fread(data, 1, size, file);

		*data_size = size;
	}
	else
	{
		printf("Failed to open file at %s\n", filename);
	}

	fclose(file);
	return data;
}

static glm_vec3
glm_make_vec3(float *data)
{
	return *(glm_vec3 *)data;
}

static glm_vec2
glm_make_vec2(float *data)
{
	return *(glm_vec2 *)data;
}

static struct Model
load_obj(const char *filename)
{
	struct Model model;

	size_t obj_string_len;
	char *tmp_string = (char *)load_entire_file(filename, &obj_string_len);
	char *obj_string = (char *)realloc(tmp_string, obj_string_len + 1);
	obj_string[obj_string_len] = '\0';

	printf("read obj string from file (\"%s\")\n", filename);
	printf("address: 0x%08X\n", (uintptr_t)obj_string);
	printf("size in bytes: %lu\n", obj_string_len);

	// Start parsing through the file string

	printf("parsing obj string...\n");
	
	//printf("position count: %lu\n", desc.position_count);
	//printf("uv count: %lu\n", desc.uv_count);
	//printf("normal count: %lu\n", desc.normal_count);
	//printf("face count: %lu\n", desc.face_count);
	float *v_a = NULL; // vec3
	float *vt_a = NULL; // vec2
	float *vn_a = NULL; // vec3
	uint32_t *f_a = NULL; // position/texcoord/normal, 3 uints, 3 times

	size_t v_n = 0;
	size_t vt_n = 0;
	size_t vn_n = 0;
	size_t f_n = 0;

	char *line;
	char token[25];

	line = strtok(obj_string, "\n");

	while (line != NULL && token != NULL)
	{
		sscanf(line, "%s", &token[0]);

		if (strlen(token) == 0) break;
		//token = strtok(beg_line, " \n");
		//printf("%s\n", token);
		//printf("%u\n", f_n);

		if (!strcmp(token, "v")) // Position
		{
			v_a = (float *)realloc(v_a, ++v_n * 3 * sizeof(float));
			float vx, vy, vz;
			sscanf(line, "v %f %f %f", &vx, &vy, &vz);
			v_a[ (v_n-1)*3+0 ] = vx;
			v_a[ (v_n-1)*3+1 ] = vy;
			v_a[ (v_n-1)*3+2 ] = vz;
		}
		else if (!strcmp(token, "vt")) // Texcoords
		{
			vt_a = (float *)realloc(vt_a, ++vt_n * 2 * sizeof(float));
			float vx, vy;
			sscanf(line, "vt %f %f", &vx, &vy);
			vt_a[ (vt_n-1)*2+0 ] = vx;
			vt_a[ (vt_n-1)*2+1 ] = vy;
		}
		else if (!strcmp(token, "vn")) // Normals
		{
			vn_a = (float *)realloc(vn_a, ++vn_n * 3 * sizeof(float));
			float vx, vy, vz;
			sscanf(line, "vn %f %f %f", &vx, &vy, &vz);
			vn_a[ (vn_n-1)*3+0 ] = vx;
			vn_a[ (vn_n-1)*3+1 ] = vy;
			vn_a[ (vn_n-1)*3+2 ] = vz;
		}
		else if (!strcmp(token, "f")) // Face
		{
			f_a = (uint32_t *)realloc(f_a, ++f_n * 9 * sizeof(uint32_t));
			uint32_t vi[3], vti[3], vni[3];
			sscanf(line, "f %u//%u %u//%u %u//%u",
				&vi[0], /*&vti[0],*/ &vni[0],
				&vi[1], /*&vti[1],*/ &vni[1],
				&vi[2], /*&vti[2],*/ &vni[2]);

			for (size_t i = 0; i < 3; ++i)
			{
				//printf("%u\n", vi[i]);
				f_a[ (f_n-1)*9 + i*3+0 ] = vi[i];
				//f_a[ (f_n-1)*9 + i*3+1 ] = vti[i];
				f_a[ (f_n-1)*9 + i*3+2 ] = vni[i];
			}
		}

		line = strtok(NULL, "\n");
		//line = strchr(line, '\n') + 1;//strtok(line, "\n\0") + 1;
	}

	model.vertexArray = (struct Vertex *)malloc(sizeof(struct Vertex) * f_n * 3);
	model.vertexCount = f_n * 3;
	model.drawCount = f_n;

	for (size_t i = 0; i < f_n * 3; ++i)
	{
		struct Vertex vert;
		size_t v_idx = f_a[ i*3+0 ]-1;
		size_t vt_idx = f_a[ i*3+1 ]-1;
		size_t vn_idx = f_a[ i*3+2 ]-1;
		//printf("%u\n", v_idx);
		vert.position = *(glm_vec3*)&v_a[v_idx*3];

		if (vt_n > 0) vert.uv = *(glm_vec2 *)&vt_a[vt_idx*2];
		if (vn_n > 0) vert.normal = *(glm_vec3 *)&vn_a[vn_idx*3];

		model.vertexArray[i] = vert;
	}

	model.hasNormals = vn_n > 0;
	model.hasTexCoords = vt_n > 0;

	model.isIndexed = false;


	free(v_a);
	if (vt_n > 0) free(vt_a);
	if (vn_n > 0) free(vn_a);
	free(f_a);

	printf("parsed %u vertices\n", v_n);

	free(obj_string);

	return model;
}


static void
free_model(const struct Model *model)
{
	free(model->vertexArray);
	free(model->indexArray);
}

static glm_mat4x4
identity(void)
{
	glm_mat4x4 Result = { 0 };

	Result.elem[0][0] = 1.0f;
	Result.elem[1][1] = 1.0f;
	Result.elem[2][2] = 1.0f;
	Result.elem[3][3] = 1.0f;

	return Result;
}

static glm_mat4x4
perspective(float fovy, float aspect, float znear, float zfar)
{
	glm_mat4x4 m = identity();

	float atanHalfFov = 1.0f / tan(fovy/2.0f);
	m.elem[2][2] = -zfar / (zfar - znear);
	m.elem[3][2] = -zfar * znear / (zfar - znear);
	m.elem[2][3] = -1.0f; // set w = -z
	m.elem[3][3] = 0.0f;
	m.elem[0][0] = atanHalfFov;
	m.elem[1][1] = atanHalfFov * aspect;

	return m;
}

static glm_vec4
glm_mul_mat4x4_vec4(glm_mat4x4 m, glm_vec4 v)
{
	glm_vec4 Result;

	Result.elem[0] = m.elem[0][0] * v.x + m.elem[1][0] * v.y + m.elem[2][0] * v.z + m.elem[3][0] * v.w;
	Result.elem[1] = m.elem[0][1] * v.x + m.elem[1][1] * v.y + m.elem[2][1] * v.z + m.elem[3][1] * v.w;
	Result.elem[2] = m.elem[0][2] * v.x + m.elem[1][2] * v.y + m.elem[2][2] * v.z + m.elem[3][2] * v.w;
	Result.elem[3] = m.elem[0][3] * v.x + m.elem[1][3] * v.y + m.elem[2][3] * v.z + m.elem[3][3] * v.w;

	return Result;
}

static void
render_model_gl1(struct Model *model, glm_vec3 *pos, glm_vec3 *scale, float time, float rotSpeed)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();


	//glMultMatrixf((const GLfloat*)&view->elem[0][0]);
/*
	glTranslatef(0.0f, 0.25f * sinf(glfwGetTime()*2.5f), 1.0f);
	glRotatef(glfwGetTime() * M_PI * 16.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.2f, 0.2f, 0.2f);
*/

	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(time * 2.0f * M_PI * rotSpeed, 0.0f, 1.0f, 0.0f);
	glScalef(scale->x, scale->y, scale->z);
	
	glBegin(GL_TRIANGLES);

	for (size_t i = 0; i < model->vertexCount; ++i)
	{
		//glm_vec3 normal = model->vertexArray[i].normal;
		//glm_vec3 lightDir = glm_normalize(glm_vec3(1.0f, 1.0f, 1.0f));
		//glm_vec3 color = glm_vec3(glm_dot(normal, lightDir));
		glNormal3fv(&model->vertexArray[i].normal.elem[0]);

		//glColor3fv(&color.elem[0]);
		glVertex3fv(&model->vertexArray[i].position.elem[0]);
	}

	glEnd();

	glPopMatrix();
}

static void
render(glm_mat4x4 *view, struct Model *teapot, float time)
{
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

	//double aspect = (double)width / (double)height;
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMultMatrixf((const GLfloat*)&view->elem[0][0]);


	//glm_vec4 lightPos0 = glm_vec4(lightPos, 1.0f);

	//lightPos0 = glm_mul_mat4x4_vec4(view, lightPos0);
	//glOrtho(-aspect, aspect, -1.0, 1.0, 1.0, -1.0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);


	{
		glEnable(GL_LIGHT0);
		glm_vec4 lightColorDiff = {5.0f, 5.0f, 5.0f, 0.0f};
		glm_vec4 lightColorAmb = {0.0f, 0.0f, 0.0f, 0.0f};
		glm_vec4 lightColorSpec = {5.0f, 5.0f, 5.0f, 0.0f};

		glm_vec3 lightPos = { 0.0f, 6.0f, -0.0f };
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightColorAmb.elem);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColorDiff.elem);
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightColorSpec.elem);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos.elem);
		float kc = 0.0f;
		float kl = 0.0f;
		float kq = 4.0f * M_PI;
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, kc);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, kl);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, kq);
	}

	{
		glEnable(GL_LIGHT1);
		glm_vec4 lightColorDiff = {0.0f, 0.0f, 2.0f, 0.0f};
		glm_vec4 lightColorAmb = {0.0f, 0.0f, 0.0f, 0.0f};
		glm_vec4 lightColorSpec = {0.0f, 0.0f, 2.0f, 0.0f};

		float a = 2.67f;
		float b = 1.7f;
		float t = time * M_PI * 2.0f;
		float k = M_PI / 4.0f;
		float n = 4.0f;
		float x = a * sinf(t);
		float y = b * cosf(n*t + k);

		glm_vec3 lightPos = { x, y, -1.5f };
		glLightfv(GL_LIGHT1, GL_AMBIENT, lightColorAmb.elem);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColorDiff.elem);
		glLightfv(GL_LIGHT1, GL_SPECULAR, lightColorSpec.elem);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos.elem);
		float kc = 0.0f;
		float kl = 0.0f;
		float kq = 4.0f * M_PI;
		glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, kc);
		glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, kl);
		glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, kq);
	}

	{
		glEnable(GL_LIGHT2);
		glm_vec4 lightColorDiff = {1.5f, 2.0f, 0.0f, 0.0f};
		glm_vec4 lightColorAmb = {0.0f, 0.0f, 0.0f, 0.0f};
		glm_vec4 lightColorSpec = {1.5f, 2.0f, 0.0f, 0.0f};

		float a = 0.15f;
		float b = 0.5f;
		float t = time * M_PI * 0.5f;
		float k = M_PI / 3.5f;
		float n = 4.0f;
		float x = a * sinf(t);
		float y = b * cosf(n*t + k);

		glm_vec3 lightPos = { x, 1.5f, y - 0.5f };
		
		glLightfv(GL_LIGHT2, GL_AMBIENT, lightColorAmb.elem);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColorDiff.elem);
		glLightfv(GL_LIGHT2, GL_SPECULAR, lightColorSpec.elem);
		glLightfv(GL_LIGHT2, GL_POSITION, lightPos.elem);
		float kc = 0.0f;
		float kl = 0.0f;
		float kq = 4.0f * M_PI;
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, kc);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, kl);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, kq);
	}



	{
		GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat diffuse[] = {0.2, 1.0, 0.6, 1.0};
		GLfloat specular[] = {0.2, 1.0, 0.6, 1.0};
		GLfloat shine = 200.0;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);

		float t1 = time * M_PI * 0.74f;
		float s1 = 0.5f + (0.5f + 0.5f * cosf(t1)) * 0.5f;
		float s2 = 1.0f - (0.5f + 0.5f * -sinf(t1)) * 0.5f;

		glm_vec3 scale = { s1 * 0.12f, s2 * 0.12f, s1 * 0.12f };

		glm_vec3 pos = {0.0f, -0.2f + 0.05f * sinf(t1), -0.8f};
		render_model_gl1(teapot, &pos, &scale, time, -22.0f);
	}

	{
		GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat diffuse[] = {1.0, 0.6, 0.14, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 200.0;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);

		float t1 = time * M_PI * 1.84f;
		float s1 = 0.4f + (0.5f + 0.5f * cosf(t1)) * 0.6f;
		float s2 = 1.0f - (0.5f + 0.5f * -sinf(t1)) * 0.6f;

		glm_vec3 scale = { s1 * 0.055f, s2 * 0.055f, s1 * 0.055f };

		glm_vec3 pos = {-0.43f, -0.15 + 0.15f * sinf(t1), -0.8f};
		render_model_gl1(teapot, &pos, &scale, time, 44.0f);
	}

	{
		GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat diffuse[] = {1.0f, 0.85f, 0.74f, 1.0f};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 200.0;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);

		float t1 = time * M_PI * 1.2f;
		float s1 = 0.2f + (0.5f + 0.5f * cosf(t1)) * 0.8f;
		float s2 = 1.0f - (0.5f + 0.5f * -sinf(t1)) * 0.8f;

		glm_vec3 scale = { s1 * 0.08f, s2 * 0.08f, s1 * 0.08f };
		glm_vec3 pos = {0.42f, -0.1f + 0.08f * sinf(t1), -0.8f};
		render_model_gl1(teapot, &pos, &scale, time, 32.0f);
	}

	glPopMatrix();
}

int main(int argc, char *argv[])
{
	struct Model teapot = load_obj("../data/teapot.obj");
	printf("done loading teapot!\n");

	unsigned int width = 640;
	unsigned int height = 480;

	glm_mat4x4 view;

	glfwInit();
	GLFWwindow *window = glfwCreateWindow(width, height, "Teapot", NULL, NULL);
	glfwMakeContextCurrent(window);

	glViewport(0, 0, width, height);
	glClearColor(0.1f, 0.005f, 0.002f, 1.0f);

	bool isQuit = false;

	while (!isQuit)
	{
		glfwPollEvents();

		if (glfwWindowShouldClose(window)) isQuit = true;
		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);

		
		float aspect = (float)width/(float)height;
		view = perspective( 90.0f/360.0f *M_PI*2.0f, aspect, 0.01f, 1000.0f);

		float time = glfwGetTime();
		int n = 8;
		float dt = 1.0f / 24.0f;//10.0f + (0.5f + 0.5f * sinf(time*0.2f*M_PI)) * 14.0f;

		glClear(GL_ACCUM_BUFFER_BIT);

		for (int i = 0; i < n; ++i)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			float t = time + dt * (float)i/(float)n;

			if (fmodf(t, 7.0f) <= 4.5f)
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			render(&view, &teapot, t);


			if(i == 0)
				glAccum(GL_LOAD, 1.0f / (float)n);
			else
				glAccum(GL_ACCUM, 1.0f / (float)n);

			glAccum(GL_ACCUM, 1.0f / (float)n);
		}

		glAccum(GL_RETURN, 1.0f);

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();


	free_model(&teapot);
	return EXIT_SUCCESS;
}