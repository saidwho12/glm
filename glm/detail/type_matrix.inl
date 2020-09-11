/* Constructors & helper functions */

/* Generates and returns the identity matrix for an nxn square matrix  */
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat(C, R, T, Q)
identity(void)
{
	/*GLM_STATIC_ASSERT(C == R, "identity only for square matrices.");*/
	mat(C, R, T, Q) Result;
	GLM_ZERO_MEMORY(&Result, sizeof(Result));
	size_t loopIdx;
	static const size_t MINIMUM_DIM = C < R ? C : R;

	for (loopIdx = 0; loopIdx < MINIMUM_DIM; ++loopIdx)
		Result.elem[loopIdx][loopIdx] = (T)1;

	return Result;
}

/* Matrix Constructor (From section 5.4.2. Vector and Matrix Constructors of GLSL 4.60.7 specification) */
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat(C, R, T, Q)
constructor(length_t const argCount, ...)
{
	mat(C, R, T, Q) Result;
	va_list AP;
	
	uint64_t argType, argTypeFlag;
	glm_type_info_t argTypeInfo;
	static const size_t ELEMENT_COUNT = C * R;
	static const uint64_t DST_ELEM_TYPE = GLM_TYPEOF_SCALAR(T);

	GLM_ASSERT(argCount <= ELEMENT_COUNT, "Too many arguments for matrix constructor.");
	va_start(AP, argCount);

	/* Parse variadic arguments */
	if (argCount > 1) {
		length_t argIdx = 0;
		length_t elemIdx = 0;
		while (argIdx < argCount && elemIdx < ELEMENT_COUNT) {
			argType = va_arg(AP, uint64_t);

			glmGetTypeInfo(&argTypeInfo, argType);

			T *elemAddr = (T *) &Result + elemIdx;
			elemIdx += glmReadAndConvertArg(DST_ELEM_TYPE, elemAddr,
				ELEMENT_COUNT - elemIdx, &argTypeInfo, &AP);

			++argIdx;
		}
	} else {
		argType = va_arg(AP, uint64_t);
		argTypeFlag = 1ULL << argType;

		if (argTypeFlag & GLM_MASK_SCALAR) {
			/* Cast from scalar (second paragraph, sect. 5.4.2 [GLSL 4.60]) */
			scalar(T, defaultp) scalarValue;
			length_t loopIdx = 0;
			static const length_t MINIMUM_DIM = C < R ? C : R;
			GLM_ZERO_MEMORY(&Result, sizeof(Result));

			switch (argType) {
				case GLM_TYPE_BOOL: scalarValue = va_arg(AP, int); break;
				case GLM_TYPE_FLOAT: scalarValue = va_arg(AP, double); break;
				case GLM_TYPE_DOUBLE: scalarValue = va_arg(AP, double); break;
				case GLM_TYPE_INT: scalarValue = va_arg(AP, int); break;
				case GLM_TYPE_UINT: scalarValue = va_arg(AP, unsigned int); break;
			}

			while (loopIdx < MINIMUM_DIM) {
				Result.elem[loopIdx][loopIdx] = scalarValue;
				++loopIdx;
			}
		}
		else if (argTypeFlag & GLM_MASK_MATRIX) {
			/* Cast from matrix (third paragraph, sect. 5.4.2 [GLSL 4.60]) */
			Result = identity();
			glmGetTypeInfo(&argTypeInfo, argType);
			glmMoveMatrixArg((void *)&Result, C, R, DST_ELEM_TYPE, &argTypeInfo, &AP);
		} else {
			glmGetTypeInfo(&argTypeInfo, argType);
			glmReadAndConvertArg(DST_ELEM_TYPE, (void *)&Result, ELEMENT_COUNT, &argTypeInfo, &AP);
		}
	}

	va_end(AP);
	return Result;
}