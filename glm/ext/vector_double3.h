#ifndef GLM_EXT_VECTOR_DOUBLE3_H
#define GLM_EXT_VECTOR_DOUBLE3_H

#include "../detail/type_vector.h"
#include "../detail/type_vec3.h"

#define glm_dvec3(...) glm_tvec3(double, defaultp, __VA_ARGS__)
#define glm_double3(...) glm_tvec3(double, defaultp, __VA_ARGS__)

#include "vector_bool3.h"

#include "vector_double3.c"

#endif /* GLM_EXT_VECTOR_DOUBLE3_H */