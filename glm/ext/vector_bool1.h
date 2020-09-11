#ifndef GLM_EXT_VECTOR_BOOL1_H
#define GLM_EXT_VECTOR_BOOL1_H

#include "../detail/type_vector.h"
#include "../detail/type_vec1.h"

#define glm_bvec1(...) glm_tvec1(bool, defaultp, __VA_ARGS__)
#define glm_bool1(...) glm_tvec1(bool, defaultp, __VA_ARGS__)

#include "vector_bool1.c"

#endif /* GLM_EXT_VECTOR_BOOL1_H */
