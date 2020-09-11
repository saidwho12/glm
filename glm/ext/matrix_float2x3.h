#ifndef GLM_EXT_MATRIX_FLOAT2X3_H
#define GLM_EXT_MATRIX_FLOAT2X3_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat2x3.h"

#define glm_mat2x3(...) glm_tmat2x3(float, defaultp, __VA_ARGS__)
#define glm_float2x3(...) glm_tmat2x3(float, defaultp, __VA_ARGS__)

#include "matrix_float2x3.c"

#endif /* GLM_EXT_MATRIX_FLOAT2X3_H */