/*
 * GripperServer.h
 *
 *  Created on: Feb 21, 2020
 *      Author: mjlaks
 */

#ifndef SRC_COMS_GRIPPERSERVER_H_
#define SRC_COMS_GRIPPERSERVER_H_


#include <PID_Bowler.h>
#include <PacketEvent.h>
#include <Servo.h>
#include "../drivers/MyPid.h"
#include <cmath>              // needed for std::abs
#include <stdio.h>


#define GRIPPER_SERVER_ID 05 //Server ID Number


class GripperServer: public PacketEventAbstract
{
private:



public:

	Servo * myGripperServo;

	GripperServer(Servo* gripperServo) : PacketEventAbstract(GRIPPER_SERVER_ID)
	{
		myGripperServo = gripperServo;
	}

	void event(float * buffer);

};

#endif /* SRC_COMS_GRIPPERSERVER_H_ */
