#pragma once

#ifdef ST_PLATFORM_WINDOWS
	#ifdef ST_BUILD
		#define Studious_API __declspec(dllexport)
	#else
		#define Studious_API __declspec(dllimport)
	#endif
#else
	#error Windows is currently the Only Supported Platform!
#endif