#ifndef GLM_EXT_MATRIX_DOUBLE2X2_H
#define GLM_EXT_MATRIX_DOUBLE2X2_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat2x2.h"

#define glm_dmat2x2(...) glm_tmat2x2(double, defaultp, __VA_ARGS__)
#define glm_dmat2(...) glm_tmat2x2(double, defaultp, __VA_ARGS__)
#define glm_double2x2(...) glm_tmat2x2(double, defaultp, __VA_ARGS__)

#include "matrix_double2x2.c"

#endif /* GLM_EXT_MATRIX_DOUBLE2X2_H */