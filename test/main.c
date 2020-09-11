#include <stdio.h>
#include <glm/glm.h>

glm_mat4 glm_lookAtRH(glm_vec3 const eye, glm_vec3 const center, glm_vec3 const up)
{
	glm_mat4 Result = glm_mat4(1);	

	glm_vec3 const f = glm_normalize_vec3( glm_sub_vec3(center, eye) );
	glm_vec3 const s = glm_normalize_vec3( glm_cross_vec3(f, up) );
	glm_vec3 const u = glm_cross_vec3(s, f);

	Result.elem[0][0] = s.x;
	Result.elem[1][0] = s.y;
	Result.elem[2][0] = s.z;
	Result.elem[0][1] = u.x;
	Result.elem[1][1] = u.y;
	Result.elem[2][1] = u.z;
	Result.elem[0][2] = -f.x;
	Result.elem[1][2] = -f.y;
	Result.elem[2][2] = -f.z;
	Result.elem[3][0] = -glm_dot_vec3(s, eye);
	Result.elem[3][1] = -glm_dot_vec3(u, eye);
	Result.elem[3][2] =  glm_dot_vec3(f, eye);

	return Result;
}

int main(int argc, char *argv[])
{
	glm_dvec2 v1 = glm_dvec2(-25.0, 13.37);
	printf("%lf, %lf\n", v1.x, v1.y);

	glm_ivec2 v2 = glm_ivec2(3.14159f, v1);
	printf("%d, %d\n", v2.x, v2.y);

	glm_uvec2 v3 = glm_uvec2(v2);
	printf("%u, %u\n", v3.x, v3.y);

	glm_uvec2 *pv3 = &v3;
	
	glm_vec4 v4 = glm_vec4(5.67f, v1, v2);
	printf("%f, %f, %f, %f\n", v4.x, v4.y, v4.z, v4.w);
	
	glm_addeqs_vec4(&v4, 5.0f);
	printf("%f, %f, %f, %f\n", v4.x, v4.y, v4.z, v4.w);
	
	glm_diveqs_vec4(&v4, 2.0f);
	printf("%f, %f, %f, %f\n", v4.x, v4.y, v4.z, v4.w);

	float len = glm_length_vec4(v4);
	printf("%f\n", len);
	
	v4 = glm_normalize_vec4(v4);

	printf("%f, %f, %f, %f\n", v4.x, v4.y, v4.z, v4.w);

	glm_vec1 v5 = { 5.2f };
	printf("%f\n", v5.x);

	glm_ivec4 v6 = { 1, 2, 3, 4 };
	printf("%d, %d, %d, %d\n", v6.x, v6.y, v6.z, v6.w);

	return 0;
}