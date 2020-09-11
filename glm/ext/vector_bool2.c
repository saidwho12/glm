
#include "../detail/namespace_begin.inl"
#include "../detail/namespace_template_vector_begin.inl"
#define L 2
#define T bool
#define Q defaultp
#include "../detail/func_vector_bool.inl"
#undef L
#undef T
#undef Q
#include "../detail/namespace_template_vector_end.inl"
#include "../detail/namespace_end.inl"

/*
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(2, bool, defaultp)
glm_or_bvec2(vec(2, bool, defaultp) const x, vec(2, bool, defaultp) const y)
{
	vec(2, bool, defaultp) Result;

	for(length_t i = 0; i < 2; ++i)
		Result.elem[i] = x.elem[i] || y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(2, bool, defaultp)
glm_and_bvec2(vec(2, bool, defaultp) const x, vec(2, bool, defaultp) const y)
{
	vec(2, bool, defaultp) Result;

	for(length_t i = 0; i < 2; ++i)
		Result.elem[i] = x.elem[i] && y.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(2, bool, defaultp)
glm_xor_bvec2(vec(2, bool, defaultp) const x, vec(2, bool, defaultp) const y)
{
	vec(2, bool, defaultp) Result;

	for(length_t i = 0; i < 2; ++i)
	{
		Result.elem[i] = (x.elem[i] && !y.elem[i])
			|| (!x.elem[i] && y.elem[i]);


	}

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool
glm_all_bvec2(vec(2, bool, defaultp) const v)
{
	bool Result = false;

	for(length_t i = 0; i < 2; ++i)
		Result = Result && v.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool
glm_any_bvec2(vec(2, bool, defaultp) const v)
{
	bool Result = true;

	for(length_t i = 0; i < 2; ++i)
		Result = Result || v.elem[i];

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(2, bool, defaultp)
glm_not_bvec2(vec(2, bool, defaultp) const v)
{
	vec(2, bool, defaultp) Result;

	for(length_t i = 0; i < 2; ++i)
		Result.elem[i] = !v.elem[i];

	return Result;
}
*/