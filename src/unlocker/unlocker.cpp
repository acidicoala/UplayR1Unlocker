#include "unlocker.hpp"
#include "uplay/uplay.hpp"

#include "koalabox/config_parser/config_parser.hpp"
#include "koalabox/loader/loader.hpp"
#include "koalabox/util/util.hpp"
#include "koalabox/win_util/win_util.hpp"

#include <build_config.h>

#define DETOUR(MODULE, FUNC) \
    hook::detour(MODULE, #FUNC, reinterpret_cast<FunctionPointer>(FUNC));

namespace unlocker {
    Config config = {}; // NOLINT(cert-err58-cpp)

    HMODULE original_library = nullptr;

    bool is_hook_mode = false;

    void init(const HMODULE& self_module) {
        DisableThreadLibraryCalls(self_module);

        const auto self_directory = loader::get_module_dir(self_module);

        config = config_parser::parse<Config>(self_directory / PROJECT_NAME".jsonc", true);

        if (config.logging) {
            logger = file_logger::create(self_directory / PROJECT_NAME".log");
        }

        logger->info("🐨 {} 🔓 v{}", PROJECT_NAME, PROJECT_VERSION);

        const auto module_path = win_util::get_module_file_name(self_module);

        is_hook_mode = hook::is_hook_mode(self_module, ORIGINAL_DLL);

        if (is_hook_mode) {
            logger->info("🪝 Detected hook mode");

            dll_monitor::init(
                config.hook_loader ? ORIGINAL_DLL : STORE_DLL,
                [](const HMODULE& library) {
                    hook::init();

                    original_library = library;

                    DETOUR(library, UPLAY_USER_IsOwned)

                    if (config.lang != "default") {
                        DETOUR(library, UPLAY_INSTALLER_GetLanguageUtf8)
                    }

                    logger->info("Hooking complete");

                    dll_monitor::shutdown();
                }
            );
        } else {
            logger->info("🔀 Detected proxy mode");

            original_library = loader::load_original_library(self_directory, ORIGINAL_DLL);
        }

        logger->info("🚀 Initialization complete");
    }

    void shutdown() {
        if (not is_hook_mode) {
            win_util::free_library(original_library);
        }

        logger->info("💀 Shutdown complete");
    }

}

