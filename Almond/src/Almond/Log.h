#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Almond {

	class ALMOND_API Log
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

#ifdef AL_DEBUG
	// Core log macros
	#define AL_CORE_TRACE(...) ::Almond::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define AL_CORE_INFO(...)  ::Almond::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define AL_CORE_WARN(...)  ::Almond::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define AL_CORE_ERROR(...) ::Almond::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define AL_CORE_FATAL(...) ::Almond::Log::GetCoreLogger()->fatal(__VA_ARGS__)

	// Client log macros
	#define AL_CLIENT_TRACE(...) ::Almond::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define AL_CLIENT_INFO(...)  ::Almond::Log::GetClientLogger()->info(__VA_ARGS__)
	#define AL_CLIENT_WARN(...)  ::Almond::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define AL_CLIENT_ERROR(...) ::Almond::Log::GetClientLogger()->error(__VA_ARGS__)
	#define AL_CLIENT_FATAL(...) ::Almond::Log::GetClientLogger()->fatal(__VA_ARGS__)
#else
	// Core log macros
	#define AL_CORE_TRACE(...)
	#define AL_CORE_INFO(...)
	#define AL_CORE_WARN(...)
	#define AL_CORE_ERROR(...)
	#define AL_CORE_FATAL(...)

	// Client log macros
	#define AL_CLIENT_TRACE(...)
	#define AL_CLIENT_INFO(...)
	#define AL_CLIENT_WARN(...)
	#define AL_CLIENT_ERROR(...)
	#define AL_CLIENT_FATAL(...)
#endif