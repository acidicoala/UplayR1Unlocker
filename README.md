# 🐨 Uplay R1 Unlocker 🔓

Legit DLC Unlocker for Ubisoft Connect (R1)

## [Official forum topic]

For user-friendly description, consult the official forum thread. This document is meant for developers.

[Official forum topic]: https://cs.rin.ru/forum/viewtopic.php?p=2337576#p2337576

## ⚙ Configuration

UplayR1Unlocker does not require any manual configuration. By default, it uses most reasonable options and tries to unlock all DLCs that it can. However, there might be circumstances in which you need more custom-tailored behaviour. In this case you can use a configuration file `UplayR1Unlocker.json` that you can find in the release zip. To use it, simply place it alongside the unlocker DLL. It will be read upon each launch of a game. Configuration file itself is optional, but options within the file are not. In the absence of the config file, default value specified below will be used.

The description of each available option is presented below:

- `logging`: Enables or disables logging into a _UplayR1Unlocker.log_ file. Default: `false`.
- `lang`: Enables or disables interception of EOS SDK logs. Can cause issues when enabled in *hook* mode. Default: `false`.
- `eos_logging`: Enables or disables interception of EOS SDK logs. Enabling this option can cause issues in *hook* mode. Default: `false`.
- `block_metrics`: Blocks reporting of analytics and usage metrics by the game to Epic Online Services. Metrics sent by EOS SDK itself remain unaffected. Default: `false`.
- `catalog_items`: Options in this object specify behaviour when games use `EOS_Ecom_QueryOwnership` function.
    - `unlock_all`: Controls if all items should be automatically unlocked. Default: `true`.
    - `override`: Specifies items ids¹ that override the behaviour of `unlock_all`. If `unlock_all` is _true_, then items ids in this array will be locked. If `unlock_all` is _false_, then items ids in this array will be unlocked. Default: `[]` (empty array).
- `entitlements`: Options in this object specify behaviour when games use `EOS_Ecom_QueryEntitlements` function.
    - `unlock_all`: Controls if all entitlements that were requested by their IDs should be automatically unlocked. Default: `true`.
    - `auto_inject`: Controls if ScreamAPI should fetch from online database a list of all available entitlement IDs, when a game doesn't provide them itself. Default: `true`.
    - `inject`: Specifies which entitlement ids¹ to inject when a game asks for a list of entitlements that a user owns. Default: `[]` (empty array).

## 👋 Acknowledgements

This project makes use of the following open source projects:

- [JSON for Modern C++](https://github.com/nlohmann/json)
- [PolyHook 2.0](https://github.com/stevemk14ebr/PolyHook_2_0)
- [spdlog](https://github.com/gabime/spdlog)

## 📄 License

This software is licensed under [Zero Clause BSD] license, terms of which are available in [LICENSE.txt]


[Zero Clause BSD]: https://choosealicense.com/licenses/0bsd/

[LICENSE.txt]: ./LICENSE.txt
