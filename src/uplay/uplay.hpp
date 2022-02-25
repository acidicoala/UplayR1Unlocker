#pragma once

#include "unlocker/unlocker.hpp"

#define DLL_EXPORT(TYPE) extern "C" _declspec(dllexport) TYPE

using namespace unlocker;

DLL_EXPORT(uint32_t) UPLAY_USER_IsOwned(int aUplayId);

DLL_EXPORT(PCSTR) UPLAY_INSTALLER_GetLanguageUtf8();
