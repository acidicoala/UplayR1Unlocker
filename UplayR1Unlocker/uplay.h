#pragma once

#define EXPORT extern "C" _declspec(dllexport)

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);

#ifdef _WIN64
#ifdef LOADER
constexpr auto ORIG_DLL = L"uplay_r1_loader64_o.dll";
#else
constexpr auto ORIG_DLL = L"uplay_r164_o.dll";
#endif
#else
#ifdef LOADER
constexpr auto ORIG_DLL = L"uplay_r1_loader_o.dll";
#else
constexpr auto ORIG_DLL = L"uplay_r1_o.dll";
#endif
#endif

constexpr auto VERSION = "1.2.0";

void init(HMODULE hModule);
void shutdown();
