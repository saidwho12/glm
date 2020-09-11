#ifndef GLM_EXT_MATRIX_FLOAT4X3_H
#define GLM_EXT_MATRIX_FLOAT4X3_H

#include "../detail/type_matrix.h"
#include "../detail/type_mat4x3.h"

#define glm_mat4x3(...) glm_tmat4x3(float, defaultp, __VA_ARGS__)
#define glm_float4x3(...) glm_tmat4x3(float, defaultp, __VA_ARGS__)

#include "matrix_float4x3.c"

#endif /* GLM_EXT_MATRIX_FLOAT4X3_H */