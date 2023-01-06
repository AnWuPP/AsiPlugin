#include "Plugin.h"
#include <sampapi/CChat.h>
#include <RakHook/rakhook.hpp>
#include <RakNet/StringCompressor.h>

namespace samp = sampapi::v037r1;

Plugin::Plugin(HMODULE hndl) : hModule(hndl) {
    using namespace std::placeholders;
    hookCTimerUpdate.set_cb(std::bind(&Plugin::mainloop, this, _1));
    hookCTimerUpdate.install();
}

void Plugin::mainloop(const decltype(hookCTimerUpdate)& hook) {
    static bool inited = false;
    if (!inited && samp::RefChat() != nullptr && rakhook::initialize()) {
        using namespace std::placeholders;
        samp::RefChat()->AddMessage(0xFFFFFFFF, "Plugin loaded");
        StringCompressor::AddReference();
        rakhook::on_receive_rpc += std::bind(&PluginRPC::onServerMessage, &RPC, _1, _2);
        inited = true;
    }
    return hook.get_trampoline()();
}
