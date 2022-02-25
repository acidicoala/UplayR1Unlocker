#pragma once

#include "koalabox/koalabox.hpp"

namespace unlocker {
    using namespace koalabox;

    typedef uint32_t ProductID;

    struct Config {
        bool logging = false;
        String lang = "default";
        bool hook_loader = false;
        Set<ProductID> blacklist;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Config, logging, lang, hook_loader, blacklist)
    };

    extern Config config;

    extern HMODULE original_library;

    extern bool is_hook_mode;

    void init(const HMODULE& loader_library);

    void shutdown();

}
