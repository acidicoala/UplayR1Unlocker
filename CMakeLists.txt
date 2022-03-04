cmake_minimum_required(VERSION 3.21)

include(KoalaBox/KoalaBox.cmake)

configure_globals(KoalaBox)

project(UplayR1Unlocker VERSION 2.0.0)

set_32_and_64(ORIGINAL_DLL uplay_r1_loader uplay_r1_loader64)
set_32_and_64(STORE_DLL uplay_r1 uplay_r164)

configure_version_resource("https://github.com/acidicoala/UplayR1Unlocker")

configure_exports_generator()
configure_linker_exports(
    false
    "${ORIGINAL_DLL}_o"
    "${RES_DIR}/${STORE_DLL}.dll"
    "${SRC_DIR}/uplay"
    "${SRC_DIR}/uplay/uplay.cpp"
)

configure_build_config(extra_build_config)

configure_library(
    SHARED

    ${SRC_DIR}/unlocker/unlocker.cpp
    ${SRC_DIR}/uplay/uplay.cpp
    ${SRC_DIR}/main.cpp

    ${KOALABOX_SRC_DIR}/koalabox/dll_monitor/dll_monitor.cpp
    ${KOALABOX_SRC_DIR}/koalabox/hook/hook.cpp
    ${KOALABOX_SRC_DIR}/koalabox/loader/loader.cpp
    ${KOALABOX_SRC_DIR}/koalabox/file_logger/file_logger.cpp
    ${KOALABOX_SRC_DIR}/koalabox/util/util.cpp
    ${KOALABOX_SRC_DIR}/koalabox/win_util/win_util.cpp

    ${LINKER_EXPORTS}
)

configure_precompile_headers(${CMAKE_PROJECT_NAME} ${SRC_DIR}/pch.hpp)

configure_output_name(${ORIGINAL_DLL})

configure_include_directories()

configure_dependencies(${CMAKE_PROJECT_NAME} PolyHook_2 nlohmann_json spdlog)
