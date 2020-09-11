#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.h>
#include <glm/gtx/print.h>

int main(int argc, char *argv[])
{
	{
		glm_vec2 v1 = { 1.25f, 2.73f };
		glm_vec2 v2 = { 42.13f, 64.55f };
		glm_bvec2 v3 = glm_lessThan(v1, v2);

		glm_print("Demo 1:\n\t {vec2:2.2} < {vec2:2.2} = {bvec2}\n\n", v1, v2, v3);
	}

	{
		glm_vec3 v1 = { 2.05f, 2.74f, 1.5f };
		glm_vec3 v2 = { -5.35f, 1.4f, 2.5f };
		float s = glm_dot(v1, v2);

		glm_print("Demo 2:\n\t dot({vec3:2.1}, {vec3:2.1}) = {f:2.0}\n\n", v1, v2, s);
	}

	{
		glm_vec1 pi = { 3.141592653589793f };
		glm_print("Demo 3:\n\t {vec1:1.2}\n\n", pi);
	}

	{
		glm_vec3 v1 = { 2.5f, 2.6f, -1.5f };
		glm_vec3 v2 = glm_normalize(v1);

		glm_print("Demo 4:\n\t normalize({vec3:1.2}) = {vec3}\n\n", v1, v2);
	}

	{
		glm_uvec2 v = { 0xDEAD, 0xF00D };
		bool b = v.x <= v.y;

		glm_print("Demo 5:\n\t For {uvec2}, x <= y = {b}\n\n", v, b);
	}

	{
		glm_vec3 v = { 2.53f, 74.3f, 22.32f };

		float f = glm_length(v);
		glm_print("Demo 6:\n\t length({vec3}) = {f}\n\n", v, f);
	}

	return EXIT_SUCCESS;
}