workspace "euler"
    configurations {"Release", "Debug", }
    kind "ConsoleApp"
    location "build"
    language "C++"
    buildoptions {"-Werror -Wall -std=c++1y -stdlib=libc++"}
    linkoptions {"-stdlib=libc++"}

    filter "configurations:Release"
        defines {"NODEBUG"}
        optimize "on"

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "on"

project "libeuler.so"
    location "build/eulerlib"
    targetdir "lib/%{cfg.buildcfg}"
    files {"eulerlib/*.h", "eulerlib/*.cpp"}
    buildoptions {"-fPIC"}
    linkoptions {"-shared"}

project "euler001a"
    location "build/euler001a"
    targetdir "bin/%{cfg.buildcfg}"
    files {"euler001/euler001a.cpp"}

project "euler001b"
    location "build/euler001b"
    targetdir "bin/%{cfg.buildcfg}"
    files {"euler001/euler001b.cpp"}

project "euler001c"
    location "build/euler001c"
    targetdir "bin/%{cfg.buildcfg}"
    files {"euler001/euler001c.cpp"}

project "euler002"
    location "build/euler002"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler002/euler002.cpp"}

project "euler003"
    location "build/euler002"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler002/euler002.cpp"}

project "euler010"
    location "build/euler010"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler010/euler010.cpp"}
