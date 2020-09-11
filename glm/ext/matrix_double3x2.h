#ifndef GLM_EXT_MATRIX_DOUBLE3X2_H
#define GLM_EXT_MATRIX_DOUBLE3X2_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat3x2.h"

#define glm_dmat3x2(...) glm_tmat3x2(double, defaultp, __VA_ARGS__)
#define glm_double3x2(...) glm_tmat3x2(double, defaultp, __VA_ARGS__)

#include "matrix_double3x2.c"

#endif /* GLM_EXT_MATRIX_DOUBLE3X2_H */