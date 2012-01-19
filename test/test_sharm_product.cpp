#include "common.h"
#include <UnitTest++/UnitTest++.h>

#define XHY_HEADER_FILE_ONLY
extern "C" {
#include "../xhy_sharm.c"
}

#define SAMPLE_COUNT 1000000

namespace {
	TEST(DXProd3) {
		static float s[9];
		static float t[9];

		static float tmp0[9];
		static float tmp1[9];

		static float v0[3];
		static float v1[3];

		for (int n = 0; n < SAMPLE_COUNT; ++n)
		{
			random_vec(v0);
			random_vec(v1);

			xhy_sh3_eval(v0[0], v0[1], v0[2], tmp0);
			xhy_sh3_eval(v1[0], v1[1], v1[2], tmp1);
			xhy_sh3_product(tmp0, tmp1, s);

			D3DXVECTOR3 d3dv0(v0);
			D3DXVECTOR3 d3dv1(v1);
			D3DXSHEvalDirection(tmp0, 3, &d3dv0);
			D3DXSHEvalDirection(tmp1, 3, &d3dv1);
			D3DXSHMultiply3(t, tmp0, tmp1); 

			for (int i = 0; i < 9; ++i)
			{
				CHECK_EQUAL(t[i], s[i]);
				/*				if (s[i] != t[i])
				{
				printf("sh[%d]: %.17f == %.17f\n", i, s[i], t[i]);
				difference(s[i], t[i]);
				}*/
			}
		}
	}
}
