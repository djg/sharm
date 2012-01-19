import subprocess, os

for root, dirs, files in os.walk('.'):
	configFilename = os.path.normpath(os.path.abspath(root + '\\Solution.lua'))

	if not os.path.exists(configFilename):
		continue
	
	subprocess.call('premake4 --file=Solution.lua vs2010', cwd=root)