workspace "Almond"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Almond"
    location "Almond"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AL_PLATFORM_WINDOWS",
            "AL_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "AL_DEBUG"
        symbols "On"
   
    filter "configurations:Release"
        defines "AL_RELEASE"
        optimize "On"
   
    filter "configurations:Dist"
        defines "AL_DIST"
        optimize "On"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Almond/vendor/spdlog/include",
        "Almond/src"
    }

    links
    {
        "Almond"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AL_DEBUG"
        symbols "On"
   
    filter "configurations:Release"
        defines "AL_RELEASE"
        optimize "On"
   
    filter "configurations:Dist"
        defines "AL_DIST"
        optimize "On"