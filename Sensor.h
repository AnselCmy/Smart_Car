#include "Define.h"
#include "GlobalVar.h"

#ifndef SENSOR_H
#define SENSOR_H

int* getSensorVal(int* sensorVal)
{
    int sensor;
    for(sensor = sensorFLL; sensor < sensorNUM; sensor++) 
    {
       sensorVal[sensor] = 0;
    }
    // get the value of each sensors
    int repeatNum = 3;
    int i;
    for(i = 0; i < repeatNum; i++) 
    {
       for(sensor = sensorFLL; sensor < sensorNUM; sensor++) 
       {
           sensorVal[sensor] += analogRead(sensorPin[sensor]);
           if(i == repeatNum - 1) 
           {
               sensorVal[sensor] /= repeatNum;
           }
       }
    }
    return sensorVal;
}

int* getRedVal(int* redVal)
{
    redVal[redL] = 0;
    redVal[redR] = 0;
    int repeatNum = 3;
    int i;
    for(i = 0; i < repeatNum; i++) 
    {
        redVal[redL] += digitalRead(pin_redL);
        redVal[redR] += digitalRead(pin_redR);
        if(i == repeatNum - 1) 
         {
             redVal[redL] /= repeatNum;
             redVal[redR] /= repeatNum;
         }
    }
    return redVal;
}

int getUltraVal(int trig, int echo)
{
    // int repeat = 3;
    // int i = 0;
    // long duration, cm = 0;
    // for(i = 0; i < repeat; i++)
    // {
    //     digitalWrite(trig, LOW);
    //     delayMicroseconds(5);
    //     digitalWrite(trig, HIGH);   
    //     delayMicroseconds(10);
    //     digitalWrite(trig, LOW);
    
    //     duration = pulseIn(echo, HIGH);
    //     cm += duration / 29 / 2;
    // }
    // cm /= repeat;
    // return cm;
    return 0;
}

#endif