#pragma once

#include <PacketEvent.h>
#include <cmath>        // std::abs

#define STATUS_SERVER_ID 03

class StatusServer: public PacketEventAbstract {

public:
    // Packet ID needs to be set
    StatusServer () : PacketEventAbstract(STATUS_SERVER_ID) {}

    // User function to be called when a packet comes in
    // Buffer contains data from the packet coming in at the start of the function
    // User data is written into the buffer to send it back
    void event(float * buffer);
};
