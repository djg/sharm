#include "common.h"

static float s[36];
static float t[36];

static float v[3];

int main()
{
	for (int order = 3; order <= 6; order++)
	{
		shevalfn evalfn = sheval[order];
		
		for (int i = 0; i < 1000000; ++i)
		{
			random_vec(v);
		
			evalfn(v[0], v[1], v[2], s);

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
	}

	return 0;
}