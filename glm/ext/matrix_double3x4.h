#ifndef GLM_EXT_MATRIX_DOUBLE3X4_H
#define GLM_EXT_MATRIX_DOUBLE3X4_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat3x4.h"

#define glm_dmat3x4(...) glm_tmat3x4(double, defaultp, __VA_ARGS__)
#define glm_double3x4(...) glm_tmat3x4(double, defaultp, __VA_ARGS__)

#include "matrix_double3x4.c"

#endif /* GLM_EXT_MATRIX_DOUBLE3X4_H */