#ifndef GLM_EXT_VECTOR_INT4_H
#define GLM_EXT_VECTOR_INT4_H

#include "../detail/type_vector.h"
#include "../detail/type_vec4.h"

#define glm_ivec4(...) glm_tvec4(int, defaultp, __VA_ARGS__)
#define glm_int4(...) glm_tvec4(int, defaultp, __VA_ARGS__)

#include "vector_bool4.h"

#include "vector_int4.c"

#endif /* GLM_EXT_VECTOR_INT4_H */