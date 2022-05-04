#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory.h>

namespace Studious {

	class Studious_API Log 
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;

	};
}


// Core Loggers
#define ST_CORE_TRACE(...)      ::Studious::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ST_CORE_INFO(...)       ::Studious::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ST_CORE_WARN(...)       ::Studious::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ST_CORE_ERROR(...)      ::Studious::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ST_CORE_FATAL(...)      ::Studious::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Loggers
#define ST_ERROR(...)    ::Studious::Log::GetClientLogger()->error(__VA_ARGS__)
#define ST_WARN(...)     ::Studious::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ST_INFO(...)     ::Studious::Log::GetClientLogger()->info(__VA_ARGS__)
#define ST_TRACE(...)    ::Studious::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ST_FATAL(...)    ::Studious::Log::GetClientLogger()->fatal(__VA_ARGS__)
