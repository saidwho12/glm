#ifndef GLM_EXT_VECTOR_BOOL2_H
#define GLM_EXT_VECTOR_BOOL2_H

#include "../detail/type_vector.h"
#include "../detail/type_vec2.h"

#define glm_bvec2(...) glm_tvec2(bool, defaultp, __VA_ARGS__)
#define glm_bool2(...) glm_tvec2(bool, defaultp, __VA_ARGS__)

#include "vector_bool2.c"

#endif /* GLM_EXT_VECTOR_BOOL2_H */
