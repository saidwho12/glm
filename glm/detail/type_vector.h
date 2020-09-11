#ifndef GLM_DETAIL_TYPE_VECTOR_H
#define GLM_DETAIL_TYPE_VECTOR_H

#include "setup.h"
#include "type_scalar.h"

#include "namespace_begin.inl"
#include "namespace_template_vector_begin.inl"

#define GLM_SWIZZLE1_MEMBERS(T, Q, E0) struct { scalar(T, Q) E0; }

#define GLM_SWIZZLE2_MEMBERS(T, Q, E0, E1) struct { scalar(T, Q) E0, E1; }

#define GLM_SWIZZLE3_MEMBERS(T, Q, E0, E1, E2)\
union\
{\
	struct\
	{\
		scalar(T, Q) E0;\
		union\
		{\
			struct { scalar(T, Q) E1, E2; };\
			vec(2, T, Q) E1 ## E2;\
		};\
	};\
	vec(2, T, Q) E0 ## E1;\
}

#define GLM_SWIZZLE4_MEMBERS(T, Q, E0, E1, E2, E3)\
union\
{\
	struct\
	{\
		scalar(T, Q) E0;\
		union\
		{\
			struct { scalar(T, Q) E1, E2, E3; };\
			vec(3, T, Q) E1 ## E2 ## E3;\
			vec(2, T, Q) E1 ## E2;\
		};\
	};\
	struct { vec(2, T, Q) E0 ## E1, E2 ## E3; };\
	vec(3, T, Q) E0 ## E1 ## E2;\
}

#define GLM_SWIZZLE_VEC1_MEMBERS(T, Q, E0, ...) GLM_SWIZZLE1_MEMBERS(T, Q, E0)
#define GLM_SWIZZLE_VEC2_MEMBERS(T, Q, E0, E1, ...) GLM_SWIZZLE2_MEMBERS(T, Q, E0, E1)
#define GLM_SWIZZLE_VEC3_MEMBERS(T, Q, E0, E1, E2, ...) GLM_SWIZZLE3_MEMBERS(T, Q, E0, E1, E2)
#define GLM_SWIZZLE_VEC4_MEMBERS(T, Q, E0, E1, E2, E3, ...) GLM_SWIZZLE4_MEMBERS(T, Q, E0, E1, E2, E3)

#define GLM_SWIZZLE_MEMBERS_(L, T, Q)\
union {\
GLM_SWIZZLE_VEC ## L ## _MEMBERS(T, Q, x, y, z, w);\
GLM_SWIZZLE_VEC ## L ## _MEMBERS(T, Q, r, g, b, a);\
GLM_SWIZZLE_VEC ## L ## _MEMBERS(T, Q, s, t, p, q);\
}

#define GLM_SWIZZLE_MEMBERS(...) GLM_SWIZZLE_MEMBERS_(__VA_ARGS__)

/* Align arrays to 1-byte boundaries */
#define GLM_VECTOR_DATA(L, T, Q)\
T elem[L];\
struct { uint8_t _u8[0];\
uint16_t _u16[0];\
uint32_t _u32[0];\
uint64_t _u64[0];\
int8_t _i8[0];\
int16_t _i16[0];\
int32_t _i32[0];\
int64_t _i64[0];\
float _f32[0];\
double _f64[0]; } __attribute__ ((__packed__))

#define L 1
#define T bool
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 2
#define T bool
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 3
#define T bool
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 4
#define T bool
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 1
#define T float
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 2
#define T float
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 3
#define T float
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 4
#define T float
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 1
#define T double
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 2
#define T double
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 3
#define T double
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 4
#define T double
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 1
#define T int
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 2
#define T int
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 3
#define T int
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 4
#define T int
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 1
#define T uint
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 2
#define T uint
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 3
#define T uint
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

#define L 4
#define T uint
#define Q defaultp
#include "type_vector_decl.inl"
#undef L
#undef T
#undef Q

typedef vec(1, bool, defaultp) glm_bvec1;
typedef vec(2, bool, defaultp) glm_bvec2;
typedef vec(3, bool, defaultp) glm_bvec3;
typedef vec(4, bool, defaultp) glm_bvec4;

typedef vec(1, float, defaultp) glm_vec1;
typedef vec(2, float, defaultp) glm_vec2;
typedef vec(3, float, defaultp) glm_vec3;
typedef vec(4, float, defaultp) glm_vec4;

typedef vec(1, double, defaultp) glm_dvec1;
typedef vec(2, double, defaultp) glm_dvec2;
typedef vec(3, double, defaultp) glm_dvec3;
typedef vec(4, double, defaultp) glm_dvec4;

typedef vec(1, int, defaultp) glm_ivec1;
typedef vec(2, int, defaultp) glm_ivec2;
typedef vec(3, int, defaultp) glm_ivec3;
typedef vec(4, int, defaultp) glm_ivec4;

typedef vec(1, uint, defaultp) glm_uvec1;
typedef vec(2, uint, defaultp) glm_uvec2;
typedef vec(3, uint, defaultp) glm_uvec3;
typedef vec(4, uint, defaultp) glm_uvec4;

#define glm_normalize(x) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(normalize, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(normalize, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(normalize, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(normalize, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(normalize, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(normalize, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(normalize, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(normalize, GLM_VECTOR_TYPENAME(4, double, defaultp))\
)((x))

#define glm_length(x) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(length, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(length, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(length, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(length, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(length, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(length, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(length, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(length, GLM_VECTOR_TYPENAME(4, double, defaultp))\
)((x))

#define glm_dot(x, y) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(dot, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(dot, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(dot, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(dot, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(dot, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(dot, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(dot, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(dot, GLM_VECTOR_TYPENAME(4, double, defaultp))\
)(x, y)

#define glm_lessThan(x, y) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(4, double, defaultp)),\
glm_vec(1, int, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(1, int, defaultp)),\
glm_vec(2, int, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(2, int, defaultp)),\
glm_vec(3, int, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(3, int, defaultp)),\
glm_vec(4, int, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(4, int, defaultp)),\
glm_vec(1, uint, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(1, uint, defaultp)),\
glm_vec(2, uint, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(2, uint, defaultp)),\
glm_vec(3, uint, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(3, uint, defaultp)),\
glm_vec(4, uint, defaultp): GLM_CALL_FUNC(lessThan, GLM_VECTOR_TYPENAME(4, uint, defaultp))\
)(x, y)

#define glm_greaterThan(x, y) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(4, double, defaultp)),\
glm_vec(1, int, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(1, int, defaultp)),\
glm_vec(2, int, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(2, int, defaultp)),\
glm_vec(3, int, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(3, int, defaultp)),\
glm_vec(4, int, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(4, int, defaultp)),\
glm_vec(1, uint, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(1, uint, defaultp)),\
glm_vec(2, uint, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(2, uint, defaultp)),\
glm_vec(3, uint, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(3, uint, defaultp)),\
glm_vec(4, uint, defaultp): GLM_CALL_FUNC(greaterThan, GLM_VECTOR_TYPENAME(4, uint, defaultp))\
)(x, y)

#define glm_lessThanEqual(x, y) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(4, double, defaultp)),\
glm_vec(1, int, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(1, int, defaultp)),\
glm_vec(2, int, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(2, int, defaultp)),\
glm_vec(3, int, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(3, int, defaultp)),\
glm_vec(4, int, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(4, int, defaultp)),\
glm_vec(1, uint, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(1, uint, defaultp)),\
glm_vec(2, uint, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(2, uint, defaultp)),\
glm_vec(3, uint, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(3, uint, defaultp)),\
glm_vec(4, uint, defaultp): GLM_CALL_FUNC(lessThanEqual, GLM_VECTOR_TYPENAME(4, uint, defaultp))\
)(x, y)

#define glm_greaterThanEqual(x, y) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(4, double, defaultp)),\
glm_vec(1, int, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(1, int, defaultp)),\
glm_vec(2, int, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(2, int, defaultp)),\
glm_vec(3, int, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(3, int, defaultp)),\
glm_vec(4, int, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(4, int, defaultp)),\
glm_vec(1, uint, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(1, uint, defaultp)),\
glm_vec(2, uint, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(2, uint, defaultp)),\
glm_vec(3, uint, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(3, uint, defaultp)),\
glm_vec(4, uint, defaultp): GLM_CALL_FUNC(greaterThanEqual, GLM_VECTOR_TYPENAME(4, uint, defaultp))\
)(x, y)

#define glm_equal(x, y) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(4, double, defaultp)),\
glm_vec(1, int, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(1, int, defaultp)),\
glm_vec(2, int, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(2, int, defaultp)),\
glm_vec(3, int, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(3, int, defaultp)),\
glm_vec(4, int, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(4, int, defaultp)),\
glm_vec(1, uint, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(1, uint, defaultp)),\
glm_vec(2, uint, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(2, uint, defaultp)),\
glm_vec(3, uint, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(3, uint, defaultp)),\
glm_vec(4, uint, defaultp): GLM_CALL_FUNC(equal, GLM_VECTOR_TYPENAME(4, uint, defaultp))\
)(x, y)

#define glm_notEqual(x, y) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(4, double, defaultp)),\
glm_vec(1, int, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(1, int, defaultp)),\
glm_vec(2, int, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(2, int, defaultp)),\
glm_vec(3, int, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(3, int, defaultp)),\
glm_vec(4, int, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(4, int, defaultp)),\
glm_vec(1, uint, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(1, uint, defaultp)),\
glm_vec(2, uint, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(2, uint, defaultp)),\
glm_vec(3, uint, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(3, uint, defaultp)),\
glm_vec(4, uint, defaultp): GLM_CALL_FUNC(notEqual, GLM_VECTOR_TYPENAME(4, uint, defaultp))\
)(x, y)

#define glm_or(x, y) _Generic(x,\
glm_vec(1, bool, defaultp): GLM_CALL_FUNC(or, GLM_VECTOR_TYPENAME(1, bool, defaultp)),\
glm_vec(2, bool, defaultp): GLM_CALL_FUNC(or, GLM_VECTOR_TYPENAME(2, bool, defaultp)),\
glm_vec(3, bool, defaultp): GLM_CALL_FUNC(or, GLM_VECTOR_TYPENAME(3, bool, defaultp)),\
glm_vec(4, bool, defaultp): GLM_CALL_FUNC(or, GLM_VECTOR_TYPENAME(4, bool, defaultp))\
)(x, y)

#define glm_and(x, y) _Generic(x,\
glm_vec(1, bool, defaultp): GLM_CALL_FUNC(and, GLM_VECTOR_TYPENAME(1, bool, defaultp)),\
glm_vec(2, bool, defaultp): GLM_CALL_FUNC(and, GLM_VECTOR_TYPENAME(2, bool, defaultp)),\
glm_vec(3, bool, defaultp): GLM_CALL_FUNC(and, GLM_VECTOR_TYPENAME(3, bool, defaultp)),\
glm_vec(4, bool, defaultp): GLM_CALL_FUNC(and, GLM_VECTOR_TYPENAME(4, bool, defaultp))\
)(x, y)

#define glm_xor(x, y) _Generic(x,\
glm_vec(1, bool, defaultp): GLM_CALL_FUNC(xor, GLM_VECTOR_TYPENAME(1, bool, defaultp)),\
glm_vec(2, bool, defaultp): GLM_CALL_FUNC(xor, GLM_VECTOR_TYPENAME(2, bool, defaultp)),\
glm_vec(3, bool, defaultp): GLM_CALL_FUNC(xor, GLM_VECTOR_TYPENAME(3, bool, defaultp)),\
glm_vec(4, bool, defaultp): GLM_CALL_FUNC(xor, GLM_VECTOR_TYPENAME(4, bool, defaultp))\
)(x, y)

#define glm_all(x) _Generic(x,\
glm_vec(1, bool, defaultp): GLM_CALL_FUNC(all, GLM_VECTOR_TYPENAME(1, bool, defaultp)),\
glm_vec(2, bool, defaultp): GLM_CALL_FUNC(all, GLM_VECTOR_TYPENAME(2, bool, defaultp)),\
glm_vec(3, bool, defaultp): GLM_CALL_FUNC(all, GLM_VECTOR_TYPENAME(3, bool, defaultp)),\
glm_vec(4, bool, defaultp): GLM_CALL_FUNC(all, GLM_VECTOR_TYPENAME(4, bool, defaultp))\
)(x)

#define glm_any(x) _Generic(x,\
glm_vec(1, bool, defaultp): GLM_CALL_FUNC(any, GLM_VECTOR_TYPENAME(1, bool, defaultp)),\
glm_vec(2, bool, defaultp): GLM_CALL_FUNC(any, GLM_VECTOR_TYPENAME(2, bool, defaultp)),\
glm_vec(3, bool, defaultp): GLM_CALL_FUNC(any, GLM_VECTOR_TYPENAME(3, bool, defaultp)),\
glm_vec(4, bool, defaultp): GLM_CALL_FUNC(any, GLM_VECTOR_TYPENAME(4, bool, defaultp))\
)(x)

#define glm_not(x) _Generic(x,\
glm_vec(1, bool, defaultp): GLM_CALL_FUNC(not, GLM_VECTOR_TYPENAME(1, bool, defaultp)),\
glm_vec(2, bool, defaultp): GLM_CALL_FUNC(not, GLM_VECTOR_TYPENAME(2, bool, defaultp)),\
glm_vec(3, bool, defaultp): GLM_CALL_FUNC(not, GLM_VECTOR_TYPENAME(3, bool, defaultp)),\
glm_vec(4, bool, defaultp): GLM_CALL_FUNC(not, GLM_VECTOR_TYPENAME(4, bool, defaultp))\
)(x)

#define glm_cross(x, y) _Generic(x,\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(cross, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(cross, GLM_VECTOR_TYPENAME(3, double, defaultp))\
)(x,y)


#define glm_clamps(x, minVal, maxVal) _Generic(x,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(clamps, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(clamps, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(clamps, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(clamps, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(clamps, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(clamps, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(clamps, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(clamps, GLM_VECTOR_TYPENAME(4, double, defaultp))\
)(x, minVal, maxVal)

#define glm_reflect(N, I) _Generic(N,\
glm_vec(1, float, defaultp): GLM_CALL_FUNC(reflect, GLM_VECTOR_TYPENAME(1, float, defaultp)),\
glm_vec(2, float, defaultp): GLM_CALL_FUNC(reflect, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
glm_vec(3, float, defaultp): GLM_CALL_FUNC(reflect, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
glm_vec(4, float, defaultp): GLM_CALL_FUNC(reflect, GLM_VECTOR_TYPENAME(4, float, defaultp)),\
glm_vec(1, double, defaultp): GLM_CALL_FUNC(reflect, GLM_VECTOR_TYPENAME(1, double, defaultp)),\
glm_vec(2, double, defaultp): GLM_CALL_FUNC(reflect, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
glm_vec(3, double, defaultp): GLM_CALL_FUNC(reflect, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
glm_vec(4, double, defaultp): GLM_CALL_FUNC(reflect, GLM_VECTOR_TYPENAME(4, double, defaultp))\
)(N, I)

#include "namespace_template_vector_end.inl"
#include "namespace_end.inl"

#endif /* GLM_DETAIL_TYPE_VECTOR_H */