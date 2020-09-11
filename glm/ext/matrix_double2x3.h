#ifndef GLM_EXT_MATRIX_DOUBLE2X3_H
#define GLM_EXT_MATRIX_DOUBLE2X3_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat2x3.h"

#define glm_dmat2x3(...) glm_tmat2x3(double, defaultp, __VA_ARGS__)
#define glm_double2x3(...) glm_tmat2x3(double, defaultp, __VA_ARGS__)

#include "matrix_double2x3.c"

#endif /* GLM_EXT_MATRIX_DOUBLE2X3_H */