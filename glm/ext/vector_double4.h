#ifndef GLM_EXT_VECTOR_DOUBLE4_H
#define GLM_EXT_VECTOR_DOUBLE4_H

#include "../detail/type_vector.h"
#include "../detail/type_vec4.h"

#define glm_dvec4(...) glm_tvec4(double, defaultp, __VA_ARGS__)
#define glm_double4(...) glm_tvec4(double, defaultp, __VA_ARGS__)

#include "vector_bool4.h"

#include "vector_double4.c"

#endif /* GLM_EXT_VECTOR_DOUBLE4_H */