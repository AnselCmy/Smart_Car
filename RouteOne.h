#include "DetectDirection.h"
#include "Light.h"

#ifndef ROUTEONE_H
#define ROUTEONE_H

void turnRight90()
{
    turnRightWithTime(7300);
}

void turnRight180()
{
    turnRightWithTime(13000);
}

int ifHighBidgeStart()
{
    int ultraVal = getUltraVal();
    printf("%d， %d\n", bridgeCnt, ultraVal);
    if(ultraVal <= 7)
    {
        bridgeCnt++;
        // when get the signal of ultra turn on the light
        turnLightOn();
        delay(10);
        turnLightDown();
        // delay 
        detectDirectionWithTime(0, 300);
    }
    if(bridgeCnt == 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void routeOne()
{
    getSensorVal(sensorVal);
    int crossCnt = 0;
    // int highBridgeParam = 1350;
    int highBridgeParam = 3250;
    int i = 0;
    // before first cross
    while(!ifHighBidgeStart())
    {
        detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    }
    // highBridge START
    detectDirectionWithTime(1, highBridgeParam);
    stopRunWithTime(100);
    // turn right 90
    turnMotorDown();
    turnRight90();
    stopRunWithTime(100);
    forwardRunAtSpeedWithTime(0, 10000);
    forwardRunAtSpeedWithTime(0, 10000);
    forwardRunAtSpeedWithTime(0, 10000);
    forwardRunAtSpeedWithTime(0, 5000);
    // turn right 180
    turnMotorDown();
    stopRunWithTime(100);
    turnRight180();
    stopRunWithTime(100);
    forwardRunAtSpeedWithTime(0, 10000);
    forwardRunAtSpeedWithTime(0, 10000);
    forwardRunAtSpeedWithTime(0, 10000);
    turnMotorDown();
    stopRunWithTime(100);
    turnRight90();
    stopRunWithTime(100);
    while(!(sensorVal[sensorFLL] > 200 && sensorVal[sensorFRR] > 200))
    {
        detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    }
    // highBridge END
    while(!(sensorVal[sensorFLL] < 200 && sensorVal[sensorFRR] < 200))
    {
        detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    }
    // at the second cross 
    turnRight90();
    while(1)
    {
        detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    }
}

#endif