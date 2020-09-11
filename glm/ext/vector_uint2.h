#ifndef GLM_EXT_VECTOR_UINT2_H
#define GLM_EXT_VECTOR_UINT2_H

#include "../detail/type_vector.h"
#include "../detail/type_vec2.h"

#define glm_uvec2(...) glm_tvec2(uint, defaultp, __VA_ARGS__)
#define glm_uint2(...) glm_tvec2(uint, defaultp, __VA_ARGS__)

#include "vector_bool2.h"

#include "vector_uint2.c"

#endif /* GLM_EXT_VECTOR_UINT2_H */