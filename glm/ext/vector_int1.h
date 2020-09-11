#ifndef GLM_EXT_VECTOR_INT1_H
#define GLM_EXT_VECTOR_INT1_H

#include "../detail/type_vector.h"
#include "../detail/type_vec1.h"

#define glm_ivec1(...) glm_tvec1(int, defaultp, __VA_ARGS__)
#define glm_int1(...) glm_tvec1(int, defaultp, __VA_ARGS__)

#include "vector_bool1.h"

#include "vector_int1.c"

#endif /* GLM_EXT_VECTOR_INT1_H */