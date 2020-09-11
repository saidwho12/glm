#ifndef GLM_EXT_MATRIX_DOUBLE4X3_H
#define GLM_EXT_MATRIX_DOUBLE4X3_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat4x3.h"

#define glm_dmat4x3(...) glm_tmat4x3(double, defaultp, __VA_ARGS__)
#define glm_double4x3(...) glm_tmat4x3(double, defaultp, __VA_ARGS__)

#include "matrix_double4x3.c"

#endif /* GLM_EXT_MATRIX_DOUBLE4X3_H */