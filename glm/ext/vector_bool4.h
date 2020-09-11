#ifndef GLM_EXT_VECTOR_BOOL4_H
#define GLM_EXT_VECTOR_BOOL4_H

#include "../detail/type_vector.h"
#include "../detail/type_vec4.h"

#define glm_bvec4(...) glm_tvec4(bool, defaultp, __VA_ARGS__)
#define glm_bool4(...) glm_tvec4(bool, defaultp, __VA_ARGS__)

#include "vector_bool4.c"

#endif /* GLM_EXT_VECTOR_BOOL4_H */
