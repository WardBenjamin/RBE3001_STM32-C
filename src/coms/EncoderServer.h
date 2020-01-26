/**
 * @file EncoderServer.h
 * @brief EncoderServer for the RBE3001 Lab 1 Pre-Lab
 * Created on: Jan 21, 2020
 * Author: michaellaks
 * @section RBE3001 - Nucleo Firmware - EncoderServer
 *
 * Instructions
 * ------------
 * This class implements a communication server that returns an empty packet
 * (all zeros) to the high-level Matlab control code.
 *
 */
#ifndef ENCODERSERVER_H_
#define ENCODERSERVER_H_
#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath> // std::abs
#define ENCODER_SERVER_ID 03 // identifier for this server
/**
 * @brief Class through HID sends an empty packet to the High Level Matlab code
 * Extends the `PacketEventAbstract' class.
 */
class EncoderServer: public PacketEventAbstract
{
 // Packet ID needs to be set
public:
 EncoderServer () : PacketEventAbstract(ENCODER_SERVER_ID){};
 // This method is called every time a packet from MATLAB is received
 // via HID
 void event(float * buffer);
};
#endif /* ENCODERSERVER_H_ */
