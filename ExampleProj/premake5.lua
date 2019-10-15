workspace "Example"
    configurations {"Release", "Debug"}
project "Example"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"src/", "../src/include"}
    files {"src/**.h", "src/**.cpp", "src/**.c", "src/**.hpp"}
    links {"TermDLL"}
    

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"
        libdirs {"../bin/Debug"}
        

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
        libdirs {"../bin/Release"}