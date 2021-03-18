#include "pch.h"
#include "Logger.h"
#include "Config.h"

constexpr auto LOG_PATH = "UplayR1Unlocker.log";

shared_ptr<spdlog::logger> logger = spdlog::null_logger_mt("null");

void Logger::init()
{
	if(config.log_level != "off")
	{
		logger = spdlog::basic_logger_mt("default", LOG_PATH, true);
		logger->set_pattern("[%H:%M:%S.%e] [%l]\t%v");
		logger->set_level(spdlog::level::from_str(config.log_level));
		logger->flush_on(spdlog::level::debug);
	}
}
