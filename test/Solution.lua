solution "TestSharm"
	configurations { "Debug", "Release" }

dofile "Project.lua"
dofile "../Project.lua"
dofile "../external/UnitTest++/Project.lua"