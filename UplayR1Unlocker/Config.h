#pragma once
#include "util.h"

class Config
{
public:
	Config();

	string log_level = "off";
	string lang = "default";
	vector<int> blacklist;
};

extern Config config;
