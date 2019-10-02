workspace "TermDLL"
    configurations {"Release", "Debug"}
project "TermDLL"
    kind "SharedLib"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {"src/", "src/include"}
    files {"src/**.h", "src/**.cpp", "src/**.c", "src/**.hpp"}
    defines {"TERMDLL_EXPORT"}
    

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"