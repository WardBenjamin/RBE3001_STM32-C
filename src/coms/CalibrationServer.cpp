/*
 * CalibrationServer.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: mjlaks
 */

#include "CalibrationServer.h"

void CalibrationServer::event(float* packet)
{


	encoder1Value = packet[0];
	encoder2Value = packet[1];
	encoder3Value = packet[2];

    uint8_t* buff = (uint8_t*) packet;

    // Re-initialize the packet to all zeros
    for (int i = 0; i < 60; i++)
        buff[i] = 0;

}


