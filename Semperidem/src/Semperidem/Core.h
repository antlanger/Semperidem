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

#ifdef HZ_ENABLE_ASSERTS
	#define SI_CLIENT_ASSERT(x, ...) { if(!(x)) { SI_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SI_CORE_ASSERT(x, ...) { if(!(x)) { SI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SI_CLIENT_ASSERT(x, ...)
	#define SI_CORE_ASSERT(x, ...)
#endif

//1 shifted by x spaces, used in Event.h
#define BIT(x) (1 << x)

//For the ImGui events used in ImGuiLayer.cpp
#define SI_BIND_EVENT_FN(fn)(std::bind(&fn, this, std::placeholders::_1))

