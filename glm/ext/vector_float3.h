#ifndef GLM_EXT_VECTOR_FLOAT3_H
#define GLM_EXT_VECTOR_FLOAT3_H

#include "../detail/type_vector.h"
#include "../detail/type_vec3.h"

#define glm_vec3(...) glm_tvec3(float, defaultp, __VA_ARGS__)
#define glm_float3(...) glm_tvec3(float, defaultp, __VA_ARGS__)

#include "vector_bool3.h"

#include "vector_float3.c"

#endif /* GLM_EXT_VECTOR_FLOAT3_H */