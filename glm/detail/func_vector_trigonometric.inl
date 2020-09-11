GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
sin(vec(L, T, Q) const angle)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_sin_scalar(T, Q)( angle.elem[i] );

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
cos(vec(L, T, Q) const angle)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_cos_scalar(T, Q)( angle.elem[i] );

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
tan(vec(L, T, Q) const angle)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_tan_scalar(T, Q)( angle.elem[i] );

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
asin(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_asin_scalar(T, Q)( x.elem[i] );

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
acos(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_acos_scalar(T, Q)( x.elem[i] );

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
atan(vec(L, T, Q) const y_over_x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_atan_scalar(T, Q)( y_over_x.elem[i] );

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
atan2(vec(L, T, Q) const y, vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_atan2_scalar(T, Q)( y.elem[i], x.elem[i] );

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
sinh(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = (compute_exp_scalar(T, Q)(x.elem[i]) - compute_exp_scalar(T, Q)(-x.elem[i])) / (T)2;

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
cosh(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = (compute_exp_scalar(T, Q)(x.elem[i]) + compute_exp_scalar(T, Q)(-x.elem[i])) / (T)2;

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
tanh(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
	{
		T k = compute_exp_scalar(T, Q)( (T)2 * x.elem[i] );
		Result.elem[i] = (k - (T)1) / (k + (T)1);
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
asinh(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
	{
		T tmp = (compute_exp_scalar(T, Q)(x.elem[i]) - compute_exp_scalar(T, Q)(-x.elem[i])) / (T)2;
		Result.elem[i] = (T)1 / tmp;
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
acosh(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
	{
		T tmp = (compute_exp_scalar(T, Q)(x.elem[i]) + compute_exp_scalar(T, Q)(-x.elem[i])) / (T)2;
		Result.elem[i] = (T)1 / tmp;
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
atanh(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for (length_t i = 0; i < L; ++i)
	{
		T k = compute_exp_scalar(T, Q)( (T)2 * x.elem[i] );
		T tmp = (k - (T)1) / (k + (T)1);
		Result.elem[i] = (T)1 / tmp;
	}

	return Result;
}