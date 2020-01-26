/*
 * EncoderServer.cpp
 *
 * Created on: Jan 21, 2020
 * Author: michaellaks
 */
#include "EncoderServer.h"
/**
 * @brief This function handles sending a blank packet through HID to MATLAB.
 *
 */
void EncoderServer::event(float * packet)
{
	for (int x = 0; x < 3; x++)
	{
		float hardCode = packet[(x*3)+0];
		float hardCode2 = packet[(x*3)+1];
	}


	uint8_t * buff = (uint8_t *) packet;
	// initialize the packet to all zeros
	for (int i = 0; i < 60; i++) buff[i] = 0;


	packet[1*3] = 21;
	packet[2*3] = 22;
	packet[3*3] = 37;


}
