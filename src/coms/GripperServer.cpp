/*
 * GripperServer.cpp
 *
 *  Created on: Feb 21, 2020
 *      Author: mjlaks
 */

#include "GripperServer.h"

void GripperServer::event(float* packet)
{

	// NOTE: Wakeup gate necessary since this status modifies system behavior
	//if(!packet[14])
	//	return;

	float gripperVal = packet[1];

	//Reads back encoder values from last status command

	//this->myGripperServo->write(gripperVal);

	this->myGripperServo->position(12);





	// Typecast the packet
    uint8_t* buff = (uint8_t*) packet;

    // Re-initialize the packet to all zeros
    for (int i = 0; i < 60; i++)
        buff[i] = 0;

    packet[1] = 10;
    packet[2] = 15;
    packet[3] = gripperVal;
    packet[4] = gripperVal;


}
