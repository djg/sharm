function DefaultConfig()
	platforms { "x32", "x64" }

	configuration "Debug"
		targetdir "bin/Debug/x32"
		defines { "DEBUG", "WIN32", "_CRT_SECURE_NO_WARNINGS" }
		flags { "Symbols" }

	configuration "Release"
    	targetdir "bin/Release/x32"
     	defines { "NDEBUG", "WIN32", "_CRT_SECURE_NO_WARNINGS" }
    	flags { "Optimize", "Symbols" }    

  	configuration { "Debug", "x64" }
      	targetdir "bin/Debug/x64"

   	configuration { "Release", "x64" }
      	targetdir "bin/Release/x64"

   configuration "*"
end
