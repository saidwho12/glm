#ifndef GLM_DETAIL_QUALIFIER_H
#define GLM_DETAIL_QUALIFIER_H

#include "setup.h"
#include "type_scalar.h"
#include "type_vector.h"
#include "type_matrix.h"

typedef struct glm_type_info {
	unsigned int ID;
	uint64_t typeFlag;
	uint64_t elemType;
	size_t elemCol, elemRow;
	size_t elemCount; /* C * R for matrices, and L for vectors */
} glm_type_info_t;

GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
glmGetTypeInfo(glm_type_info_t *dstInfo, uint64_t const typeID)
{
	dstInfo->ID = typeID;
	dstInfo->typeFlag = 1ULL << typeID;

	switch (typeID)
	{
		case GLM_TYPE_FLOAT2X2:
			dstInfo->elemType = GLM_TYPE_FLOAT;
			dstInfo->elemCol = 2;
			dstInfo->elemRow = 2;
			dstInfo->elemCount = 4;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT2X3:
			dstInfo->elemType = GLM_TYPE_FLOAT;
			dstInfo->elemCol = 2;
			dstInfo->elemRow = 3;
			dstInfo->elemCount = 6;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT2X4:
			dstInfo->elemType = GLM_TYPE_FLOAT;
			dstInfo->elemCol = 2;
			dstInfo->elemRow = 4;
			dstInfo->elemCount = 8;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT3X2:
			dstInfo->elemType = GLM_TYPE_FLOAT;
			dstInfo->elemCol = 3;
			dstInfo->elemRow = 2;
			dstInfo->elemCount = 6;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT3X3:
			dstInfo->elemType = GLM_TYPE_FLOAT3X3;
			dstInfo->elemCol = 3;
			dstInfo->elemRow = 3;
			dstInfo->elemCount = 9;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT3X4:
			dstInfo->elemType = GLM_TYPE_FLOAT;
			dstInfo->elemCol = 3;
			dstInfo->elemRow = 4;
			dstInfo->elemCount = 12;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT4X2:
			dstInfo->elemType = GLM_TYPE_FLOAT;
			dstInfo->elemCol = 4;
			dstInfo->elemRow = 2;
			dstInfo->elemCount = 8;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT4X3:
			dstInfo->elemType = GLM_TYPE_FLOAT;
			dstInfo->elemCol = 4;
			dstInfo->elemRow = 3;
			dstInfo->elemCount = 12;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT4X4:
			dstInfo->elemType = GLM_TYPE_FLOAT;
			dstInfo->elemCol = 4;
			dstInfo->elemRow = 4;
			dstInfo->elemCount = 16;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_DOUBLE2X2:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 2;
			dstInfo->elemRow = 2;
			dstInfo->elemCount = 4;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE2X3:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 2;
			dstInfo->elemRow = 3;
			dstInfo->elemCount = 6;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE2X4:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 2;
			dstInfo->elemRow = 4;
			dstInfo->elemCount = 8;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE3X2:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 3;
			dstInfo->elemRow = 2;
			dstInfo->elemCount = 6;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE3X3:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 3;
			dstInfo->elemRow = 3;
			dstInfo->elemCount = 9;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE3X4:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 3;
			dstInfo->elemRow = 4;
			dstInfo->elemCount = 12;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE4X2:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 4;
			dstInfo->elemRow = 2;
			dstInfo->elemCount = 8;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE4X3:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 4;
			dstInfo->elemRow = 3;
			dstInfo->elemCount = 12;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE4X4:
			dstInfo->elemType = GLM_TYPE_DOUBLE;
			dstInfo->elemCol = 4;
			dstInfo->elemRow = 4;
			dstInfo->elemCount = 16;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_BOOL:
			dstInfo->elemType  = GLM_TYPE_BOOL;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(bool);
			break;
		case GLM_TYPE_BOOL1:
			dstInfo->elemType  = GLM_TYPE_BOOL;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(bool);
			break;
		case GLM_TYPE_BOOL2:
			dstInfo->elemType  = GLM_TYPE_BOOL;
			dstInfo->elemCount = 2;
			//dstInfo->elemSize = sizeof(bool);
			break;
		case GLM_TYPE_BOOL3:
			dstInfo->elemType  = GLM_TYPE_BOOL;
			dstInfo->elemCount = 3;
			//dstInfo->elemSize = sizeof(bool);
			break;
		case GLM_TYPE_BOOL4:
			dstInfo->elemType  = GLM_TYPE_BOOL;
			dstInfo->elemCount = 4;
			//dstInfo->elemSize = sizeof(bool);
			break;
		case GLM_TYPE_FLOAT:
			dstInfo->elemType  = GLM_TYPE_FLOAT;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT1:
			dstInfo->elemType  = GLM_TYPE_FLOAT;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT2:
			dstInfo->elemType  = GLM_TYPE_FLOAT;
			dstInfo->elemCount = 2;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT3:
			dstInfo->elemType  = GLM_TYPE_FLOAT;
			dstInfo->elemCount = 3;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_FLOAT4:
			dstInfo->elemType  = GLM_TYPE_FLOAT;
			dstInfo->elemCount = 4;
			//dstInfo->elemSize = sizeof(float);
			break;
		case GLM_TYPE_DOUBLE:
			dstInfo->elemType  = GLM_TYPE_DOUBLE;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE1:
			dstInfo->elemType  = GLM_TYPE_DOUBLE;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE2:
			dstInfo->elemType  = GLM_TYPE_DOUBLE;
			dstInfo->elemCount = 2;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE3:
			dstInfo->elemType  = GLM_TYPE_DOUBLE;
			dstInfo->elemCount = 3;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_DOUBLE4:
			dstInfo->elemType  = GLM_TYPE_DOUBLE;
			dstInfo->elemCount = 4;
			//dstInfo->elemSize = sizeof(double);
			break;
		case GLM_TYPE_INT:
			dstInfo->elemType  = GLM_TYPE_INT;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(int);
			break;
		case GLM_TYPE_INT1:
			dstInfo->elemType  = GLM_TYPE_INT;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(int);
			break;
		case GLM_TYPE_INT2:
			dstInfo->elemType  = GLM_TYPE_INT;
			dstInfo->elemCount = 2;
			//dstInfo->elemSize = sizeof(int);
			break;
		case GLM_TYPE_INT3:
			dstInfo->elemType  = GLM_TYPE_INT;
			dstInfo->elemCount = 3;
			//dstInfo->elemSize = sizeof(int);
			break;
		case GLM_TYPE_INT4:
			dstInfo->elemType  = GLM_TYPE_INT;
			dstInfo->elemCount = 4;
			//dstInfo->elemSize = sizeof(int);
			break;
		case GLM_TYPE_UINT:
			dstInfo->elemType  = GLM_TYPE_UINT;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(unsigned int);
			break;
		case GLM_TYPE_UINT1:
			dstInfo->elemType  = GLM_TYPE_UINT;
			dstInfo->elemCount = 1;
			//dstInfo->elemSize = sizeof(unsigned int);
			break;
		case GLM_TYPE_UINT2:
			dstInfo->elemType  = GLM_TYPE_UINT;
			dstInfo->elemCount = 2;
			//dstInfo->elemSize = sizeof(unsigned int);
			break;
		case GLM_TYPE_UINT3:
			dstInfo->elemType  = GLM_TYPE_UINT;
			dstInfo->elemCount = 3;
			//dstInfo->elemSize = sizeof(unsigned int);
			break;
		case GLM_TYPE_UINT4:
			dstInfo->elemType  = GLM_TYPE_UINT;
			dstInfo->elemCount = 4;
			//dstInfo->elemSize = sizeof(unsigned int);
			break;
		default:
			break;
	}
}

/* Same as glm_cast_array(), but with limited WriteSize */
GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
glmLimitedCvt(size_t const writeElemCount, void *dstAddr, uint64_t const dstElemType, void const* srcAddr, uint64_t const srcElemType)
{
	size_t elemIdx;

	//printf("%d\n", writeElemCount);

	for (elemIdx = 0; elemIdx < writeElemCount; ++elemIdx)
	{
		switch (dstElemType)
		{
			case GLM_TYPE_BOOL:
				switch (srcElemType)
				{
					case GLM_TYPE_BOOL:   *((bool *)dstAddr + elemIdx) = *((const bool *)srcAddr + elemIdx); break;
					case GLM_TYPE_FLOAT:  *((bool *)dstAddr + elemIdx) = *((const float *)srcAddr + elemIdx); break;
					case GLM_TYPE_DOUBLE: *((bool *)dstAddr + elemIdx) = *((const double *)srcAddr + elemIdx); break;
					case GLM_TYPE_INT:    *((bool *)dstAddr + elemIdx) = *((const int *)srcAddr + elemIdx); break;
					case GLM_TYPE_UINT:   *((bool *)dstAddr + elemIdx) = *((const unsigned int *)srcAddr + elemIdx); break;
				}
				break;

			case GLM_TYPE_FLOAT:
				switch (srcElemType)
				{
					case GLM_TYPE_BOOL:   *((float *)dstAddr + elemIdx) = *((const bool *)srcAddr + elemIdx); break;
					case GLM_TYPE_FLOAT:  *((float *)dstAddr + elemIdx) = *((const float *)srcAddr + elemIdx); break;
					case GLM_TYPE_DOUBLE: *((float *)dstAddr + elemIdx) = *((const double *)srcAddr + elemIdx); break;
					case GLM_TYPE_INT:    *((float *)dstAddr + elemIdx) = *((const int *)srcAddr + elemIdx); break;
					case GLM_TYPE_UINT:   *((float *)dstAddr + elemIdx) = *((const unsigned int *)srcAddr + elemIdx); break;
				}
				break;

			case GLM_TYPE_DOUBLE:
				switch (srcElemType)
				{
					case GLM_TYPE_BOOL:   *((double *)dstAddr + elemIdx) = *((const bool *)srcAddr + elemIdx); break;
					case GLM_TYPE_FLOAT:  *((double *)dstAddr + elemIdx) = *((const float *)srcAddr + elemIdx); break;
					case GLM_TYPE_DOUBLE: *((double *)dstAddr + elemIdx) = *((const double *)srcAddr + elemIdx); break;
					case GLM_TYPE_INT:    *((double *)dstAddr + elemIdx) = *((const int *)srcAddr + elemIdx); break;
					case GLM_TYPE_UINT:   *((double *)dstAddr + elemIdx) = *((const unsigned int *)srcAddr + elemIdx); break;
				} 
				break;

			case GLM_TYPE_INT:
				switch (srcElemType)
				{
					case GLM_TYPE_BOOL:   *((int *)dstAddr + elemIdx) = *((const bool *)srcAddr + elemIdx); break;
					case GLM_TYPE_FLOAT:  *((int *)dstAddr + elemIdx) = *((const float *)srcAddr + elemIdx); break;
					case GLM_TYPE_DOUBLE: *((int *)dstAddr + elemIdx) = *((const double *)srcAddr + elemIdx); break;
					case GLM_TYPE_INT:    *((int *)dstAddr + elemIdx) = *((const int *)srcAddr + elemIdx); break;
					case GLM_TYPE_UINT:   *((int *)dstAddr + elemIdx) = *((const unsigned int *)srcAddr + elemIdx); break;
				}
				break;

			case GLM_TYPE_UINT:
				switch (srcElemType)
				{
					case GLM_TYPE_BOOL:   *((unsigned int *)dstAddr + elemIdx) = *((const bool *)srcAddr + elemIdx); break;
					case GLM_TYPE_FLOAT:  *((unsigned int *)dstAddr + elemIdx) = *((const float *)srcAddr + elemIdx); break;
					case GLM_TYPE_DOUBLE: *((unsigned int *)dstAddr + elemIdx) = *((const double *)srcAddr + elemIdx); break;
					case GLM_TYPE_INT:    *((unsigned int *)dstAddr + elemIdx) = *((const int *)srcAddr + elemIdx); break;
					case GLM_TYPE_UINT:   *((unsigned int *)dstAddr + elemIdx) = *((const unsigned int *)srcAddr + elemIdx); break;
				}
				break;
		}
	}
}

/* Parse and cast arguments for constructor */
GLM_FUNC_QUALIFIER GLM_CONSTEXPR size_t
glmReadAndConvertArg(uint64_t const dstElemType, void *dstAddr, size_t const writeElemLimit,
	glm_type_info_t const* argInfo, va_list *AP)
{
	uint8_t tmpMem[128];
	size_t writeElemCount = argInfo->elemCount <= writeElemLimit ?
		argInfo->elemCount : writeElemLimit;

	switch (argInfo->ID)
	{
		case GLM_TYPE_BOOL:
			*((bool *)tmpMem) = (bool)va_arg((*AP), int);
			break;
		case GLM_TYPE_FLOAT:
			*((float *)tmpMem) = (float)va_arg((*AP), double);
			break;
		case GLM_TYPE_DOUBLE:
			*((double *)tmpMem) = va_arg((*AP), double);
			break;
		case GLM_TYPE_INT:
			*((int *)tmpMem) = va_arg((*AP), int);
			break;
		case GLM_TYPE_UINT:
			*((unsigned int *)tmpMem) = va_arg((*AP), unsigned int);
			break;

		/* Bool types */
		case GLM_TYPE_BOOL1:
			*((glm_vec(1, bool, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(1, bool, defaultp));
			break;
		case GLM_TYPE_BOOL2:
			*((glm_vec(2, bool, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(2, bool, defaultp));
			break;
		case GLM_TYPE_BOOL3:
			*((glm_vec(3, bool, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(3, bool, defaultp));
			break;
		case GLM_TYPE_BOOL4:
			*((glm_vec(4, bool, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(4, bool, defaultp));
			break;

		/* Float types */
		case GLM_TYPE_FLOAT1:
			*((glm_vec(1, float, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(1, float, defaultp));
			break;
		case GLM_TYPE_FLOAT2:
			*((glm_vec(2, float, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(2, float, defaultp));
			break;
		case GLM_TYPE_FLOAT3:
			*((glm_vec(3, float, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(3, float, defaultp));
			break;
		case GLM_TYPE_FLOAT4:
			*((glm_vec(4, float, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(4, float, defaultp));
			break;

		/* Double types */
		case GLM_TYPE_DOUBLE1:
			*((glm_vec(1, double, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(1, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE2:
			*((glm_vec(2, double, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(2, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE3:
			*((glm_vec(3, double, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(3, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE4:
			*((glm_vec(4, double, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(4, double, defaultp));
			break;

		/* Integer types */
		case GLM_TYPE_INT1:
			*((glm_vec(1, int, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(1, int, defaultp));
			break;
		case GLM_TYPE_INT2:
			*((glm_vec(2, int, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(2, int, defaultp));
			break;
		case GLM_TYPE_INT3:
			*((glm_vec(3, int, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(3, int, defaultp));
			break;
		case GLM_TYPE_INT4:
			*((glm_vec(4, int, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(4, int, defaultp));
			break;

		/* Unsigned Integer types */
		case GLM_TYPE_UINT1:
			*((glm_vec(1, uint, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(1, uint, defaultp));
			break;
		case GLM_TYPE_UINT2:
			*((glm_vec(2, uint, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(2, uint, defaultp));
			break;
		case GLM_TYPE_UINT3:
			*((glm_vec(3, uint, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(3, uint, defaultp));
			break;
		case GLM_TYPE_UINT4:
			*((glm_vec(4, uint, defaultp) *)tmpMem) = va_arg((*AP), glm_vec(4, uint, defaultp));
			break;

		/* Matrix types */
		case GLM_TYPE_FLOAT2X2:
			*((glm_mat(2, 2, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(2, 2, float, defaultp));
			break;
		case GLM_TYPE_FLOAT2X3:
			*((glm_mat(2, 3, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(2, 3, float, defaultp));
			break;
		case GLM_TYPE_FLOAT2X4:
			*((glm_mat(2, 4, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(2, 4, float, defaultp));
			break;

		case GLM_TYPE_FLOAT3X2:
			*((glm_mat(3, 2, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(3, 2, float, defaultp));
			break;
		case GLM_TYPE_FLOAT3X3:
			*((glm_mat(3, 3, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(3, 3, float, defaultp));
			break;
		case GLM_TYPE_FLOAT3X4:
			*((glm_mat(3, 4, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(3, 4, float, defaultp));
			break;

		case GLM_TYPE_FLOAT4X2:
			*((glm_mat(4, 2, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(4, 2, float, defaultp));
			break;
		case GLM_TYPE_FLOAT4X3:
			*((glm_mat(4, 3, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(4, 3, float, defaultp));
			break;
		case GLM_TYPE_FLOAT4X4:
			*((glm_mat(4, 4, float, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(4, 4, float, defaultp));
			break;

		/* Double matrices */
		case GLM_TYPE_DOUBLE2X2:
			*((glm_mat(2, 2, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(2, 2, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE2X3:
			*((glm_mat(2, 3, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(2, 3, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE2X4:
			*((glm_mat(2, 4, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(2, 4, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE3X2:
			*((glm_mat(3, 2, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(3, 2, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE3X3:
			*((glm_mat(3, 3, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(3, 3, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE3X4:
			*((glm_mat(3, 4, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(3, 4, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE4X2:
			*((glm_mat(4, 2, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(4, 2, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE4X3:
			*((glm_mat(4, 3, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(4, 3, double, defaultp));
			break;
		case GLM_TYPE_DOUBLE4X4:
			*((glm_mat(4, 4, double, defaultp) *)tmpMem) = va_arg((*AP), glm_mat(4, 4, double, defaultp));
			break;

		default: break;
	}

	glmLimitedCvt(writeElemCount, dstAddr, dstElemType, (void const*)tmpMem, argInfo->elemType);
	return writeElemCount;
}


/*
 *  NOTE: Expects identity matrix passed as 'dstAddr'.
 *  The parameter passed in to 'params' must also be of a matrix type.
 * */
GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
glmMoveMatrixArg(void *dstAddr, uint64_t const dstElemType, glm_length_t const C, glm_length_t const R,
	glm_type_info_t const *paramInfo, va_list *params)
{
	/* Cast from matrix (third paragraph, sect. 5.4.2 [GLSL 4.60]) */
/*
	switch (paramInfo->typeFlag)
	{
		case GLM_TYPE_FLOAT2x2:
	}*/
}


#include "type_vector_impl.h"
#include "type_matrix_impl.h"

#endif /* GLM_DETAIL_QUALIFIER_H */
