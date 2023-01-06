#pragma once

#include "RakNet/BitStream.h"
#include <string>

class PluginRPC {
public:
    bool onServerMessage(unsigned char& id, RakNet::BitStream* bs);
};