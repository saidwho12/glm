#ifndef GLM_EXT_MATRIX_FLOAT2X4_H
#define GLM_EXT_MATRIX_FLOAT2X4_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat2x4.h"

#define glm_mat2x4(...) glm_tmat2x4(float, defaultp, __VA_ARGS__)
#define glm_float2x4(...) glm_tmat2x4(float, defaultp, __VA_ARGS__)

#include "matrix_float2x4.c"

#endif /* GLM_EXT_MATRIX_FLOAT2X4_H */