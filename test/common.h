#ifndef XHY_TEST_COMMON_H
#define XHY_TEST_COMMON_H

#include <cstdio>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <math.h>
#include <d3dx9.h>

inline float
random(float a, float b)
{
	return ((b-a)*((float)rand()/RAND_MAX))+a;
}

inline void
random_vec(float* v)
{
	float z = random(-1.0f, 1.0f);
	float t = random(0.0f, (float)M_2_PI);
	float w = sqrtf(1.0f - z*z);
	float x = w * cos(t);
	float y = w * sin(t);
	v[0] = x; v[1] = y; v[2] = z;
}

inline int
punt(float x)
{
	union { float f; int i; } u = { x };
	int i = u.i;

	// Make aInt lexicographically ordered as a twos-complement int
	return (i >= 0) ? i : i = 0x80000000 - i;
}

inline void
difference(float a, float b)
{
	int ia = punt(a);
	int ib = punt(b);
	int diff = abs(ia - ib);

	printf("  %f [0x%08x] - %f [0x%08x] = %d\n", a, ia, b, ib, diff);
}

inline void
print(float f)
{
	union { float f; int i; } v = { f };
	int i = v.i;
	printf("f = %.17f [0x%08x]\n", f, i);
}

#endif // !XHY_TEST_COMMON_H