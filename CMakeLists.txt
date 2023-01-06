cmake_minimum_required (VERSION 3.15)

project ("AsiPlugin"
	VERSION 0.0
)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_subdirectory(src)