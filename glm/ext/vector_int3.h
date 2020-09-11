#ifndef GLM_EXT_VECTOR_INT3_H
#define GLM_EXT_VECTOR_INT3_H

#include "../detail/type_vector.h"
#include "../detail/type_vec3.h"

#define glm_ivec3(...) glm_tvec3(int, defaultp, __VA_ARGS__)
#define glm_int3(...) glm_tvec3(int, defaultp, __VA_ARGS__)

#include "vector_bool3.h"

#include "vector_int3.c"

#endif /* GLM_EXT_VECTOR_INT3_H */