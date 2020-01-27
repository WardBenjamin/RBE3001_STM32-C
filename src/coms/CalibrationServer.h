/*
 * CalibrationServer.h
 *
 *  Created on: Jan 27, 2020
 *      Author: mjlaks
 *
 *      This server is used to continually update the home position
 *      of the robot for use in calibration
 */

#ifndef SRC_COMS_CALIBRATIONSERVER_H_
#define SRC_COMS_CALIBRATIONSERVER_H_

#include <PacketEvent.h>

#define CALIBRATION_SERVER_ID 04 //Server ID Number

float encoder1Value;
float encoder2Value;
float encoder3Value;


class CalibrationServer
{

public:

	CalibrationServer (float * home) : PacketEventAbstract(CALIBRATION_SERVER_ID){};

	void event(float * buffer);

};

#endif /* SRC_COMS_CALIBRATIONSERVER_H_ */
