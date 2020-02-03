/*
 * CalibrationServer.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: mjlaks
 */

#include "CalibrationServer.h"


void CalibrationServer::event(float* packet)
{

	// NOTE: Wakeup gate necessary since this status modifies system behavior
	if(!packet[14])
		return;

	//Reads back encoder values from last status command
	float encoder1Value = packet[0];
	float encoder2Value = packet[1];
	float encoder3Value = packet[2];

	printf("Old: %f, %f, %f\r\n", homePositions[0], homePositions[1], homePositions[2]);

	// Hard coded origin + current encoder value gives offset
	homePositions[0] = homePositions[0] + encoder1Value;
	homePositions[1] = homePositions[1] + encoder2Value;
	homePositions[2] = homePositions[2] + encoder3Value;
//
//	printf("Joint 1 new home: %f\r\n", myPidObjects[0]->GetPIDPosition() - j0);
	printf("New: %f, %f, %f\r\n", homePositions[0], homePositions[1], homePositions[2]);

	this->myPidObjects[0]->pidReset(0);
	this->myPidObjects[1]->pidReset(0);
	this->myPidObjects[2]->pidReset(0);




	// Typecast the packet
    uint8_t* buff = (uint8_t*) packet;

    // Re-initialize the packet to all zeros
    for (int i = 0; i < 60; i++)
        buff[i] = 0;

    // Sends back the offsets to Matlab
    packet[0] = homePositions[0];
    packet[1] = homePositions[1];
    packet[2] = homePositions[2];
}



