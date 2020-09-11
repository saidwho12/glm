#ifndef GLM_EXT_VECTOR_FLOAT4_H
#define GLM_EXT_VECTOR_FLOAT4_H

#include "../detail/type_vector.h"
#include "../detail/type_vec4.h"

#define glm_vec4(...) glm_tvec4(float, defaultp, __VA_ARGS__)
#define glm_float4(...) glm_tvec4(float, defaultp, __VA_ARGS__)

#include "vector_bool4.h"

#include "vector_float4.c"

#endif /* GLM_EXT_VECTOR_FLOAT4_H */