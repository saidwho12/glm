#ifndef GLM_EXT_MATRIX_DOUBLE3X3_H
#define GLM_EXT_MATRIX_DOUBLE3X3_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat3x3.h"

#define glm_dmat3x3(...) glm_tmat3x3(double, defaultp, __VA_ARGS__)
#define glm_dmat3(...) glm_tmat3x3(double, defaultp, __VA_ARGS__)
#define glm_double3x3(...) glm_tmat3x3(double, defaultp, __VA_ARGS__)

#include "matrix_double3x3.c"

#endif /* GLM_EXT_MATRIX_DOUBLE3X3_H */