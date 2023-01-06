include(FetchContent)

FetchContent_Declare(
	sampapi
	GIT_REPOSITORY https://github.com/BlastHackNet/SAMP-API.git
	GIT_TAG f89b35edb7eaf5db374e32a63f2366c4bb714418
)
FetchContent_Declare(
	ktsignal
	GIT_REPOSITORY https://github.com/kin4stat/ktsignal.git
	GIT_TAG f08a19d9a00ad5284871bf44178d835da7b26ebf
)
FetchContent_Declare(
	kthook
	GIT_REPOSITORY https://github.com/kin4stat/kthook.git
	GIT_TAG 21ca70481273d1efcc98ca49063178e46277009b
)
FetchContent_Declare(
	RakHook
	GIT_REPOSITORY https://github.com/imring/RakHook.git
	GIT_TAG 625fd17897395997feb56ae293c7c07dbe49d26b
)
FetchContent_MakeAvailable(sampapi ktsignal kthook rakhook)

add_library(AsiPlugin SHARED)

include_directories(
	${PROJECT_SOURCE_DIR}/include
)
target_sources(AsiPlugin PRIVATE
	main.cpp
	Plugin.cpp
	PluginRPC.cpp
)

set_target_properties(AsiPlugin
    PROPERTIES
    OUTPUT_NAME ${ASI_FILENAME}
    SUFFIX ".asi"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PATH_TO_SAMP}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PATH_TO_SAMP}
)
target_compile_features(AsiPlugin PUBLIC cxx_std_20)
target_link_libraries(AsiPlugin PUBLIC sampapi kthook rakhook)

set_property(TARGET AsiPlugin PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")