#ifndef GLM_EXT_MATRIX_DOUBLE2X4_H
#define GLM_EXT_MATRIX_DOUBLE2X4_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat2x4.h"

#define glm_dmat2x4(...) glm_tmat2x4(double, defaultp, __VA_ARGS__)
#define glm_double2x4(...) glm_tmat2x4(double, defaultp, __VA_ARGS__)

#include "matrix_double2x4.c"

#endif /* GLM_EXT_MATRIX_DOUBLE2X4_H */