# AsiPlugin
This is example
## Preparing
Open CMakeLists.txt in main folder, change SET option for you!
**ASI_FILENAME** - output filename after compile, without extention.
**PATH_TO_SAMP** - path for you game directory.
## Build
Open command line:

    git clone https://github.com/AnWuPP/AsiPlugin.git
    cd AsiPlugin
    mkdir build && cd build
    cmake .. -A Win32
After creating cmake cache

    cmake --build .
Asi file put to you game folder, open game :)