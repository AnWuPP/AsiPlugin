# AsiPlugin
This is an example of an ASI plugin for SA:MP built with CMake
## Preparing
Open command line

    git clone https://github.com/AnWuPP/AsiPlugin.git
    cd AsiPlugin
Open CMakeLists.txt in project folder and change SET options for youself!  
**`ASI_FILENAME`** - output filename after compile, without extention.
## Build
In command line, change `PATH_TO_SAMP` for youself

    cmake -B build -A Win32 -DPATH_TO_SAMP="D:/Games/Grand Theft Auto San Andreas Samp RP/"
After creating cmake cache

    cmake --build build
ASI file will be put to you game folder, launch game :)
## Other
To change the SA:MP directory after creating the cache

    cmake -B build -DPATH_TO_SAMP="new_path"
    cmake --build build
If turn PATH_TO_SAMP off (`-DPATH_TO_SAMP=OFF`), then will default path `path_to_project/Debug` or `path_to_project/Release` depending on the config.