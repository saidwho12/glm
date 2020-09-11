#ifndef GLM_EXT_VECTOR_INT2_H
#define GLM_EXT_VECTOR_INT2_H

#include "../detail/type_vector.h"
#include "../detail/type_vec2.h"

#define glm_ivec2(...) glm_tvec2(int, defaultp, __VA_ARGS__)
#define glm_int2(...) glm_tvec2(int, defaultp, __VA_ARGS__)

#include "vector_bool2.h"

#include "vector_int2.c"

#endif /* GLM_EXT_VECTOR_INT2_H */