#ifndef GLM_EXT_MATRIX_FLOAT3X4_H
#define GLM_EXT_MATRIX_FLOAT3X4_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat3x4.h"

#define glm_mat3x4(...) glm_tmat3x4(float, defaultp, __VA_ARGS__)
#define glm_float3x4(...) glm_tmat3x4(float, defaultp, __VA_ARGS__)

#include "matrix_float3x4.c"

#endif /* GLM_EXT_MATRIX_FLOAT3X4_H */