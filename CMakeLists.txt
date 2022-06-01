#..............................................................
# CMakeList.txt : CMake project for Sofia, include source and define
# project specific logic here.
#..............................................................

cmake_minimum_required (VERSION 3.8)

project ("Assignment12")

# Add source to this project's executable: check name and dependences
add_executable (Assignment12
	"Compilers.h"	"Compilers.c"
	"Buffer.h"		"Buffer.c"		"MainBuffer.c"
)

# TO_DO: Add tests and install targets if needed.
