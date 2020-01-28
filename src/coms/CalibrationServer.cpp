/*
 * CalibrationServer.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: mjlaks
 */

#include "CalibrationServer.h"


void CalibrationServer::event(float* packet)
{

	//Reads back encoder values from last status command
	float encoder1Value = packet[0];
	float encoder2Value = packet[1];
	float encoder3Value = packet[2];



	//hard coded origin - current encoder value gives offset
	homeArray[0] = homeArray[0] - encoder1Value;
	homeArray[1] = homeArray[1] - encoder2Value;
	homeArray[2] = homeArray[2] - encoder3Value;




	//typecast the packet
    uint8_t* buff = (uint8_t*) packet;

    // Re-initialize the packet to all zeros
    for (int i = 0; i < 60; i++)
        buff[i] = 0;

    //sends back the offsets to matlab
    packet[0] = homeArray[0];
    packet[1] = homeArray[1];
    packet[2] = homeArray[2];
    //packet[3] = encoder1Value;
//    ///packet[0] = 10;
//    packet[1] = 11;
//    packet[2] = 12;
    //packet[1] = offsetArray[1];
    //packet[2] = offsetArray[2];
    //packet[4] = 10;
    //packet[5] = test2;

}



