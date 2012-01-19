dofile "../../build/DefaultConfig.lua"

project "UnitTest++"
	DefaultConfig()
	kind "StaticLib"
   	language "C++"
   	includedirs { ".." }
   	files { "**.h", "**.cpp" }
