GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec(3, T, Q)
cross(vec(3, T, Q) const x, vec(3, T, Q) const y)
{
	vec(3, T, Q) Result;

	Result.x = x.y * y.z - y.y * x.z;
	Result.y = x.z * y.x - y.z * x.x;
	Result.z = x.x * y.y - y.x * x.y;

	return Result;
}