dofile "../build/DefaultConfig.lua"

project "TestSharm"
	kind "ConsoleApp"
	configuration "x32"
		libdirs { "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86" }
	configuration "x64"
		libdirs { "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64" }
	configuration "*"
	language "C++"
	includedirs { "../", "../external", "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include" }
	files { "*.h", "*.cpp", "../xhy_sharm.c" }
	links { "UnitTest++", "d3dx9" }

	DefaultConfig()

	postbuildcommands { "\"$(TargetPath)\"" }