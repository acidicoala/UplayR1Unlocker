#include "pch.h"
#include "util.h"
#include "Logger.h"

path getDllDir(HMODULE hModule)
{
	TCHAR name[MAX_PATH];
	auto result = GetModuleFileName(NULL, name, MAX_PATH);

	if(result == NULL)
		logger->error("Failed to get dll path. Error code: {}", GetLastError());

	return path(name).parent_path();
}