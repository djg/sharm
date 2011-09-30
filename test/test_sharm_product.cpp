#include "common.h"

static float s[36];
static float t[36];

static float tmp0[36];
static float tmp1[36];

static float v0[3];
static float v1[3];

typedef FLOAT* (WINAPI *D3DXSHMultiplyFn)(FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
 
D3DXSHMultiplyFn multiplyFn[] =
{
	0, 0, 0,
	D3DXSHMultiply3,
	D3DXSHMultiply4,
	D3DXSHMultiply5,
	D3DXSHMultiply6,
};

int main()
{
	int order = 3;
//	for (int order = 3; order <= 6; order++)
	{
		shevalfn evalfn = sheval[order];
		shprodfn prodfn = shprod[order];

		D3DXSHMultiplyFn multfn = multiplyFn[order];

		for (int n = 0; n < 1000000; ++n)
		{
			random_vec(v0);
			random_vec(v1);

			evalfn(v0[0], v0[1], v0[2], tmp0);
			evalfn(v1[0], v1[1], v1[2], tmp1);
			prodfn(tmp0, tmp1, s);
			
			D3DXVECTOR3 d3dv0(v0);
			D3DXVECTOR3 d3dv1(v1);
			D3DXSHEvalDirection(tmp0, order, &d3dv0);
			D3DXSHEvalDirection(tmp1, order, &d3dv1);
			multfn(t, tmp0, tmp1); 

			for (int i = 0; i < order*order; ++i)
			{
				if (s[i] != t[i])
				{
					printf("sh[%d]: %.17f == %.17f\n", i, s[i], t[i]);
					difference(s[i], t[i]);
				}
			}
		}
	}

	return 0;
}