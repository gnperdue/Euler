workspace "euler"
    configurations {"Release", "Debug", }
    kind "ConsoleApp"
    location "build"
    language "C"

    filter "configurations:Release"
        defines {"NODEBUG"}
        optimize "on"

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "on"

project "euler003"
    location "build/euler003"
    targetdir "bin/%{cfg.buildcfg}"
    files {"euler003/*.h", "euler003/*.c"}

project "euler010"
    location "build/euler010"
    targetdir "bin/%{cfg.buildcfg}"
    files {"euler010/*.h", "euler010/*.c"}

project "euler014_pthr"
    location "build/euler014_pthr"
    targetdir "bin/%{cfg.buildcfg}"
    files {"euler014/euler014_pthr.c"}

-- $ mpicc -compile_info
-- clang -Wl,-flat_namespace -Wl,-commons,use_dylibs \
--   -I/usr/local/Cellar/mpich/3.2.1_2/include \
--   -L/usr/local/Cellar/mpich/3.2.1_2/lib \
--   -lmpi -lpmpi
project "euler014_mpi"
    location "build/euler014_mpi"
    targetdir "bin/%{cfg.buildcfg}"
    files {"euler014/euler014_mpi.c"}
    includedirs {"/usr/local/Cellar/mpich/3.2.1_2/include"}
    libdirs {"/usr/local/Cellar/mpich/3.2.1_2/lib"}
    links {
        "mpi",
        "pmpi"
    }
    linkoptions {
        "-Wl,-flat_namespace",
        "-Wl,-commons,use_dylibs",
    }

project "euler024"
    location "build/euler024"
    targetdir "bin/%{cfg.buildcfg}"
    files {"euler024/*.h", "euler024/*.c"}
