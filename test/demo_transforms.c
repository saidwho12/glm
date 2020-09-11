#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.h>
#include <glm/gtx/print.h>

typedef struct
{
	glm_vec3 position;
	float fov;
	float aspect;
	glm_vec3 forward;
} Camera;

glm_mat4 GetCameraViewProjection(const Camera *cam)
{
	glm_mat4 p = glm_perspective(cam->fov, cam->aspect, 0.01f, 1000.0f);
	
	glm_mat4 v = glm_lookAt(cam->position,
		glm_add(cam->position, cam->forward),
		glm_vec3(0.0f, 1.0f, 0.0f));

	return glm_mul_float4x4_float4x4(p, v);
}

int main(int argc, char *argv[])
{
	Camera cam;

	glm_mat4 vp = GetCameraViewProjection(&cam);

	return EXIT_SUCCESS;
}