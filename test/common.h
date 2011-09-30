#ifndef XHY_TEST_COMMON_H
#define XHY_TEST_COMMON_H

#include <cstdio>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <math.h>
#include <d3dx9.h>

#include "../xhy_sharm.c"

float
random(float a, float b)
{
	return ((b-a)*((float)rand()/RAND_MAX))+a;
}

void
random_vec(float* v)
{
	float z = random(-1.0f, 1.0f);
	float t = random(0.0f, (float)M_2_PI);
	float w = sqrtf(1.0f - z*z);
	float x = w * cos(t);
	float y = w * sin(t);
	v[0] = x; v[1] = y; v[2] = z;
}

int
punt(float x)
{
	union { float f; int i; } u = { x };
	int i = u.i;

	// Make aInt lexicographically ordered as a twos-complement int
	return (i >= 0) ? i : i = 0x80000000 - i;
}

void
difference(float a, float b)
{
	int ia = punt(a);
	int ib = punt(b);
	int diff = abs(ia - ib);

	printf("  %f [0x%08x] - %f [0x%08x] = %d\n", a, ia, b, ib, diff);
}

void
print(float f)
{
	union { float f; int i; } v = { f };
	int i = v.i;
	printf("f = %.17f [0x%08x]\n", f, i);
}

typedef void (*shevalfn)(float, float, float, float*);

shevalfn sheval[] = 
{
	0, 0, 0,
	xhy_sh3_eval,
	xhy_sh4_eval,
	xhy_sh5_eval,
	xhy_sh6_eval,
};

typedef void (*shprodfn)(const float* a, const float* b, float* c);

shprodfn shprod[] =
{
	0, 0, 0,
	xhy_sh3_product,
	xhy_sh4_product,
	xhy_sh5_product,
	xhy_sh6_product,
};

#endif // !XHY_TEST_COMMON_H