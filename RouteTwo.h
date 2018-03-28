#include "DetectDirection.h"
#include "ServoControl.h"
#include "Sensor.h"

#ifndef ROUTETWO_H
#define ROUTETWO_H

void routeTwo()
{
	turnMotorOn();
	servoFront.write(90);
	while(1)
	{
		detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
	}
}

#endif