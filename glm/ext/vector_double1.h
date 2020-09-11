#ifndef GLM_EXT_VECTOR_DOUBLE1_H
#define GLM_EXT_VECTOR_DOUBLE1_H

#include "../detail/type_vector.h"
#include "../detail/type_vec1.h"

#define glm_dvec1(...) glm_tvec1(double, defaultp, __VA_ARGS__)
#define glm_double1(...) glm_tvec1(double, defaultp, __VA_ARGS__)

#include "vector_bool1.h"

#include "vector_double1.c"

#endif /* GLM_EXT_VECTOR_DOUBLE1_H */