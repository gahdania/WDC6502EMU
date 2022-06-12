newoption {
    trigger = "gfxapi",
    value = "API",
    description = "Choose a particular 3D API for rendering",
    allowed = {
        { "opengl3-glfw",   "OpenGL v3 (using GLFW)" },
        { "opengl2-glfw",   "OpenGL v2 (using GLFW)" },
        { "opengl3-glut",   "OpenGL v3 (using GLUT)" },
        { "opengl2-glut",   "OpenGL v2 (using GLUT)" },
        { "dx11",           "DirectX 11"}
    },
    default = "opengl3-glfw"
}

workspace "Tidel"
    architecture "x86_64"
    startproject "Tidel"
    configurations { "Debug", "Release" }

	flags
	{
		"MultiProcessorCompile"
	}

    links {
        "dl",
        "pthread",
        "GL"
    }

    includedirs {
        "deps/glad/include",
        "deps/glfw/include",
        "deps/imgui",
        "deps/imgui/backends",
        "deps"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "deps/glfw"
	include "deps/glad"
	include "deps/imgui"
group ""

project "Tidel"

	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    links {
        "glad",
        "glfw",
        "ImGui"
    }

    files {
        "src/ui/**.h",
        "src/ui/**.cpp",
        "src/**.h",
        "src/**.cpp"
    }

    filter { "options:gfxapi=opengl3" }
        defines {
            "USING_OPENGL3"
        }

    filter { "options:gfxapi=opengl2" }
        defines {
            "USING_OPENGL2"
        }

    filter { "options:gfxapi=vulkan"}
        defines {
            "GLFW_INCLUDE_NONE",
            "GLFW_INCLUDE_VULKAN"
        }