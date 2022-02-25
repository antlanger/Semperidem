#pragma once

#ifdef SI_PLATFORM_WINDOWS
	#ifdef SI_BUILD_DLL
		#define SEMPERIDEM_API __declspec(dllexport)
	#else
		#define SEMPERIDEM_API __declspec(dllimport)
	#endif
#else
	#error Semperidem only supports Windows at the moment!
#endif

//Mappers so we don't have to include everytime __declspec(dllexport/import)
