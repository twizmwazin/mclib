#ifndef PACKETS_PACKET_DISPATCHER_H_
#define PACKETS_PACKET_DISPATCHER_H_

#include "Packet.h"
#include <map>
#include <vector>
#include "../Protocol.h"

namespace Minecraft {
namespace Packets {

class PacketHandler;

class PacketDispatcher {
private:
    typedef s64 PacketId;
    typedef std::pair<Minecraft::Protocol::State, PacketId> PacketType;
    std::map<PacketType, std::vector<PacketHandler*>> m_Handlers;

public:
    void Dispatch(Packet* packet);

    void RegisterHandler(Minecraft::Protocol::State protocolState, PacketId id, PacketHandler* handler);
    void UnregisterHandler(Minecraft::Protocol::State protocolState, PacketId id, PacketHandler* handler);
    void UnregisterHandler(PacketHandler* handler);
};

} // ns Packets
} // ns Minecraft

#endif
