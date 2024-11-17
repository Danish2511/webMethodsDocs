Compiling the C++ Applications:

The Universal Messaging C++ libraries have a dependency on OpenSSL 1.0.1. The library is available as part of the Software AG installation.

In order to make compilation easier, we have provided a CMake script which can be used to generate the build files for the target platform.  CMake can be downloaded from http://www.cmake.org/cmake/resources/software.html

Windows:

The Universal Messaging C++ libraries have been compiled using CMake and Microsoft Visual Studio 2015. To get the required environment for cmake you will need to run the Visual Studio 2015 Command Prompt available via the "Visual Studio Tools" folder.

	32bit:
		1) cmake -Wno-dev -G "Visual Studio 14" .
		2) cd [AppName]
		3) msbuild /p:Configuration=Release;PlatformType=x86 [AppName].sln
		4) set PATH=%PATH%;[Location_Of_UM_Install]\cplus\lib\x86;[Location_Of_UM_Install]/../common/security/openssl/bin;$[Location_Of_UM_Install]/../common/security/openssl/lib
		5) Release\[AppName].exe

	64bit:
		1) cmake -Wno-dev -G "Visual Studio 14 Win64"
		2) cd [AppName]
		3) msbuild /p:Configuration=Release;PlatformType=x64 [AppName].sln
		4) set PATH=%PATH%;[Location_Of_UM_Install]\cplus\lib\x86_64;[Location_Of_UM_Install]/../common/security/openssl/bin;$[Location_Of_UM_Install]/../common/security/openssl/lib
		5) Release\[AppName].exe


Linux

		1) cmake .
		2) cd [AppName]
		3) make
		4) export PATH=$PATH:[Location_Of_UM_Install]/cplus/lib/x86_64:[Location_Of_UM_Install]/../common/security/openssl/bin:$[Location_Of_UM_Install]/../common/security/openssl/lib
		5) ./[AppName]

OS X
        1) cmake .
        2) cd [AppName]
        3) make
        4) export DYLD_LIBRARY_PATH=[Location_Of_UM_Install]/cplus/lib/x86_64:[Location_Of_UM_Install]/../common/security/openssl/bin:$[Location_Of_UM_Install]/../common/security/openssl/lib
        5) ./[AppName]
