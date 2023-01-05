#include "Plugin.h"

Plugin::Plugin() {
    using namespace std::placeholders;
    hookCTimerUpdate.set_cb(std::bind(&Plugin::mainloop, this, _1));
	hookCTimerUpdate.install();
}
Plugin::~Plugin() {
    hookCTimerUpdate.remove();
}

void Plugin::mainloop(const decltype(hookCTimerUpdate)& hook) {
    static bool inited = false;
    if (!inited && samp::RefChat() != nullptr && rakhook::initialize()) {
        using namespace std::placeholders;
        samp::RefChat()->AddMessage(0xFFFFFFFF, "Plugin loaded");
        StringCompressor::AddReference();
        rakhook::on_receive_rpc += std::bind(&PluginEvents::onServerMessage, rpc, _1, _2);
        inited = true;
    }
}
