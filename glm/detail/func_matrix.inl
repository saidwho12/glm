GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat(C, R, T, Q)
matrixCompMult(mat(C, R, T, Q) const x, mat(C, R, T, Q) const y)
{
	
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat(C, R, T, Q)
outerProduct(vec(C, T, Q) const c, vec(C, T, Q) const r)
{

}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR T
determinant(mat(C, R, T, Q) const m)
{
	
}

/* Inverse matrix */
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat(C, R, T, Q)
inverse(mat(C, R, T, Q) const m)
{
	mat(C, R, T, Q) Result;

		

	return Result;
}

GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat(R, C, T, Q)
transpose(mat(C, R, T, Q) const m)
{
	mat(R, C, T, Q) Result;
	length_t i, j;

	for (i = 0; i < C; ++i)
		for (j = 0; j < R; ++j)
			Result.elem[j][i] = m.elem[i][j];

	return Result;
}