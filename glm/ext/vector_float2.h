#ifndef GLM_EXT_VECTOR_FLOAT2_H
#define GLM_EXT_VECTOR_FLOAT2_H

#include "../detail/type_vector.h"
#include "../detail/type_vec2.h"

#define glm_vec2(...) glm_tvec2(float, defaultp, __VA_ARGS__)
#define glm_float2(...) glm_tvec2(float, defaultp, __VA_ARGS__)

#include "vector_bool2.h"

#include "vector_float2.c"

#endif /* GLM_EXT_VECTOR_FLOAT2_H */