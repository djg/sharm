#include "common.h"
#include <UnitTest++/UnitTest++.h>

#define XHY_HEADER_FILE_ONLY
extern "C" {
#include "../xhy_sharm.c"
}

#define SAMPLE_COUNT 1000000

namespace {

	TEST(SH3Eval) {	
		static float s[9];
		static float t[9];

		static float v[3];

		for (int i = 0; i < SAMPLE_COUNT; ++i)
		{
			random_vec(v);

			xhy_sh3_eval(v[0], v[1], v[2], s);

			D3DXVECTOR3 d3dv(v);
			D3DXSHEvalDirection(t, 3, &d3dv);

			for (int i = 0; i < 9; ++i)
			{
				CHECK_EQUAL(t[i], s[i]);
			}
		}
	}

	TEST(SH4Eval) {	
		static float s[16];
		static float t[16];

		static float v[3];

		for (int i = 0; i < SAMPLE_COUNT; ++i)
		{
			random_vec(v);

			xhy_sh4_eval(v[0], v[1], v[2], s);

			D3DXVECTOR3 d3dv(v);
			D3DXSHEvalDirection(t, 4, &d3dv);

			for (int i = 0; i < 16; ++i)
			{
				CHECK_EQUAL(t[i], s[i]);
			}
		}
	}

	TEST(SH5Eval) {	
		static float s[25];
		static float t[25];

		static float v[3];

		for (int i = 0; i < SAMPLE_COUNT; ++i)
		{
			random_vec(v);

			xhy_sh5_eval(v[0], v[1], v[2], s);

			D3DXVECTOR3 d3dv(v);
			D3DXSHEvalDirection(t, 5, &d3dv);

			for (int i = 0; i < 25; ++i)
			{
				CHECK_EQUAL(t[i], s[i]);
			}
		}
	}

	TEST(SH6Eval) {	
		static float s[36];
		static float t[36];

		static float v[3];

		for (int i = 0; i < SAMPLE_COUNT; ++i)
		{
			random_vec(v);

			xhy_sh6_eval(v[0], v[1], v[2], s);

			D3DXVECTOR3 d3dv(v);
			D3DXSHEvalDirection(t, 6, &d3dv);

			for (int i = 0; i < 36; ++i)
			{
				CHECK_EQUAL(t[i], s[i]);
			}
		}
	}
}