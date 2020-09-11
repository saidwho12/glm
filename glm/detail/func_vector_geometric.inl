GLM_FUNC_QUALIFIER GLM_CONSTEXPR T
length(vec(L, T, Q) const x)
{
	T tmp = (T)0;

	for (length_t i = 0; i < L; ++i) tmp += x.elem[i] * x.elem[i];

	return compute_sqrt_scalar(T, Q)(tmp);
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR T
distance(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	T tmp = (T)0;

	for (length_t i = 0; i < L; ++i)
	{
		T delta = x.elem[i] - y.elem[i];
		tmp += delta * delta;
	}

	return compute_sqrt_scalar(T, Q)(tmp);
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR T
dot(vec(L, T, Q) const x, vec(L, T, Q) const y)
{
	T tmp = (T)0;

	for (length_t i = 0; i < L; ++i)
		tmp += x.elem[i] * y.elem[i];

	return tmp;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
normalize(vec(L, T, Q) const x)
{
	vec(L, T, Q) Result;
	T len = length(x);

	for (length_t i = 0; i < L; ++i)
		Result.elem[i] = x.elem[i] / len;

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
faceforward(vec(L, T, Q) const N, vec(L, T, Q) const I, vec(L, T, Q) const Nref)
{
	return (dot(Nref,I) < 0) ? N : negate(N);
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q)
reflect(vec(L, T, Q) const I, vec(L, T, Q) const N)
{
	return sub(I, muls(N, 2 * dot(N,I)));
}