#pragma once

//Implementation of the mappers for Windows.

#ifdef SI_PLATFORM_WINDOWS
	#ifdef SI_BUILD_DLL
		#define SEMPERIDEM_API __declspec(dllexport)
	#else
		#define SEMPERIDEM_API __declspec(dllimport)
	#endif
#else
	#error Semperidem only supports Windows at the moment!
#endif

