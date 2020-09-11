#ifndef GLM_DETAIL_TYPE_VEC3_H
#define GLM_DETAIL_TYPE_VEC3_H

#include "variadic_param.h"

#define GLM_VEC3_RSEQ() 3,2,1,0

#define GLM_VEC3_CONSTRUCTOR_PARAMS_0(A1, A2, A3)  
#define GLM_VEC3_CONSTRUCTOR_PARAMS_1(A1, A2, A3) GLM_VARIADIC_PARAM(A1)
#define GLM_VEC3_CONSTRUCTOR_PARAMS_2(A1, A2, A3) GLM_VARIADIC_PARAM(A1), GLM_VARIADIC_PARAM(A2)
#define GLM_VEC3_CONSTRUCTOR_PARAMS_3(A1, A2, A3) GLM_VARIADIC_PARAM(A1), GLM_VARIADIC_PARAM(A2), GLM_VARIADIC_PARAM(A3)
#define GLM_VEC3_CONSTRUCTOR_PARAMS_(A1, A2, A3, N, ...) N, GLM_VEC3_CONSTRUCTOR_PARAMS_ ## N (A1, A2, A3)
#define GLM_VEC3_CONSTRUCTOR_PARAMS(...) GLM_VEC3_CONSTRUCTOR_PARAMS_(__VA_ARGS__)

#define GLM_VEC3_CONSTRUCTOR(T, Q, ...) GLM_VECTOR_CONSTRUCTOR_NAME(3, T, Q)(GLM_VEC3_CONSTRUCTOR_PARAMS(__VA_ARGS__, GLM_VEC3_RSEQ()))
#define glm_tvec3(T, Q, ...) GLM_VEC3_CONSTRUCTOR(T, Q, __VA_ARGS__)

#endif /* GLM_DETAIL_TYPE_VEC3_H */