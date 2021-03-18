#include "pch.h"
#include "Config.h"

using nlohmann::json;

// Source: https://stackoverflow.com/a/54394658/3805929
#define GET(j, key) this->key = j[#key].get<decltype(key)>()

constexpr auto CONFIG_PATH = "UplayR1Unlocker.jsonc";

Config::Config(HMODULE hModule)
{
	auto path = getDllDir(hModule) / CONFIG_PATH;
	std::ifstream ifs(path, std::ifstream::in);

	if(!ifs.good())
	{
		// MessageBox(NULL, path.c_str(), L"Config not found at: ", MB_ICONERROR);
		return;
	}

	try
	{
		auto j = json::parse(ifs, nullptr, true, true);

		GET(j, log_level);
		GET(j, lang);
		GET(j, blacklist);
	} catch(json::exception e)
	{
		MessageBoxA(NULL, e.what(), "Error parsing config file", MB_ICONERROR);
		return;
	}
}

void Config::init(HMODULE hModule)
{
	if(config != nullptr)
		return;

	config = new Config(hModule);
}

Config* config = nullptr;
