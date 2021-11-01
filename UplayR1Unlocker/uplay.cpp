#include "pch.h"
#include "uplay.h"
#include "Logger.h"
#include "Config.h"

HMODULE originalDLL = nullptr;

void init(const HMODULE hModule)
{
	Config::init(hModule);
	Logger::init(hModule);

	logger->info("Uplay R1 Unlocker v{}", VERSION);

	const auto originalPath = getDllDir(hModule) / ORIG_DLL;
	originalDLL = LoadLibrary(originalPath.c_str());
	if(originalDLL)
	{
		logger->info(L"Successfully loaded original DLL: {}", ORIG_DLL);
	}
	else
	{
		const auto message = fmt::format(L"Failed to load original DLL: {}. Error code: {}", originalPath.c_str(), GetLastError());
		logger->error(message);
		MessageBox(nullptr, message.c_str(), L"Error during initialization", MB_ICONERROR | MB_OK);
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
EXPORT int UPLAY_USER_IsOwned(const int aUplayId)
{
	GET_PROXY_FUNC(UPLAY_USER_IsOwned)
	const auto result = proxyFunc(aUplayId);

	const auto isOwned = !vectorContains(config->blacklist, aUplayId);

	logger->info(
		"UPLAY_USER_IsOwned -> aUplayId: {},\tisOwned: {}\t(legitimately owned: {})",
		aUplayId, isOwned, static_cast<bool>(result)
	);

	return isOwned; // implicit type conversion
}

EXPORT PCSTR UPLAY_INSTALLER_GetLanguageUtf8()
{
	if(config->lang == "default")
	{
		GET_PROXY_FUNC(UPLAY_INSTALLER_GetLanguageUtf8)
		const auto result = proxyFunc();
		logger->info("UPLAY_INSTALLER_GetLanguageUtf8 -> original lang: {}", result);
		return result;
	}
	else
	{
		logger->info("UPLAY_INSTALLER_GetLanguageUtf8 -> modified lang: {}", config->lang);
		return config->lang.c_str();
	}
}
