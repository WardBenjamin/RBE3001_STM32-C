/**
 * RBE3001 - Nucleo Firmware
 * See header file for more detail on this class.
 */
#include "StatusServer.h"

/**
 *  @brief This function handles incoming status request packets from MATLAB.
 */  
void StatusServer::event(float* packet)
{
    uint8_t* buff = (uint8_t*) packet;

    // Re-initialize the packet to all zeros
    for (int i = 0; i < 60; i++)
        buff[i] = 0;


    for(int i = 0; i < myPumberOfPidChannels; i++)
    {
       float position = myPidObjects[i]->GetPIDPosition();
       float velocity = myPidObjects[i]->getVelocity();
       packet[i] = position;
       packet[i + 3] = velocity;
    }



    /*packet[0] = 10; // Encoder, Joint 0
    packet[1] = 1; // Encoder, Joint 1
    packet[2] = 2; // Encoder, Joint 2
    packet[3] = 34; // Velocity, Joint 0
    packet[4] = 4; // Velocity, Joint 1
    packet[5] = 5; // Velocity, Joint 2*/
}
