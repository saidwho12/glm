#ifndef GLM_EXT_VECTOR_DOUBLE2_H
#define GLM_EXT_VECTOR_DOUBLE2_H

#include "../detail/type_vector.h"
#include "../detail/type_vec2.h"

#define glm_dvec2(...) glm_tvec2(double, defaultp, __VA_ARGS__)
#define glm_double2(...) glm_tvec2(double, defaultp, __VA_ARGS__)

#include "vector_bool2.h"

#include "vector_double2.c"

#endif /* GLM_EXT_VECTOR_DOUBLE2_H */