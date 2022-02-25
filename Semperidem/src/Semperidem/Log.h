#pragma once

#include "memory.h"
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Semperidem
{
	class SEMPERIDEM_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//Core log macros
#define SI_CORE_ERROR(...)   ::Semperidem::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SI_CORE_WARN(...)    ::Semperidem::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SI_CORE_INFO(...)    ::Semperidem::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SI_CORE_TRACE(...)   ::Semperidem::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SI_CORE_FATAL(...)   ::Semperidem::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SI_CLIENT_ERROR(...)   ::Semperidem::Log::GetClientLogger()->error(__VA_ARGS__)
#define SI_CLIENT_WARN(...)    ::Semperidem::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SI_CLIENT_INFO(...)    ::Semperidem::Log::GetClientLogger()->info(__VA_ARGS__)
#define SI_CLIENT_TRACE(...)   ::Semperidem::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SI_CLIENT_FATAL(...)   ::Semperidem::Log::GetClientLogger()->fatal(__VA_ARGS__)