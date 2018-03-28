#include "ServoControl.h"

#ifndef ROUTETHREE_H
#define ROUTETHREE_H

void routeThree()
{
	turnMotorOn();
	for(int i=0; i<5; i++) 
	{
	   for(int pos = 0; pos < 180; pos+=10)  
	   {                                   
	       servoFront.write(pos);        
	       delay(50);                 
	   }
	   forwardRunAtSpeedWithTime(0, 5000);
	   for(int pos = 180; pos>=1; pos-=10) 
	   {                                
	       servoFront.write(pos);        
	       delay(50);                 
	   }
	}
	servoFront.write(70);
	while(1)
	{
		detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
	}
}

#endif