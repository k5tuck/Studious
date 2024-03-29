workspace "Studious"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Studious"
	location "Studious"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/Studious/**.h",
		"%{prj.name}/Studious/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:Windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ST_PLATFORM_WINDOWS",
			"ST_BUILD"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") 
		}

	filter "configurations:Debug"
		defines "ST_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "ST_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "ST_DIST"
		optimize "On"
	
	filter {"system:windows", "configurations:Release"}
		buildoptions "/MT"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Studious/vendor/spdlog/include",
		"Studious/"
	}

	links
	{
		"Studious"
	}

	filter "system:Windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ST_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ST_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "ST_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "ST_DIST"
		optimize "On"
	
	filter {"system:windows", "configurations:Release"}
		buildoptions "/MT"