#ifndef GLM_EXT_MATRIX_FLOAT3X3_H
#define GLM_EXT_MATRIX_FLOAT3X3_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat3x3.h"

#define glm_mat3x3(...) glm_tmat3x3(float, defaultp, __VA_ARGS__)
#define glm_mat3(...) glm_tmat3x3(float, defaultp, __VA_ARGS__)
#define glm_float3x3(...) glm_tmat3x3(float, defaultp, __VA_ARGS__)

#include "matrix_float3x3.c"

#endif /* GLM_EXT_MATRIX_FLOAT3X3_H */