/* Construct vectors from scalars, matrices, etc. */
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
constructor(length_t const argCount, ...)
{
	vec(L, T, Q) Result;

	va_list AP;

	unsigned int argType;
	uint64_t argTypeFlag;
	glm_type_info_t argTypeInfo;
	static const uint64_t DST_ELEM_TYPE = GLM_TYPEOF_SCALAR(T);

	GLM_ASSERT(argCount <= L, "Too many arguments for vector constructor.");
	va_start(AP, argCount);

	if (argCount > 1) {
		length_t argIdx = 0, elemIdx = 0;

		while (argIdx < argCount && elemIdx < L) {
			argType = va_arg(AP, unsigned int);

			glmGetTypeInfo(&argTypeInfo, argType);

			scalar(T, Q) *dstAddr = (scalar(T, Q) *) &Result.elem[0] + elemIdx;
			elemIdx += glmReadAndConvertArg(DST_ELEM_TYPE, dstAddr, L - elemIdx, &argTypeInfo, &AP);

			++argIdx;
		}
	} else {
		argType = va_arg(AP, unsigned int);
		argTypeFlag = 1ULL << argType;

		if (argTypeFlag & GLM_MASK_SCALAR)
		{
			scalar(T, Q) scalarValue = 0;
			length_t loopIdx = 0;

			switch (argTypeFlag) {
				case GLM_TYPE_BOOL: scalarValue = va_arg(AP, int); break;
				case GLM_TYPE_FLOAT: scalarValue = va_arg(AP, double); break;
				case GLM_TYPE_DOUBLE: scalarValue = va_arg(AP, double); break;
				case GLM_TYPE_INT: scalarValue = va_arg(AP, int); break;
				case GLM_TYPE_UINT: scalarValue = va_arg(AP, unsigned int); break;
			}

			while (loopIdx < L)
				Result.elem[loopIdx++] = scalarValue;
		}
	}

	va_end(AP);
	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
negate(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = -x.elem[i];

	return Result;
}


GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
add(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] + y.elem[i];

	return Result;
}


GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
sub(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] - y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
mul(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] * y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
div(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] / y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
adds(vec(L, T, Q) const x, T const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] + y;

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
subs(vec(L, T, Q) const x, T const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] - y;

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
muls(vec(L, T, Q) const x, T const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] * y;

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
divs(vec(L, T, Q) const x, T const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] / y;

	return Result;
}


GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
addeqs(vec(L, T, Q) *lhs, T const rhs)
{
	for(length_t i = 0; i < L; ++i)
		lhs->elem[i] += rhs;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
subeqs(vec(L, T, Q) *lhs, T const rhs)
{
	for(length_t i = 0; i < L; ++i)
		lhs->elem[i] -= rhs;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
muleqs(vec(L, T, Q) *lhs, T const rhs)
{
	for(length_t i = 0; i < L; ++i)
		lhs->elem[i] *= rhs;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
diveqs(vec(L, T, Q) *lhs, T const rhs)
{
	for(length_t i = 0; i < L; ++i)
		lhs->elem[i] /= rhs;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
addeqv(vec(L, T, Q) *lhs, vec(L, T, Q) const rhs)
{
	for(length_t i = 0; i < L; ++i)
		lhs->elem[i] += rhs.elem[i];
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
subeqv(vec(L, T, Q) *lhs, vec(L, T, Q) const rhs)
{
	for(length_t i = 0; i < L; ++i)
		lhs->elem[i] -= rhs.elem[i];
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
muleqv(vec(L, T, Q) *lhs, vec(L, T, Q) const rhs)
{
	for(length_t i = 0; i < L; ++i)
		lhs->elem[i] *= rhs.elem[i];
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR void
diveqv(vec(L, T, Q) *lhs, vec(L, T, Q) const rhs)
{
	for(length_t i = 0; i < L; ++i)
		lhs->elem[i] /= rhs.elem[i];
}