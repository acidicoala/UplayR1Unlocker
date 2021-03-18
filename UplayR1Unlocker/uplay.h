#pragma once

#define EXPORT extern "C" _declspec(dllexport)

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);

#ifdef _WIN64
constexpr auto ORIG_DLL = L"uplay_r1_loader64_o.dll";
#else
constexpr auto ORIG_DLL = L"uplay_r1_loader_o.dll";
#endif


void init(HMODULE hModule);
void shutdown();
