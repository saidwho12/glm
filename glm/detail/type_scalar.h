#ifndef GLM_DETAIL_TYPE_SCALAR_H
#define GLM_DETAIL_TYPE_SCALAR_H

#include "setup.h"
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint16_t   glm_float16;
typedef float      glm_float32;
typedef double     glm_float64;
typedef uint8_t    glm_uint8;
typedef uint16_t   glm_uint16;
typedef uint32_t   glm_uint32;
typedef int8_t     glm_int8;
typedef int16_t    glm_int16;
typedef int32_t    glm_int32;
typedef uint32_t   uint;

#undef bool
typedef _Bool bool;
typedef _Bool glm_bool;

#define bool bool

typedef size_t glm_length_t;

/* Typedefs for different precision */
#define GLM_SCALAR_TYPENAME_float_defaultp   float32
#define GLM_SCALAR_TYPENAME_float_highp      float32
#define GLM_SCALAR_TYPENAME_float_mediump    float16
#define GLM_SCALAR_TYPENAME_float_lowp   

#define GLM_SCALAR_TYPENAME_bool_defaultp   bool
#define GLM_SCALAR_TYPENAME_bool_highp      bool
#define GLM_SCALAR_TYPENAME_bool_mediump    bool
#define GLM_SCALAR_TYPENAME_bool_lowp   

#define GLM_SCALAR_TYPENAME_double_defaultp  float64
#define GLM_SCALAR_TYPENAME_double_highp     float64
#define GLM_SCALAR_TYPENAME_double_mediump   float32
#define GLM_SCALAR_TYPENAME_double_lowp      float16

#define GLM_SCALAR_TYPENAME_uint_defaultp    uint32
#define GLM_SCALAR_TYPENAME_uint_highp       uint32
#define GLM_SCALAR_TYPENAME_uint_mediump     uint16
#define GLM_SCALAR_TYPENAME_uint_lowp        uint8

#define GLM_SCALAR_TYPENAME_int_defaultp     int32
#define GLM_SCALAR_TYPENAME_int_highp        int32
#define GLM_SCALAR_TYPENAME_int_mediump      int16
#define GLM_SCALAR_TYPENAME_int_lowp         int8

/*
    Macros for generating function calls, for both float32 and float64 for instance 
    (T, Q) -> (Type, Qualifier) e.g (float, defaultp) -> float32
*/
#define GLM_SCALAR_TYPENAME_(T, Q) GLM_SCALAR_TYPENAME_ ## T ## _ ## Q
#define GLM_SCALAR_TYPENAME(...) GLM_SCALAR_TYPENAME_(__VA_ARGS__)

#define glm_scalar(T, Q) GLM_PREFIX(GLM_SCALAR_TYPENAME(T, Q))

#define GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, F)   GLM_CALL_FUNC(F, GLM_SCALAR_TYPENAME(T, Q))

/* Handles calls to different functions (scalar) */
#define glm_compute_cos_scalar(T, Q)            GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_cos)
#define glm_compute_sin_scalar(T, Q)            GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_sin)
#define glm_compute_tan_scalar(T, Q)            GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_tan)
#define glm_compute_asin_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_asin)
#define glm_compute_acos_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_acos)
#define glm_compute_atan_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_atan)
#define glm_compute_atan2_scalar(T, Q)          GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_atan2)
#define glm_compute_sinh_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_sinh)
#define glm_compute_cosh_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_cosh)
#define glm_compute_tanh_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_tanh)
#define glm_compute_sqrt_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_sqrt)
#define glm_compute_inversesqrt_scalar(T, Q)    GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_inversesqrt)
#define glm_compute_pow_scalar(T, Q)            GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_pow)
#define glm_compute_exp_scalar(T, Q)            GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_exp)
#define glm_compute_exp2_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_exp2)
#define glm_compute_log_scalar(T, Q)            GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_log)
#define glm_compute_log2_scalar(T, Q)           GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_log2)
#define glm_compute_abs_scalar(T, Q)            GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_abs)
#define glm_compute_floor_scalar(T, Q)          GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_floor)
#define glm_compute_trunc_scalar(T, Q)          GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_trunc)
#define glm_compute_round_scalar(T, Q)          GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_round)
#define glm_compute_mod_scalar(T, Q)            GLM_CALL_COMPUTE_FUNC_SCALAR(T, Q, compute_mod)

#include "scalar_float32.inl"
#include "scalar_float64.inl"

#endif /* GLM_DETAIL_TYPE_SCALAR_H */