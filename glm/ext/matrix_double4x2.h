#ifndef GLM_EXT_MATRIX_DOUBLE4X2_H
#define GLM_EXT_MATRIX_DOUBLE4X2_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat4x2.h"

#define glm_dmat4x2(...) glm_tmat4x2(double, defaultp, __VA_ARGS__)
#define glm_double4x2(...) glm_tmat4x2(double, defaultp, __VA_ARGS__)

#include "matrix_double4x2.c"

#endif /* GLM_EXT_MATRIX_DOUBLE4X2_H */