#include "ServoControl.h"

#ifndef ROUTETHREE_H
#define ROUTETHREE_H

void routeFour()
{
	turnMotorOn();
	servoFront.write(70);
	while(1)
	{
		detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
	}
}

#endif