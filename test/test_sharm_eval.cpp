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

typedef void (*shfunc)(float, float, float, float*);

shfunc shfp[] = 
{
	0, 0, 0,
	xhy_sh3_eval,
	xhy_sh4_eval,
	xhy_sh5_eval,
	xhy_sh6_eval,
};


int main()
{
	int order;
	for (order = 3; order <= 6; order++)
	{
		float* s = new float[order * order];
		float* t = new float[order * order];
		float v[3];
	
		int i;
		for (i = 0; i < 1000000; ++i)
		{
			random_vec(v);
		
			(shfp[order])(v[0], v[1], v[2], s);

			D3DXVECTOR3 d3dv(v);
			D3DXSHEvalDirection(t, order, &d3dv);

			for (int i = 0; i < order*order; ++i)
			{
				if (s[i] != t[i])
				{
					printf("sh[%d]: %.17f == %.17f\n", i, s[i], t[i]);
					difference(s[i], t[i]);
				}
			}
		}
	
		delete [] s;
		delete [] t;
	}

	return 0;
}