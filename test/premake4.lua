solution "xhy_sharm"
    configurations { "Debug", "Release" }
	includedirs { "$(DXSDK_DIR)/include" }
	libdirs { "$(DXSDK_DIR)/Lib/x86" }
	links { "d3dx9", "d3d9" }
	
project "test_sharm_eval"
    kind "ConsoleApp"
    language "C++"
    files { "test_sharm_eval.cpp" }

    configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    configuration "Release"
        defines { "NDEBUG" }
        flags { "Optimize" }