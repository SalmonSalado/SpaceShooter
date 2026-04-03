cmake_minimum_required(VERSION 4.2.1)
project(myProject)

set(MY_SOURCES 
	${CMAKE_SOURCE_DIR} main.cpp
	${CMAKE_SOURCE_DIR} src/ball.cpp
)


add_executable(game ${MY_SOURCES})
target_include_directories(game PRIVATE include/)

# This is to check if raylib is in the project, and if not, populate it into the external library folder
find_package(raylib QUIET)
if (NOT raylib_FOUND )
	if (NOT EXISTS ${CMAKE_SOURCE_DIR}/external/raylib/CMakeLists.txt) 
		message(STATUS "Raylib library was not found, creating from git...")
		include(FetchContent)
		FetchContent_Declare(
			raylib
			GIT_REPOSITORY https://github.com/raysan5/raylib.git
			GIT_TAG 5.5
			SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/raylib

		)

		FetchContent_MakeAvailable(raylib)
	
	endif()

endif()

# To add raylib to the subdirectories
#add_subdirectory(external/raylib)

# I guess now we also need to include directories

# This is to check if it's windows

if (WIN32)
	#target_include_directories(game PRIVATE
		#external/raylib/src
		#	)

	target_link_libraries(game PRIVATE 
		raylib
		opengl32
		gdi32
		winmm
	)
endif()
