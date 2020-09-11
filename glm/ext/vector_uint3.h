#ifndef GLM_EXT_VECTOR_UINT3_H
#define GLM_EXT_VECTOR_UINT3_H

#include "../detail/type_vector.h"
#include "../detail/type_vec3.h"

#define glm_uvec3(...) glm_tvec3(uint, defaultp, __VA_ARGS__)
#define glm_uint3(...) glm_tvec3(uint, defaultp, __VA_ARGS__)

#include "vector_bool3.h"

#include "vector_uint3.c"

#endif /* GLM_EXT_VECTOR_UINT3_H */