GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
pow(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_pow_scalar(T, Q)(x.elem[i], y.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
exp(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_exp_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
log(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_log_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
exp2(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_exp2_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
log2(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_log2_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
sqrt(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_sqrt_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
inversesqrt(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_inversesqrt_scalar(T, Q)(x.elem[i]);

	return Result;
}
