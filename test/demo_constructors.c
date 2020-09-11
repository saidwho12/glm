#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.h>
#include <glm/gtx/print.h>


int main(int argc, char *argv[])
{
	{
		glm_dvec2 v1 = { 1.0, 2.0 };
		glm_uvec2 v2 = { 3, 4 };

		glm_vec4 v3 = glm_vec4(v1, v2);

		glm_print("Demo 1:\n\t vec4({dvec2:1.1}, {uvec2}) -> {vec4:1.}\n\n", v1, v2, v3);
	}

	{
		glm_bvec2 v1 = { false, true };
		glm_vec3 v2 = { 2.0f, 3.0f, 4.0f };

		glm_uvec3 v3 = glm_uvec3(v1, v2);

		glm_print("Demo 2:\n\t uvec3({bvec2}, {vec3:1.1}) -> {uvec3}\n\n", v1, v2, v3);
	}

	{
		float x = 2.56f;
		glm_vec2 v = glm_vec2(x);

		glm_print("Demo 3:\n\t vec2({f}) -> {vec2}\n\n", x, v);
	}

	{
		float x = 1.0f;
		float y = 2.0f;
		float z = 3.0f;
		float w = 4.0f;

		glm_vec4 v = glm_vec4(x, y, z, w);

		glm_print("Demo 4:\n\t vec4({f:1.1}, {f:1.1}, {f:1.1}, {f:1.1}) -> {vec4:1.1}\n\n", x,y,z,w,v);
	}

	{
		glm_vec2 v1 = { 12.0f, 25.32f };
		glm_mat2x2 m1 = { 11.2f, 8.21f, 3.24f, 4.64f };

		glm_vec4 v = glm_vec4(v1, m1);

	}

	{
		glm_vec2 v1 = { 1.0f, 2.0f };
		glm_vec2 v2 = { 3.0f, 4.0f };

		glm_mat2 m1 = glm_mat2(v1,v2);

		printf("[[%f %f],\n [%f %f]]\n",
			m1.elem[0][0], m1.elem[0][1],
			m1.elem[1][0], m1.elem[1][1]
			);

	}

	{
		glm_vec3 v1 = {1.0f, 2.0f, 3.0f};
		glm_vec3 v2 = {1.0f, 2.0f, 3.0f};
		glm_vec3 v3 = {1.0f, 2.0f, 3.0f};
		glm_mat3 m1 = glm_mat3(v1, v2, v3);

		printf("[[%f %f %f],\n [%f %f %f],\n [%f %f %f]]\n",
		       m1.elem[0][0], m1.elem[0][1], m1.elem[0][2],
		       m1.elem[1][0], m1.elem[1][1], m1.elem[1][2],
		       m1.elem[2][0], m1.elem[2][1], m1.elem[2][2]
		);
  }

	return EXIT_SUCCESS;
}
