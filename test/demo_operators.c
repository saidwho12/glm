#include <stdlib.h>
#include <glm/glm.h>
#include <glm/gtx/print.h>
/*
static void glm_addeq_generic(glm_type_t lhs_type, void *lhs,
                              glm_type_t rhs_type, const void *rhs)
{
	if (lhs_type == rhs_type)
	{
		glm_type_t type = lhs_type;
		switch (type)
		{
			case GLM_TYPE_FLOAT1: break;
			case GLM_TYPE_FLOAT2: break;
			case GLM_TYPE_FLOAT1: break;
			case GLM_TYPE_FLOAT1: break;
			case GLM_TYPE_FLOAT1: break;
			case GLM_TYPE_FLOAT1: break;
		}
	}
}
*/
#define GLM_GENERIC_BINARY_OPERATOR(op, x, y)\
({\
	__builtin_choose_expr(\
		__builtin_types_compatible_p(__typeof__((x)), __typeof__((y))),\
			_Generic(x,\
			glm_vec(2,float,defaultp): GLM_CALL_FUNC(op, GLM_VECTOR_TYPENAME(2, float, defaultp)),\
			glm_vec(2,double,defaultp): GLM_CALL_FUNC(op, GLM_VECTOR_TYPENAME(2, double, defaultp)),\
			glm_vec(2,int,defaultp): GLM_CALL_FUNC(op, GLM_VECTOR_TYPENAME(2, int, defaultp)),\
			glm_vec(2,uint,defaultp): GLM_CALL_FUNC(op, GLM_VECTOR_TYPENAME(2, uint, defaultp)),\
			glm_vec(3,float,defaultp): GLM_CALL_FUNC(op, GLM_VECTOR_TYPENAME(3, float, defaultp)),\
			glm_vec(3,double,defaultp): GLM_CALL_FUNC(op, GLM_VECTOR_TYPENAME(3, double, defaultp)),\
			glm_vec(3,int,defaultp): GLM_CALL_FUNC(op, GLM_VECTOR_TYPENAME(3, int, defaultp)),\
			glm_vec(3,uint,defaultp): GLM_CALL_FUNC(op, GLM_VECTOR_TYPENAME(3, uint, defaultp))\
	)(x, y), "");\
})

#define glm_add(x, y) GLM_GENERIC_BINARY_OPERATOR(add, x, y)
#define glm_sub(x, y) GLM_GENERIC_BINARY_OPERATOR(sub, x, y)
#define glm_mul(x, y) GLM_GENERIC_BINARY_OPERATOR(mul, x, y)
#define glm_div(x, y) GLM_GENERIC_BINARY_OPERATOR(div, x, y)


typedef float f32;
typedef double f64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

void glm_addeq_base(uint8_t lhs_type, void *lhs, uint8_t rhs_type, const void *rhs)
{
	if (lhs_type == rhs_type)
	{
		switch (lhs_type)
		{
			case GLM_TYPE_BOOL1:
				glm_addeqv_bool1(lhs, *(glm_bool1 *)rhs);
				break;
			case GLM_TYPE_BOOL2:
				glm_addeqv_bool2(lhs, *(glm_bool2 *)rhs);
				break;
			case GLM_TYPE_BOOL3:
				glm_addeqv_bool3(lhs, *(glm_bool3 *)rhs);
				break;
			case GLM_TYPE_BOOL4:
				glm_addeqv_bool4(lhs, *(glm_bool4 *)rhs);
				break;
			case GLM_TYPE_DOUBLE1:
				glm_addeqv_double1(lhs, *(glm_double1 *)rhs);
				break;
			case GLM_TYPE_DOUBLE2:
				glm_addeqv_double2(lhs, *(glm_double2 *)rhs);
				break;
			case GLM_TYPE_DOUBLE3:
				glm_addeqv_double3(lhs, *(glm_double3 *)rhs);
				break;
			case GLM_TYPE_DOUBLE4:
				glm_addeqv_double4(lhs, *(glm_double4 *)rhs);
				break;
			case GLM_TYPE_INT1:
				glm_addeqv_int1(lhs, *(glm_int1 *)rhs);
				break;
			case GLM_TYPE_INT2:
				glm_addeqv_int2(lhs, *(glm_int2 *)rhs);
				break;
			case GLM_TYPE_INT3:
				glm_addeqv_int3(lhs, *(glm_int3 *)rhs);
				break;
			case GLM_TYPE_INT4:
				glm_addeqv_int4(lhs, *(glm_int4 *)rhs);
				break;
			case GLM_TYPE_UINT1:
				glm_addeqv_uint1(lhs, *(glm_uint1 *)rhs);
				break;
			case GLM_TYPE_UINT2:
				glm_addeqv_uint2(lhs, *(glm_uint2 *)rhs);
				break;
			case GLM_TYPE_UINT3:
				glm_addeqv_uint3(lhs, *(glm_uint3 *)rhs);
				break;
			case GLM_TYPE_UINT4:
				glm_addeqv_uint4(lhs, *(glm_uint4 *)rhs);
				break;
		}
	}
}

#define glm_addeq(lhs, rhs) { __typeof__((rhs)) tmp_rhs = rhs; glm_addeq_base(GLM_TYPEOF(lhs), &lhs, GLM_TYPEOF(rhs), &tmp_rhs); }

int main(int argc, char *argv[])
{
	glm_vec3 x = glm_vec3(0);
    
	x = glm_add(x, glm_add(glm_vec3(10,5,10), glm_vec3(15,55.25f,11)));
    
	glm_print("{vec3:0.2}\n", x);

	printf("%d\n", sizeof(x));

	glm_addeq(x, x)

	glm_print("{vec3:0.2}\n", x);

	u64 s = x._u64[0];

	{
		glm_int4 x = {12,42,64,8}, y = {8,4,8,4}, z = {2,2,2,2};
		x = glm_add_int4(x, y);
		glm_diveqv_int4(&x, z);
		glm_addeq(x, z);
	}

	printf("%llu\n", s);

	return EXIT_SUCCESS;
}