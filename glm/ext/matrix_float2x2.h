#ifndef GLM_EXT_MATRIX_FLOAT2X2_H
#define GLM_EXT_MATRIX_FLOAT2X2_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat2x2.h"

#define glm_mat2x2(...) glm_tmat2x2(float, defaultp, __VA_ARGS__)
#define glm_mat2(...) glm_tmat2x2(float, defaultp, __VA_ARGS__)
#define glm_float2x2(...) glm_tmat2x2(float, defaultp, __VA_ARGS__)

#include "matrix_float2x2.c"

#endif /* GLM_EXT_MATRIX_FLOAT2X2_H */