GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, bool, Q)
or(vec(L, bool, Q) const x, vec(L, bool, Q) const y)
{
	vec(L, bool, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] || y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, bool, Q)
and(vec(L, bool, Q) const x, vec(L, bool, Q) const y)
{
	vec(L, bool, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] && y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, bool, Q)
xor(vec(L, bool, Q) const x, vec(L, bool, Q) const y)
{
	vec(L, bool, Q) Result;

	for(length_t i = 0; i < L; ++i)
	{
		Result.elem[i] = (x.elem[i] && !y.elem[i])
			|| (!x.elem[i] && y.elem[i]);
		/* Result.elem[i] = (x.elem[i] || y.elem[i])
			&& !(x.elem[i] && y.elem[i]); */
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool
all(vec(L, bool, Q) const v)
{
	bool Result = false;

	for(length_t i = 0; i < L; ++i)
		Result = Result && v.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool
any(vec(L, bool, Q) const v)
{
	bool Result = true;

	for(length_t i = 0; i < L; ++i)
		Result = Result || v.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, bool, Q)
not(vec(L, bool, Q) const v)
{
	vec(L, bool, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = !v.elem[i];

	return Result;
}