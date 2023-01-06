cmake_minimum_required (VERSION 3.8)

# change for you "D:/Games/Grand Theft Auto San Andreas Samp RP/"
set(ASI_FILENAME "AsiPlugin")
option(PATH_TO_SAMP "Path to game folder" OFF)

project (${ASI_FILENAME}
	VERSION 0.0
)

add_subdirectory(src)