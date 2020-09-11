#ifndef GLM_EXT_MATRIX_FLOAT3X2_H
#define GLM_EXT_MATRIX_FLOAT3X2_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat3x2.h"

#define glm_mat3x2(...) glm_tmat3x2(float, defaultp, __VA_ARGS__)
#define glm_float3x2(...) glm_tmat3x2(float, defaultp, __VA_ARGS__)

#include "matrix_float3x2.c"

#endif /* GLM_EXT_MATRIX_FLOAT3X2_H */