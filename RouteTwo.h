#include "DetectDirection.h"
#include "ServoControl.h"
#include "Sensor.h"

#ifndef ROUTETWO_H
#define ROUTETWO_H

// void routeTwo() 
// {
// 	// turnMotorOn();
//     // servoFront.write(90);
// 	// while(1)
// 	// {
// 	// 	detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
// 	// }
// 	turnMotorOn();
//     servoFront.write(100);
//     forwardRunAtSpeedWithTime(0, 10000);
//     detectDirectionWithTime(0, 580);
//     servoFront.write(180);
//     detectDirectionWithTime(0, 300);
//     servoFront.write(100);
//     forwardRunAtSpeedWithTime(0, 30000);
//     // stopRun();
//     turnLightOn();
//     while(1)
//     {
//     	detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
//     }
// }

void routeTwo()
{
	turnMotorOn();
	servoFront.write(90);
	while(1)
	{
		detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
	}
}

#if 0
void routeTwo()
{
	forwardRunAtSpeedWithTime(0, 10000);
	forwardRunAtSpeedWithTime(0, 10000);
	forwardRunAtSpeedWithTime(0, 10000); 
	forwardRunAtSpeedWithTime(0, 10000); 
	forwardRunAtSpeedWithTime(0, 10000); 
	forwardRunAtSpeedWithTime(0, 10000); 
	forwardRunAtSpeedWithTime(0, 5000);
	turnLightOn();
	delay(100);
	turnLightDown();
	detectDirectionWithTime(1, 1500);
	turnLightOn();
	delay(100);
	turnLightDown();
	forwardRunAtSpeedWithTime(0, 10000);
	forwardRunAtSpeedWithTime(0, 10000); 
	forwardRunAtSpeedWithTime(0, 10000); 
	forwardRunAtSpeedWithTime(0, 10000);
	forwardRunAtSpeedWithTime(0, 5000);
	turnLightOn();
	delay(100);
	turnLightDown();
	while(1){
		detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
	}
}
#endif

#endif