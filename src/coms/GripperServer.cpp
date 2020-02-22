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

	float gripperVal = 0.85;

	if (packet[0] == 0) {
		gripperVal = 0.0;
	}

	this->myGripperServo->write(gripperVal);


	// this->myGripperServo->position(12);





	// Typecast the packet
    uint8_t* buff = (uint8_t*) packet;

    // Re-initialize the packet to all zeros
    for (int i = 0; i < 60; i++)
        buff[i] = 0;

    packet[0] = this->myGripperServo->read();

}
