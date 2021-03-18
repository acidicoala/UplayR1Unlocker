#include "pch.h"
#include "uplay.h"
#include "Logger.h"
#include "Config.h"

HMODULE originalDLL = nullptr;

void init()
{
	Logger::init();
	logger->info("Uplay R1 Unlocker v{}", VERSION);

	originalDLL = LoadLibrary(ORIG_DLL);
	if(originalDLL)
	{
		logger->info(L"Successfully loaded original DLL: {}", ORIG_DLL);
	}
	else
	{
		auto message = fmt::format(L"Failed to load original DLL: {}. Error code: {}", ORIG_DLL, GetLastError());
		logger->error(message);
		MessageBox(NULL, message.c_str(), L"Error during initialization", MB_ICONERROR | MB_OK);
		exit(1);
	}
}


void shutdown()
{
	logger->info("Shutting down");
	FreeLibrary(originalDLL);
}

// Used as: cmp eax, 1
// Therefore, we must return int rather than a bool
EXPORT int UPLAY_USER_IsOwned(int aUplayId)
{
	GET_PROXY_FUNC(UPLAY_USER_IsOwned);
	auto result = proxyFunc(aUplayId);

	auto isOwned = !vectorContains(config.blacklist, aUplayId);

	logger->info(
		"UPLAY_USER_IsOwned -> aUplayId: {},\tisOwned: {}\t(legitimately owned: {})",
		aUplayId, isOwned, (bool) result
	);

	return isOwned; // implicit type conversion
}

EXPORT PCSTR UPLAY_INSTALLER_GetLanguageUtf8()
{
	if(config.lang == "default")
	{
		GET_PROXY_FUNC(UPLAY_INSTALLER_GetLanguageUtf8);
		auto result = proxyFunc();
		logger->info("UPLAY_INSTALLER_GetLanguageUtf8 -> original lang: {}", result);
		return result;
	}
	else
	{
		logger->info("UPLAY_INSTALLER_GetLanguageUtf8 -> modified lang: {}", config.lang);
		return config.lang.c_str();
	}
}
