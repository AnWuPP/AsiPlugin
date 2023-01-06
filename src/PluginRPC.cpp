#include "PluginRPC.h"

template <typename T>
std::string readWithSize(RakNet::BitStream* bs) {
    T size;
    if (!bs->Read(size))
        return {};
    std::string str(size, '\0');
    bs->Read(str.data(), size);
    return str;
}

template <typename T>
void writeWithSize(RakNet::BitStream* bs, std::string_view str) {
    T size = static_cast<T>(str.size());
    bs->Write(size);
    bs->Write(str.data(), size);
}

bool PlaginRPC::onServerMessage(unsigned char& id, RakNet::BitStream* bs) {
    if (id != 93) // RPC_ClientMessage
        return true;
    unsigned long color;
    std::string   msg;

    // read
    bs->Read(color);
    msg = readWithSize<unsigned int>(bs);

    msg = "[HK] " + msg;

    // write
    bs->Reset();
    bs->Write(color);
    writeWithSize<unsigned int>(bs, msg);
    return true;
}