#include "pch.h"
#include "uplay.h"

BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
	if(ul_reason_for_call == DLL_PROCESS_ATTACH)
		init();
	else if(ul_reason_for_call == DLL_PROCESS_DETACH)
		shutdown();

	return TRUE;
}

