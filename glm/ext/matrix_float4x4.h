#ifndef GLM_EXT_MATRIX_FLOAT4X4_H
#define GLM_EXT_MATRIX_FLOAT4X4_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat4x4.h"

#define glm_mat4x4(...) glm_tmat4x4(float, defaultp, __VA_ARGS__)
#define glm_mat4(...) glm_tmat4x4(float, defaultp, __VA_ARGS__)
#define glm_float4x4(...) glm_tmat4x4(float, defaultp, __VA_ARGS__)

#include "matrix_float4x4.c"

#endif /* GLM_EXT_MATRIX_FLOAT4X4_H */