dofile "build/DefaultConfig.lua"

project "Sharm"
	DefaultConfig()
	kind "StaticLib"
	language "C"
	includedirs { "." }
	files { "*.h", "*.c" }