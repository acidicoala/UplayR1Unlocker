#pragma once
#include "util.h"

class Config
{
protected:
	Config(HMODULE hModule);
public:
	string log_level = "off";
	string lang = "default";
	vector<int> blacklist;

	static void init(HMODULE hModule);
};

extern Config* config;
