# AsiPlugin
This is an example of an ASI plugin for SA:MP built with CMake
## Preparing:
Open command line

    git clone https://github.com/AnWuPP/AsiPlugin.git
    cd AsiPlugin
Open CMakeLists.txt in project folder, change SET options for youself!
    **ASI_FILENAME** - output filename after compile, without extention.
    **PATH_TO_SAMP** - path for you game directory.
## Build
Open command line

    mkdir build && cd build
    cmake .. -A Win32
After creating cmake cache

    cmake --build .
ASI file will be put to you game folder, launch game :)