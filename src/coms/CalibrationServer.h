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

#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>              // needed for std::abs


#define CALIBRATION_SERVER_ID 04 //Server ID Number



//float encoder1Value;
//float encoder2Value;
//float encoder3Value;

class CalibrationServer: public PacketEventAbstract
{
private:
	float * homePositions;

public:
	CalibrationServer(float * homePositions) : PacketEventAbstract(CALIBRATION_SERVER_ID)
	{
		this->homePositions = homePositions;
	}

	void event(float * buffer);

};

#endif /* SRC_COMS_CALIBRATIONSERVER_H_ */
