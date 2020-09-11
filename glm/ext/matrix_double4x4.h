#ifndef GLM_EXT_MATRIX_DOUBLE4X4_H
#define GLM_EXT_MATRIX_DOUBLE4X4_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat4x4.h"

#define glm_dmat4x4(...) glm_tmat4x4(double, defaultp, __VA_ARGS__)
#define glm_dmat4(...) glm_tmat4x4(double, defaultp, __VA_ARGS__)
#define glm_double4x4(...) glm_tmat4x4(double, defaultp, __VA_ARGS__)

#include "matrix_double4x4.c"

#endif /* GLM_EXT_MATRIX_DOUBLE4X4_H */