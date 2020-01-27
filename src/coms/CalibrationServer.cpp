/*
 * CalibrationServer.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: mjlaks
 */

#include "CalibrationServer.h"

void CalibrationServer::event(float* packet)
{

	float encoder1Value = packet[0];
	float encoder2Value = packet[1];
	float encoder3Value = packet[2];

	homeArray[0] = encoder1Value;
	homeArray[1] = encoder2Value;
	homeArray[2] = encoder3Value;


    uint8_t* buff = (uint8_t*) packet;

    // Re-initialize the packet to all zeros
    for (int i = 0; i < 60; i++)
        buff[i] = 0;

    packet[0] = encoder1Value;
    packet[1] = encoder2Value;
    packet[2] = encoder3Value;

}


