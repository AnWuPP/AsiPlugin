#pragma once
#include "RakHook/rakhook.hpp"
#include "RakNet/StringCompressor.h"
#include "RakNet/PacketEnumerations.h"

class PlaginRPC {
public:
    bool onServerMessage(unsigned char& id, RakNet::BitStream* bs);
};