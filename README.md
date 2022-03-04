# 🐨 Uplay R1 Unlocker 🔓

Legit DLC Unlocker for Ubisoft Connect (R1)

## [Official forum topic]

For user-friendly description, consult the official forum thread. This document is meant for developers.

[Official forum topic]: https://cs.rin.ru/forum/viewtopic.php?p=2337576#p2337576

## ⚙ Configuration

UplayR1Unlocker does not require any manual configuration. By default, it uses most reasonable options and tries to unlock all DLCs that it can. However, there might be circumstances in which you need more custom-tailored behaviour. In this case you can use a configuration file [`UplayR1Unlocker.json`](./res/UplayR1Unlocker.jsonc) that you can find in this repository. To use it, simply place it alongside the unlocker DLL. It will be read upon each launch of a game. Configuration file itself is optional, but options within the file are not. In the absence of the config file, default value specified below will be used.

The description of each available option is presented below:

- `logging`: Enables or disables logging into a _UplayR1Unlocker.log_ file. Default: `false`.
- `lang`: String that overrides game language if it is not set to `default`. Default: `default`.
- `hook_loader`: Specifies which DLL to hook. When `true`, the unlocker hooks `uplay_r1_loader(64).dll`. When `false`, it hooks `uplay_r1(64).dll`. Default: `false`.
- `blacklist`: A list of IDs to keep locked. Default: `[]` (empty list).

## 👋 Acknowledgements

This project makes use of the following open source projects:

- [JSON for Modern C++](https://github.com/nlohmann/json)
- [PolyHook 2.0](https://github.com/stevemk14ebr/PolyHook_2_0)
- [spdlog](https://github.com/gabime/spdlog)

## 📄 License

This software is licensed under [Zero Clause BSD] license, terms of which are available in [LICENSE.txt]


[Zero Clause BSD]: https://choosealicense.com/licenses/0bsd/

[LICENSE.txt]: ./LICENSE.txt
