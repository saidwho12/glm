#include <stdio.h>
#include <math.h>
#include <glm/glm.h>

typedef struct Material
{
	glm_vec3 albedo;
	float roughness;
	float anisotropic;
	float metallic;
	float ior;
} Material_t;

typedef struct Intersection
{
	glm_vec3 position;
	glm_vec3 normal;
	float time; // On the ray
	uint16_t materialID;
} Intersection_t;

typedef struct Sphere
{
	glm_vec3 position;
	float radius;
} Sphere_t;

typedef struct Scene
{
	Material_t *materials;
	uint16_t materialsLen;

	Sphere_t *spheres;
	uint16_t spheresLen;
} Scene_t;

glm_vec3 CosineSampleHemisphere(const float U1, const float U2)
{
	const float r = sqrtf(U1);
	const float theta = 2.0f * M_PI * U2;

	const float x = r * cosf(theta);
	const float y = r * sinf(theta);

	return glm_vec3(x, y, sqrtf(fmaxf(0.0f, 1.0f - U1)));
}

glm_vec3 ImportanceSampleLambertBSDF(const Material_t *mtl, glm_vec3 *wi, const glm_vec3 wo, const float U1, const float U2)
{
	*wi = CosineSampleHemisphere(U1, U2);
	return mtl->albedo;
}

float InverseSquareFalloff(const float r)
{
	return 1.0f / (4.0f * M_PI * r * r);
}

/*
typedef glm_vec3 (*StochasticBSDF)(struct Material *mtl, glm_vec3 *wi, glm_vec3 *wo, float U1, float U2);

glm_vec3 PointLightFunc(struct HitRecord *rec, struct PointLight *light)
{
	glm_vec3 lightDelta = glm_sub(rec->point, light->point);
	float lightDist = glm_length(lightDelta);

	float intensity = InverseSquareFalloff(lightDist);
	float U1 = Random(rng);
	float U2 = Random(rng);
	glm_vec3 color = CosineSampleLambertBSDF(mtl,)
}
*/

typedef struct Random
{
	float seed;
	glm_vec2 coords;
} Random_t;

float Rand(Random_t *rng)
{
	return rng->seed++;
}

glm_vec3 EstimateTangent(const glm_vec3 normal)
{

}

const Material_t *ReferenceMaterialFromID(const Scene_t *scene, uint16_t materialID)
{
	return &scene->materials[materialID];
}

glm_vec3 PathTrace(Scene_t *scene, Random_t *rng, glm_vec3 ro, glm_vec3 rd)
{
	Intersection_t hit = {0};

	glm_vec3 color = glm_vec3(0.0f);
	glm_vec3 falloff = glm_vec3(1.0f);
	glm_vec3 wi;
	glm_vec3 wo;

	for (uint8_t i = 0; i < 8; ++i)
	{
		if (IntersectScene(&hit, scene))
		{
			const Material_t *mtl = ReferenceMaterialFromID(scene, hit.materialID);

			glm_vec3 tangent = EstimateTangent(hit.normal);
			glm_vec3 biTangent = glm_cross(hit.normal, tangent);
			glm_mat3 tangentToWorld = glm_mat3(tangent, biTangent, hit.normal);
			glm_mat3 worldToTangent = glm_inverse(tangentToWorld);

			wo = glm_mul(worldToTangent, glm_negate(rd));

			float U1 = Rand(rng);
			float U2 = Rand(rng);

			if (Rand(rng) < 0.5f)
			{
				// Diffuse shading on this branch
				glm_vec3 diffuse = ImportanceSampleLambertBSDF(mtl, &wi, &wo, U1, U2);
				glm_muleq(&falloff, diffuse);
			}
			else
			{

			}

			ro = hit.position;
			rd = glm_mul(tangentToWorld, wi);
		}
		else
		{
			color = glm_vec3(rd.z*.5f+.5f);
			break;
		}
	}

	return glm_mul(color, falloff);
}




int main(int argc, char *argv[])
{
	//struct HitRecord rec;

	//glm_vec3 lightDelta = glm_sub(rec.point, light.point);

	//glm_vec3 normal = glm_normalize(glm_vec3(2.0f, -2.5f, 25.85f));
	//glm_vec3 tangent = glm_normalize(glm_cross(normal, glm_vec3(0, 1, 0)));
	//glm_vec3 bi_tangent = glm_normalize(glm_cross(normal, tangent));

	//glm_mat3x3 tbn = glm_mat3x3(tangent, bi_tangent, normal);

	return 0;
}