GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, bool, Q)
lessThan(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, bool, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] < y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR  vec(L, bool, Q)
lessThanEqual(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, bool, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] <= y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR  vec(L, bool, Q)
greaterThan(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, bool, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] > y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR  vec(L, bool, Q)
greaterThanEqual(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, bool, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] >= y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR  vec(L, bool, Q)
equal(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, bool, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] == y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR  vec(L, bool, Q)
notEqual(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, bool, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] != y.elem[i];

	return Result;
}