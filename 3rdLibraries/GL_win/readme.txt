You need to:
	1. copy glut32.dll to ../system;
	2. copy glut.h to ../Microsoft Visual Studio/VC/include/GL;
	3. copy glut32.lib to ../Microsoft Visual Studio/VC/lib.
	under MVS
	4. go to Project -> Properties; select Linker -> Input then add the following to the Additional Dependencies field:
		opengl32.lib; glu32.lib; glut32.lib;