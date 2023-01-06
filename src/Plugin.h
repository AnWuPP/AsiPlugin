#pragma once

#include "PluginRPC.h"
#include <RakHook/rakhook.hpp>
#include <RakNet/StringCompressor.h>
#include <kthook/kthook.hpp>

using CTimerProto = void( __cdecl* )();

class Plugin {
public:
    Plugin() = delete;
	Plugin(HMODULE hModule);
    HMODULE hModule;
private:
    PluginRPC RPC;
    kthook::kthook_simple<CTimerProto> hookCTimerUpdate{ reinterpret_cast<void*>(0x561B10) };
    void mainloop(const decltype(hookCTimerUpdate)& hook);
};