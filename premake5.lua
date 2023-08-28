workspace "Blender"
    architecture "universal"
    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputdirectory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Blender"
    kind "ConsoleApp"
    language "C"

    targetdir("bin/" .. outputdirectory .. "/%{prj.name}")
    objdir("bin-int/" .. outputdirectory .. "/%{prj.name}")

    files
    {
        "source/**.c",
        "intern/**.c"
    }

    includedirs
    {
        "source/**",
        "intern/**"
    }

    externalincludedirs
    {
        "/usr/local/include"
    }

    filter "system:macosx"
        cppdialect "C++17"

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {NDEBUG}
        optimize "On"