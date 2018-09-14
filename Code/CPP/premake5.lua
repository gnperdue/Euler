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
    location "build/euler003"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler003/euler003.cpp"}

project "euler004"
    location "build/euler004"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler004/euler004.cpp"}

project "euler005"
    location "build/euler005"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler005/euler005.cpp"}

project "euler008"
    location "build/euler008"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler008/euler008.cpp"}

project "euler009"
    location "build/euler009"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler009/euler009.cpp"}

project "euler010"
    location "build/euler010"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler010/euler010.cpp"}

project "euler012"
    location "build/euler012"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler012/euler012.cpp"}

project "euler013"
    location "build/euler013"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler013/euler013.cpp"}

project "euler014"
    location "build/euler014"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"eulerlib"}
    libdirs {"lib/%{cfg.buildcfg}"}
    links {"euler"}
    files {"euler014/euler014.cpp"}
