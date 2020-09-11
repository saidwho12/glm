#ifndef GLM_EXT_VECTOR_FLOAT1_H
#define GLM_EXT_VECTOR_FLOAT1_H

#include "../detail/type_vector.h"
#include "../detail/type_vec1.h"

#define glm_vec1(...) glm_tvec1(float, defaultp, __VA_ARGS__)
#define glm_float1(...) glm_tvec1(float, defaultp, __VA_ARGS__)

#include "vector_bool1.h"

#include "vector_float1.c"

#endif /* GLM_EXT_VECTOR_FLOAT1_H */