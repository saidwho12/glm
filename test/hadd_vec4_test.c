#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

static float __attribute__((__naked__)) __attribute__((__noinline__))
hadd_vec4_sse1_ver1(const float *v)
{
	__asm__
	(
		"movaps (%0), %%xmm0\n\t"
		"movaps %%xmm0, %%xmm1\n\t"
		"shufps $177, %%xmm0, %%xmm1\n\t"
		"addps %%xmm1, %%xmm0\n\t"
		"movhlps %%xmm0, %%xmm1\n\t"
		"addss %%xmm1, %%xmm0\n\t"
		"ret"
		:: "r" (v)
	);
}

static float __attribute__((__naked__)) __attribute__((__noinline__))
hadd_vec4_sse1_ver2(const float *v)
{
	__asm__
	(
		"movss (%0), %%xmm0\n\t"
		"addss 4(%0), %%xmm0\n\t"
		"addss 8(%0), %%xmm0\n\t"
		"addss 12(%0), %%xmm0\n\t"
		"ret"
		:: "r" (v)
	);
}

static float __attribute__((__naked__)) __attribute__((__noinline__))
hadd_vec4_sse3_ver1(const float *v)
{
	__asm__
	(
		"movaps (%0), %%xmm0\n\t"
		"movshdup %%xmm0, %%xmm1\n\t"
		"addps %%xmm0, %%xmm1\n\t"
		"movhlps %%xmm1, %%xmm0\n\t"
		"addss %%xmm1, %%xmm0\n\t"
		"ret"
		:: "r" (v)
	);
}

static float __attribute__((__naked__)) __attribute__((__noinline__))
hadd_vec4_sse3_ver2(const float *v)
{
	__asm__
	(
		"movaps (%0), %%xmm0\n\t"
		"haddps %%xmm0, %%xmm0\n\t"
		"haddps %%xmm0, %%xmm0\n\t"
		"ret"
		:: "r" (v)
	);
}

static float __attribute__((__noinline__))
hadd_vec4_c(const float *v)
{
    return v[0] + v[1] + v[2] + v[3];
}

/*
typedef struct glm_fmv
{
	float (*hadd_vec4)(const float *);
} glm_fmv_t;

static glm_fmv_t glm_static_fmv_impl;

typedef enum glm_simd_flags_x86
{
	GLM_SIMD_XMM_BIT = 0x1,
	GLM_SIMD_SSE_BIT = 0x2,
} glm_simd_flags_x86_t;

inline float
glm_fmv_hadd_vec4(const glm_fmv_t *impl, const float *v)
{
	return impl->hadd_vec4(v);
}

void
glm_fmv_optimize(const float *v)
{
	
}
*/
#if 1
#define TESTED_FUNCTION_NAME hadd_vec4_sse1_ver1
#define STRINGIFY_(x) (char *)( #x )
#define STRINGIFY(...) STRINGIFY_(__VA_ARGS__)

#define SIMD_ITERATIONS (1000)
#define SIMD_OPERATIONS (10000)

int main(void)
{
    srand( time(NULL) );
    struct timespec start, end;
    uint64_t delta_us;
    float *data = (float *) malloc(SIMD_OPERATIONS * sizeof(float) * 4);
	float time_sum = 0.0f;

	for (unsigned int j = 0; j < SIMD_ITERATIONS; ++j)
	{
		float sum = 0.0f;
		
		/* Initialize testing data */
		for (unsigned int i = 0; i < SIMD_OPERATIONS; ++i)
		{
			float *x = &data[i * 4];
			*(x + 0) = rand();
			*(x + 1) = rand();
			*(x + 2) = rand();
			*(x + 3) = rand();
		}

		/* Start timer */
		clock_gettime(CLOCK_MONOTONIC, &start);

		for (unsigned int i = 0; i < SIMD_OPERATIONS; ++i)
		{
			sum += TESTED_FUNCTION_NAME( &data[i*4] );
		}
		
		/* Stop timer */
		clock_gettime(CLOCK_MONOTONIC, &end);
		printf("%f\n", sum);
		delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
		printf("[iter %u]: %u operation of %s took %lu us.\n", j, SIMD_OPERATIONS, STRINGIFY(TESTED_FUNCTION_NAME), delta_us);
		time_sum += (float)delta_us;
	}

	float time_avg = time_sum / (float)SIMD_ITERATIONS;
	printf("Average time for %u iterations of %u operations of %s: %f\n", SIMD_ITERATIONS, SIMD_OPERATIONS, STRINGIFY(TESTED_FUNCTION_NAME), time_avg);

	return EXIT_SUCCESS;
}
#endif