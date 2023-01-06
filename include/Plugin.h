#pragma once
#include "kthook/kthook.hpp"
#include "sampapi/CChat.h"
#include "Rpc.h"

using CTimerProto = void( __cdecl* )();
namespace samp = sampapi::v037r1;

class Plugin {
public:
	Plugin();
	virtual ~Plugin();
private:
    PlaginRPC RPC;
    kthook::kthook_simple<CTimerProto> hookCTimerUpdate{ reinterpret_cast<void*>(0x561B10) };
    void mainloop(const decltype(hookCTimerUpdate)& hook);
};