#include "common.h"
#include <UnitTest++/UnitTest++.h>

#define XHY_HEADER_FILE_ONLY
extern "C" {
#include "../xhy_sharm.c"
}

namespace {
	TEST(DXProd3) {
		float s[9];
		float t[9];

		float tmp0[9];
		float tmp1[9];

		float v0[3];
		float v1[3];

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

		CHECK_ARRAY_EQUAL(t, s, 9);
	}

	TEST(DXProd4) {
		float s[16];
		float t[16];

		float tmp0[16];
		float tmp1[16];

		float v0[3];
		float v1[3];

		random_vec(v0);
		random_vec(v1);

		xhy_sh4_eval(v0[0], v0[1], v0[2], tmp0);
		xhy_sh4_eval(v1[0], v1[1], v1[2], tmp1);
		xhy_sh4_product(tmp0, tmp1, s);

		D3DXVECTOR3 d3dv0(v0);
		D3DXVECTOR3 d3dv1(v1);
		D3DXSHEvalDirection(tmp0, 4, &d3dv0);
		D3DXSHEvalDirection(tmp1, 4, &d3dv1);
		D3DXSHMultiply4(t, tmp0, tmp1); 

		CHECK_ARRAY_EQUAL(t, s, 16);
	}
}
