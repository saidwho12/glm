GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
abs(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_abs_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
sign(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
	{
		if (x.elem[0] > (T)0)
		{
			Result.elem[i] = (T)1;
		}
		else if (x.elem[0] < (T)0)
		{
			Result.elem[i] = (T)-1;
		}
		else
		{
			Result.elem[i] = (T)0;
		}
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
floor(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_floor_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
trunc(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_trunc_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
round(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_round_scalar(T, Q)(x.elem[i]);

	return Result;
}
/*
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
roundEven(vec(L, T, Q) const x)
{
}
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
ceil(vec(L, T, Q) const x)
{

}
*/

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
fract(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] - compute_floor_scalar(T, Q)(x.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
mod(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_mod_scalar(T, Q)(x.elem[i], y.elem[i]);

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
mods(vec(L, T, Q) const x, T const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = compute_mod_scalar(T, Q)(x.elem[i], y);

	return Result;
}
/*
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
modf(vec(L, T, Q) const x, vec(L, T, Q) *y)
{
	
}*/

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
min(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = y.elem[i] < x.elem[i] ? y.elem[i] : x.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
mins(vec(L, T, Q) const x, T const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = y < x.elem[i] ? y : x.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
max(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] < y.elem[i] ? y.elem[i] : x.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
maxs(vec(L, T, Q) const x, T const y)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] < y ? y : x.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
clamp(vec(L, T, Q) const x, vec(L, T, Q) const minVal, vec(L, T, Q) const maxVal)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
	{
		Result.elem[i] = x.elem[i] < minVal.elem[i] ? minVal.elem[i]
		: (x.elem[i] > maxVal.elem[i] ? maxVal.elem[i] : x.elem[i]);
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
clamps(vec(L, T, Q) const x, T const minVal, T const maxVal)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
	{
		Result.elem[i] = x.elem[i] < minVal ? minVal
		: (x.elem[i] > maxVal ? maxVal : x.elem[i]);
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
mix(vec(L, T, Q) const x, vec(L, T, Q) const y, vec(L, T, Q) const a)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
	{
		Result.elem[i] = x.elem[i] * a.elem[i] + y.elem[i] * ((T)1 - a.elem[i]);
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
mixs(vec(L, T, Q) const x, vec(L, T, Q) const y, T const a)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
	{
		Result.elem[i] = x.elem[i] * a + y.elem[i] * ((T)1 - a);
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
step(vec(L, T, Q) const edge, vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] < edge.elem[i] ? (T)0 : (T)1;

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
steps(T const edge, vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] < edge ? (T)0 : (T)1;

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
smoothstep(vec(L, T, Q) const edge0, vec(L, T, Q) const edge1, vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
	{
		T const tmp = (x.elem[i] - edge0.elem[i])
			/ (edge1.elem[i] - edge0.elem[i]);

		Result.elem[i] = tmp * tmp * ((T)3 - (T)2 * tmp);
	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
smoothsteps(T const edge0, T const edge1, vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;

	for(length_t i = 0; i < L; ++i)
	{
		T const tmp = (x.elem[i] - edge0) / (edge1 - edge0);
		Result.elem[i] = tmp * tmp * ((T)3 - (T)2 * tmp);
	}

	return Result;
}
/*
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
isnan()
{

}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
isinf()
{

}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
fma()
{

}
*/
/*
floatBitsToInt
floatBitsToUint
intBitsToFloat
uintBitsToFloat
frexp
ldexp
*/