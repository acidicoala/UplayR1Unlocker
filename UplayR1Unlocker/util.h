#pragma once
#include "framework.h"

using std::string;
using std::wstring;
using std::vector;
using std::shared_ptr;
using std::filesystem::absolute;
using std::filesystem::path;

// Source: Polyhook 2
template<typename T>
T FnCast(FARPROC fnToCast, T pFnCastTo)
{
	return (T) fnToCast;
}

template <typename T>
bool vectorContains(vector<T> v, T element)
{
	return std::find(v.begin(), v.end(), element) != v.end();
}

path getDllDir(HMODULE hModule);
