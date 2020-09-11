typedef
struct vec(L, T, Q) 
{
	union {
		GLM_VECTOR_DATA(L, T, Q);
		GLM_SWIZZLE_MEMBERS(L, T, Q);
	};
} vec(L, T, Q);

GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q) constructor(length_t const argCount, ...);
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q) negate(vec(L, T, Q) const x);
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q) add(vec(L, T, Q) const x, vec(L, T, Q) const y);
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q) sub(vec(L, T, Q) const x, vec(L, T, Q) const y);
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q) mul(vec(L, T, Q) const x, vec(L, T, Q) const y);
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(L, T, Q) div(vec(L, T, Q) const x, vec(L, T, Q) const y);