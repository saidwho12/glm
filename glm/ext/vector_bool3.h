#ifndef GLM_EXT_VECTOR_BOOL3_H
#define GLM_EXT_VECTOR_BOOL3_H

#include "../detail/type_vector.h"
#include "../detail/type_vec3.h"

#define glm_bvec3(...) glm_tvec3(bool, defaultp, __VA_ARGS__)
#define glm_bool3(...) glm_tvec3(bool, defaultp, __VA_ARGS__)

#include "vector_bool3.c"

#endif /* GLM_EXT_VECTOR_BOOL3_H */
