#include "ServoControl.h"
#include "Light.h"

#ifndef ROUTEFOUR_H
#define ROUTEFOUR_H

// void routeFour()
// {
// 	turnMotorOn();
// 	servoFront.write(180);
// 	detectDirectionWithTime(0, 900);
// 	turnLightOn();
// 	// // servoFront.write(70);
// 	forwardRunAtSpeedWithTime(0, 20000); 
// 	forwardRunAtSpeedWithTime(0, 20000);
// 	forwardRunAtSpeedWithTime(0, 10000); 
// 	turnLightDown();
// 	servoFront.write(0);
// 	detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
// 	// stopRun();
// 	while(1){
// 		detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
// 	}
// 	// while(1)
// 	// {
// 	// 	detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
// 	// }
// }

// void routeFour()
// {
// 	turnMotorOn();
// 	servoFront.write(180);
// 	detectDirectionWithTime(0, 800);
// 	turnLightOn();
// 	// // servoFront.write(70);
// 	forwardRunAtSpeedWithTime(0, 20000); 
// 	forwardRunAtSpeedWithTime(0, 20000);
// 	forwardRunAtSpeedWithTime(0, 10000); 
// 	turnLightDown();
// 	servoFront.write(0);
// 	// detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
// 	// stopRun();
// 	while(1){
// 		detectDirectionWithoutMotor(getSensorVal(sensorVal), getRedVal(redVal));
// 	}
// 	// while(1)
// 	// {
// 	// 	detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
// 	// }
// }

void routeFour()
{
	turnMotorOn();
	servoFront.write(180);
	detectDirectionWithTime(0, 3000);
	detectDirectionWithTime(0, 3000);
	detectDirectionWithTime(0, 1000);
	turnLightOn();
	// // servoFront.write(70);
	forwardRunAtSpeedWithTime(0, 20000); 
	forwardRunAtSpeedWithTime(0, 20000);
	forwardRunAtSpeedWithTime(0, 5000); 
	turnLightDown();
	servoFront.write(0);
	// detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
	// stopRun();
	while(1){
		detectDirectionWithoutMotor(getSensorVal(sensorVal), getRedVal(redVal));
	}
	// while(1)
	// {
	// 	detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
	// }
}

#endif