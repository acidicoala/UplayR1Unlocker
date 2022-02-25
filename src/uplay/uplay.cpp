#include "uplay.hpp"

#define GET_ORIGINAL_FUNCTION(FUNC) \
    static const auto FUNC##_o = hook::get_original_function( \
        unlocker::is_hook_mode, unlocker::original_library, #FUNC, FUNC \
    );

// Used as: cmp eax, 1
// Therefore, we must return int rather than a bool
DLL_EXPORT(uint32_t) UPLAY_USER_IsOwned(const int aUplayId) {
    GET_ORIGINAL_FUNCTION(UPLAY_USER_IsOwned)
    const auto result = UPLAY_USER_IsOwned_o(aUplayId);

    const auto isOwned = not config.blacklist.contains(aUplayId);

    logger->debug(
        "{} -> aUplayId: {},\tisOwned: {}\t(legitimately owned: {})",
        __func__, aUplayId, isOwned, static_cast<bool>(result)
    );

    return static_cast<bool>(isOwned); // implicit type conversion
}

DLL_EXPORT(PCSTR) UPLAY_INSTALLER_GetLanguageUtf8() {
    logger->debug(__func__);

    if (config.lang == "default") {
        GET_ORIGINAL_FUNCTION(UPLAY_INSTALLER_GetLanguageUtf8)
        const auto result = UPLAY_INSTALLER_GetLanguageUtf8_o();

        logger->info("🔤 {} -> responding with original lang: {}", __func__, result);
        return result;
    } else {
        logger->info("🔤 {} -> responding with configured lang: {}", __func__, config.lang);
        return config.lang.c_str();
    }
}
