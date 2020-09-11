#ifndef GLM_DETAIL_SETUP_H
#define GLM_DETAIL_SETUP_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <inttypes.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include <memory.h>

#define GLM_FUNC_QUALIFIER static inline
#define GLM_CONSTEXPR

#define GLM_VECTOR_LENGTH(v) (sizeof(v)/sizeof(v.e[0]))

#define GLM_EVAL(...) __VA_ARGS__


#define GLM_PREFIX_(x) glm_ ## x
#define GLM_PREFIX(...) GLM_PREFIX_(__VA_ARGS__)

//#define GLM_NAMESPACE(...) GLM_NAMESPACE_(__VA_ARGS__)
/*
#define glm_vec_(L, T, Q) glm_ ## T ## L
#define glm_vec(...) glm_vec_(__VA_ARGS__)
*/

//#define glm_vec(...) glm_typename_vec_(__VA_ARGS__)/*glm_nameof_vec_(__VA_ARGS__)*/

#define GLM_EVAL(...) __VA_ARGS__
#define GLM_PASTE_(A, B) A ## B
#define GLM_PASTE(...) GLM_PASTE_(__VA_ARGS__)
#define GLM_CALL_FUNC_(Func, Type)  GLM_PASTE(Func, _## Type)
#define GLM_CALL_FUNC(...) GLM_PREFIX(GLM_CALL_FUNC_(__VA_ARGS__))


/*
#define GLM_VECTOR_TYPENAME_bool1   bvec1
#define GLM_VECTOR_TYPENAME_bool2   bvec2
#define GLM_VECTOR_TYPENAME_bool3   bvec3
#define GLM_VECTOR_TYPENAME_bool4   bvec4

#define GLM_VECTOR_TYPENAME_float1  vec1
#define GLM_VECTOR_TYPENAME_float2  vec2
#define GLM_VECTOR_TYPENAME_float3  vec3
#define GLM_VECTOR_TYPENAME_float4  vec4

#define GLM_VECTOR_TYPENAME_double1 dvec1
#define GLM_VECTOR_TYPENAME_double2 dvec2
#define GLM_VECTOR_TYPENAME_double3 dvec3
#define GLM_VECTOR_TYPENAME_double4 dvec4

#define GLM_VECTOR_TYPENAME_int1    ivec1
#define GLM_VECTOR_TYPENAME_int2    ivec2
#define GLM_VECTOR_TYPENAME_int3    ivec3
#define GLM_VECTOR_TYPENAME_int4    ivec4

#define GLM_VECTOR_TYPENAME_uint1   uvec1
#define GLM_VECTOR_TYPENAME_uint2   uvec2
#define GLM_VECTOR_TYPENAME_uint3   uvec3
#define GLM_VECTOR_TYPENAME_uint4   uvec4
*/
#define GLM_VECTOR_TYPENAME_(L, T, Q) T ## L
#define GLM_VECTOR_TYPENAME(...) GLM_VECTOR_TYPENAME_(__VA_ARGS__)
#define GLM_VECTOR_CONSTRUCTOR_NAME(L, T, Q) GLM_CALL_FUNC(constructor, GLM_VECTOR_TYPENAME(L, T, Q))

#define glm_vec(L, T, Q) GLM_PREFIX(GLM_VECTOR_TYPENAME(L, T, Q))

/*
#define GLM_MATRIX_TYPENAME_float2x2_defaultp mat2x2
#define GLM_MATRIX_TYPENAME_float2x3_defaultp mat2x3
#define GLM_MATRIX_TYPENAME_float2x4_defaultp mat2x4
#define GLM_MATRIX_TYPENAME_float3x2_defaultp mat3x2
#define GLM_MATRIX_TYPENAME_float3x3_defaultp mat3x3
#define GLM_MATRIX_TYPENAME_float3x4_defaultp mat3x4
#define GLM_MATRIX_TYPENAME_float4x2_defaultp mat4x2
#define GLM_MATRIX_TYPENAME_float4x3_defaultp mat4x3
#define GLM_MATRIX_TYPENAME_float4x4_defaultp mat4x4

#define GLM_MATRIX_TYPENAME_double2x2_defaultp dmat2x2
#define GLM_MATRIX_TYPENAME_double2x3_defaultp dmat2x3
#define GLM_MATRIX_TYPENAME_double2x4_defaultp dmat2x4
#define GLM_MATRIX_TYPENAME_double3x2_defaultp dmat3x2
#define GLM_MATRIX_TYPENAME_double3x3_defaultp dmat3x3
#define GLM_MATRIX_TYPENAME_double3x4_defaultp dmat3x4
#define GLM_MATRIX_TYPENAME_double4x2_defaultp dmat4x2
#define GLM_MATRIX_TYPENAME_double4x3_defaultp dmat4x3
#define GLM_MATRIX_TYPENAME_double4x4_defaultp dmat4x4
*/

#define GLM_MATRIX_TYPENAME_(C, R, T, Q) T ## R ## x ## C
#define GLM_MATRIX_TYPENAME(...) GLM_MATRIX_TYPENAME_(__VA_ARGS__)
#define GLM_MATRIX_CONSTRUCTOR_NAME(C, R, T, Q) GLM_CALL_FUNC(constructor, GLM_MATRIX_TYPENAME(C, R, T, Q))

/*
 C: Left-hand  length_t (constexpr)
 R: Right hand length_t (constexpr)
 T: typename (type)
 Q: qualifier (constexpr)
*/
#define glm_mat(C, R, T, Q) GLM_PREFIX(GLM_MATRIX_TYPENAME(C, R, T, Q))

typedef enum glm_qualifier
{
    lowp,
    mediump,
    highp,
    defaultp
} glm_qualifier;
/*
typedef enum glm_qualifier
{
 GLM_QUALIFIER_LOWP,
 GLM_QUALIFIER_MEDIUMP,
 GLM_QUALIFIER_HIGHP,
 GLM_QUALIFIER_DEFAULTP = GLM_QUALIFIER_HIGHP
} glm_qualifier_t;*/


/* Enums of all glm typenames */
#define GLM_TYPE_BOOL      0
#define GLM_TYPE_FLOAT     1
#define GLM_TYPE_DOUBLE    2
#define GLM_TYPE_INT       3
#define GLM_TYPE_UINT      4
#define GLM_TYPE_BOOL1     5
#define GLM_TYPE_BOOL2     6
#define GLM_TYPE_BOOL3     7
#define GLM_TYPE_BOOL4     8
#define GLM_TYPE_FLOAT1    9
#define GLM_TYPE_FLOAT2    10
#define GLM_TYPE_FLOAT3    11
#define GLM_TYPE_FLOAT4    12
#define GLM_TYPE_DOUBLE1   13
#define GLM_TYPE_DOUBLE2   14
#define GLM_TYPE_DOUBLE3   15
#define GLM_TYPE_DOUBLE4   16
#define GLM_TYPE_INT1      17
#define GLM_TYPE_INT2      18
#define GLM_TYPE_INT3      19
#define GLM_TYPE_INT4      20
#define GLM_TYPE_UINT1     21
#define GLM_TYPE_UINT2     22
#define GLM_TYPE_UINT3     23
#define GLM_TYPE_UINT4     24
#define GLM_TYPE_FLOAT2X2  25
#define GLM_TYPE_FLOAT2X3  26
#define GLM_TYPE_FLOAT2X4  27
#define GLM_TYPE_FLOAT3X2  28
#define GLM_TYPE_FLOAT3X3  29
#define GLM_TYPE_FLOAT3X4  30
#define GLM_TYPE_FLOAT4X2  31
#define GLM_TYPE_FLOAT4X3  32
#define GLM_TYPE_FLOAT4X4  33
#define GLM_TYPE_DOUBLE2X2 34
#define GLM_TYPE_DOUBLE2X3 35
#define GLM_TYPE_DOUBLE2X4 36
#define GLM_TYPE_DOUBLE3X2 37
#define GLM_TYPE_DOUBLE3X3 38
#define GLM_TYPE_DOUBLE3X4 39
#define GLM_TYPE_DOUBLE4X2 40
#define GLM_TYPE_DOUBLE4X3 41
#define GLM_TYPE_DOUBLE4X4 42

#define GLM_TYPE_BOOL_BIT      0x0000000000000001ULL
#define GLM_TYPE_FLOAT_BIT     0x0000000000000002ULL
#define GLM_TYPE_DOUBLE_BIT    0x0000000000000004ULL
#define GLM_TYPE_INT_BIT       0x0000000000000008ULL
#define GLM_TYPE_UINT_BIT      0x0000000000000010ULL
#define GLM_TYPE_BOOL1_BIT     0x0000000000000020ULL
#define GLM_TYPE_BOOL2_BIT     0x0000000000000040ULL
#define GLM_TYPE_BOOL3_BIT     0x0000000000000080ULL
#define GLM_TYPE_BOOL4_BIT     0x0000000000000100ULL
#define GLM_TYPE_FLOAT1_BIT    0x0000000000000200ULL
#define GLM_TYPE_FLOAT2_BIT    0x0000000000000400ULL
#define GLM_TYPE_FLOAT3_BIT    0x0000000000000800ULL
#define GLM_TYPE_FLOAT4_BIT    0x0000000000001000ULL
#define GLM_TYPE_DOUBLE1_BIT   0x0000000000002000ULL
#define GLM_TYPE_DOUBLE2_BIT   0x0000000000004000ULL
#define GLM_TYPE_DOUBLE3_BIT   0x0000000000008000ULL
#define GLM_TYPE_DOUBLE4_BIT   0x0000000000010000ULL
#define GLM_TYPE_INT1_BIT      0x0000000000020000ULL
#define GLM_TYPE_INT2_BIT      0x0000000000040000ULL
#define GLM_TYPE_INT3_BIT      0x0000000000080000ULL
#define GLM_TYPE_INT4_BIT      0x0000000000100000ULL
#define GLM_TYPE_UINT1_BIT     0x0000000000200000ULL
#define GLM_TYPE_UINT2_BIT     0x0000000000400000ULL
#define GLM_TYPE_UINT3_BIT     0x0000000000800000ULL
#define GLM_TYPE_UINT4_BIT     0x0000000001000000ULL
#define GLM_TYPE_FLOAT2X2_BIT  0x0000000002000000ULL
#define GLM_TYPE_FLOAT2X3_BIT  0x0000000004000000ULL
#define GLM_TYPE_FLOAT2X4_BIT  0x0000000008000000ULL
#define GLM_TYPE_FLOAT3X2_BIT  0x0000000010000000ULL
#define GLM_TYPE_FLOAT3X3_BIT  0x0000000020000000ULL
#define GLM_TYPE_FLOAT3X4_BIT  0x0000000040000000ULL
#define GLM_TYPE_FLOAT4X2_BIT  0x0000000080000000ULL
#define GLM_TYPE_FLOAT4X3_BIT  0x0000000100000000ULL
#define GLM_TYPE_FLOAT4X4_BIT  0x0000000200000000ULL
#define GLM_TYPE_DOUBLE2X2_BIT 0x0000000400000000ULL
#define GLM_TYPE_DOUBLE2X3_BIT 0x0000000800000000ULL
#define GLM_TYPE_DOUBLE2X4_BIT 0x0000001000000000ULL
#define GLM_TYPE_DOUBLE3X2_BIT 0x0000002000000000ULL
#define GLM_TYPE_DOUBLE3X3_BIT 0x0000004000000000ULL
#define GLM_TYPE_DOUBLE3X4_BIT 0x0000008000000000ULL
#define GLM_TYPE_DOUBLE4X2_BIT 0x0000010000000000ULL
#define GLM_TYPE_DOUBLE4X3_BIT 0x0000020000000000ULL
#define GLM_TYPE_DOUBLE4X4_BIT 0x0000040000000000ULL

#define GLM_MASK_SCALAR (GLM_TYPE_BOOL_BIT | GLM_TYPE_FLOAT_BIT | GLM_TYPE_DOUBLE_BIT | GLM_TYPE_INT_BIT | GLM_TYPE_UINT_BIT)

#define GLM_MASK_VECTOR (GLM_TYPE_BOOL1_BIT | GLM_TYPE_BOOL2_BIT | GLM_TYPE_BOOL3_BIT | GLM_TYPE_BOOL4_BIT\
  | GLM_TYPE_FLOAT1_BIT | GLM_TYPE_FLOAT2_BIT | GLM_TYPE_FLOAT3_BIT | GLM_TYPE_FLOAT4_BIT\
  | GLM_TYPE_DOUBLE1_BIT | GLM_TYPE_DOUBLE2_BIT | GLM_TYPE_DOUBLE3_BIT | GLM_TYPE_DOUBLE4_BIT\
  | GLM_TYPE_INT1_BIT | GLM_TYPE_INT2_BIT | GLM_TYPE_INT3_BIT | GLM_TYPE_INT4_BIT\
  | GLM_TYPE_UINT1_BIT | GLM_TYPE_UINT2_BIT | GLM_TYPE_UINT3_BIT | GLM_TYPE_UINT4_BIT)

#define GLM_MASK_MATRIX (GLM_TYPE_FLOAT2X2_BIT | GLM_TYPE_FLOAT2X3_BIT | GLM_TYPE_FLOAT2X4_BIT\
  | GLM_TYPE_FLOAT3X2_BIT | GLM_TYPE_FLOAT3X3_BIT | GLM_TYPE_FLOAT3X4_BIT\
  | GLM_TYPE_FLOAT4X2_BIT | GLM_TYPE_FLOAT4X3_BIT | GLM_TYPE_FLOAT4X4_BIT\
  | GLM_TYPE_DOUBLE2X2_BIT | GLM_TYPE_DOUBLE2X3_BIT | GLM_TYPE_DOUBLE2X4_BIT\
  | GLM_TYPE_DOUBLE3X2_BIT | GLM_TYPE_DOUBLE3X3_BIT | GLM_TYPE_DOUBLE3X4_BIT\
  | GLM_TYPE_DOUBLE4X2_BIT | GLM_TYPE_DOUBLE4X3_BIT | GLM_TYPE_DOUBLE4X4_BIT)

#define GLM_STATIC_ASSERT(expr, message) _Static_assert(expr, message)
#define GLM_ZERO_MEMORY(address, size) memset(address, 0, size)
#define GLM_ASSERT(expr, message) assert(expr && message)


#define GLM_TYPEOF_SCALAR_bool  GLM_TYPE_BOOL
#define GLM_TYPEOF_SCALAR_float  GLM_TYPE_FLOAT
#define GLM_TYPEOF_SCALAR_double GLM_TYPE_DOUBLE
#define GLM_TYPEOF_SCALAR_int  GLM_TYPE_INT
#define GLM_TYPEOF_SCALAR_uint  GLM_TYPE_UINT

#define GLM_TYPEOF_SCALAR_(T) GLM_TYPEOF_SCALAR_ ## T
#define GLM_TYPEOF_SCALAR(...) GLM_TYPEOF_SCALAR_(__VA_ARGS__)

#define GLM_TYPEOF(x)\
_Generic((x),\
bool : GLM_TYPE_BOOL,\
float : GLM_TYPE_FLOAT,\
double : GLM_TYPE_DOUBLE,\
int : GLM_TYPE_INT,\
uint : GLM_TYPE_UINT,\
glm_vec(1, bool, defaultp): GLM_TYPE_BOOL1,\
glm_vec(2, bool, defaultp): GLM_TYPE_BOOL2,\
glm_vec(3, bool, defaultp): GLM_TYPE_BOOL3,\
glm_vec(4, bool, defaultp): GLM_TYPE_BOOL4,\
glm_vec(1, float, defaultp): GLM_TYPE_FLOAT1,\
glm_vec(2, float, defaultp): GLM_TYPE_FLOAT2,\
glm_vec(3, float, defaultp): GLM_TYPE_FLOAT3,\
glm_vec(4, float, defaultp): GLM_TYPE_FLOAT4,\
glm_vec(1, double, defaultp): GLM_TYPE_DOUBLE1,\
glm_vec(2, double, defaultp): GLM_TYPE_DOUBLE2,\
glm_vec(3, double, defaultp): GLM_TYPE_DOUBLE3,\
glm_vec(4, double, defaultp): GLM_TYPE_DOUBLE4,\
glm_vec(1, int, defaultp): GLM_TYPE_INT1,\
glm_vec(2, int, defaultp): GLM_TYPE_INT2,\
glm_vec(3, int, defaultp): GLM_TYPE_INT3,\
glm_vec(4, int, defaultp): GLM_TYPE_INT4,\
glm_vec(1, uint, defaultp): GLM_TYPE_UINT1,\
glm_vec(2, uint, defaultp): GLM_TYPE_UINT2,\
glm_vec(3, uint, defaultp): GLM_TYPE_UINT3,\
glm_vec(4, uint, defaultp): GLM_TYPE_UINT4,\
glm_mat(2, 2, float, defaultp): GLM_TYPE_FLOAT2X2,\
glm_mat(2, 3, float, defaultp): GLM_TYPE_FLOAT2X3,\
glm_mat(2, 4, float, defaultp): GLM_TYPE_FLOAT2X4,\
glm_mat(3, 2, float, defaultp): GLM_TYPE_FLOAT3X2,\
glm_mat(3, 3, float, defaultp): GLM_TYPE_FLOAT3X3,\
glm_mat(3, 4, float, defaultp): GLM_TYPE_FLOAT3X4,\
glm_mat(4, 2, float, defaultp): GLM_TYPE_FLOAT4X2,\
glm_mat(4, 3, float, defaultp): GLM_TYPE_FLOAT4X3,\
glm_mat(4, 4, float, defaultp): GLM_TYPE_FLOAT4X4,\
glm_mat(2, 2, double, defaultp): GLM_TYPE_DOUBLE2X2,\
glm_mat(2, 3, double, defaultp): GLM_TYPE_DOUBLE2X3,\
glm_mat(2, 4, double, defaultp): GLM_TYPE_DOUBLE2X4,\
glm_mat(3, 2, double, defaultp): GLM_TYPE_DOUBLE3X2,\
glm_mat(3, 3, double, defaultp): GLM_TYPE_DOUBLE3X3,\
glm_mat(3, 4, double, defaultp): GLM_TYPE_DOUBLE3X4,\
glm_mat(4, 2, double, defaultp): GLM_TYPE_DOUBLE4X2,\
glm_mat(4, 3, double, defaultp): GLM_TYPE_DOUBLE4X3,\
glm_mat(4, 4, double, defaultp): GLM_TYPE_DOUBLE4X4\
)

#endif /* GLM_DETAIL_SETUP_H */
