solution "xhy_sharm"
    configurations { "Debug", "Release" }
	includedirs { "$(DXSDK_DIR)/include" }
	libdirs { "$(DXSDK_DIR)/Lib/x86" }
	links { "d3dx9d", "d3d9" }

	configuration "Debug"
        defines { "DEBUG", "_DEBUG" }
        flags { "Symbols" }

    configuration "Release"
        defines { "NDEBUG" }
        flags { "Optimize" }
		
project "test_sharm_eval"
    kind "ConsoleApp"
    language "C++"
    files { "test_sharm_eval.cpp", "test_common.h" }

 project "test_sharm_product"
	kind "ConsoleApp"
	language "C++"
	files { "test_sharm_product.cpp", "test_common.h" }