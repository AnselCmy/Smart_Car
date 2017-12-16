#include "Define.h"
#include "GlobalVar.h"
#include "MotorControl.h"

#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H 

/*
 * Control Motor At Left And Right
 * speed: 0~89, 0 at the fastest speed
 * dir  : FOREARD or BACKWARD
 */
void leftRunAtSpeed (int speed, int dir) 
{
    int offset = 0;
    if (dir == BACKWARD) 
    {
        speed = 180 - speed;
    }
    servoLF.write(speed + offset);
    servoLB.write(speed + offset);
}

void rightRunAtSpeed (int speed, int dir) 
{
    
    int offset = 0;
    if (dir == FORWARD) 
    {
        speed = 180 - speed;
    }
    servoRF.write(speed);
    servoRB.write(speed);
}

/*
 * Forward
 * speed: 0~90, 0 at the fastest speed
 */
void forwardRunAtSpeed (int speed) 
{ 
    leftRunAtSpeed(speed, FORWARD);
    rightRunAtSpeed(speed, FORWARD);
}

void forwardRunAtSpeedWithTime (int speed, int sec) 
{ 
    turnMotorOn();
    for(int i = 0; i<sec; i++)
    {
        leftRunAtSpeed(speed, FORWARD);
        rightRunAtSpeed(speed, FORWARD);
    }
}

/*
 * Turn
 */
void turnRight() 
{
    leftRunAtSpeed(0, FORWARD);
    rightRunAtSpeed(0, BACKWARD);
}

void turnLeft() 
{
    leftRunAtSpeed(0, BACKWARD);
    rightRunAtSpeed(0, FORWARD);
}

void turnRightWithTime(int sec)
{
    for(int i = 0; i < sec; i++)
    {
        turnRight();
    }
}

void turnLeftWithTime(int sec)
{
    for(int i = 0; i < sec; i++)
    {
        turnLeft();
    }
}

/*
 * Tune
 */
void tuneToLeft()
{
    rightRunAtSpeed(0, FORWARD);
    leftRunAtSpeed(75, FORWARD);
}

void tuneToRight()
{
    rightRunAtSpeed(70, FORWARD);
    leftRunAtSpeed(0, FORWARD);
}

void onlyUseRight()
{
    rightRunAtSpeed(0, FORWARD);
    servoLF.write(base_servoLF);
    servoLB.write(base_servoLB);
}

void onlyUseLeft()
{
    leftRunAtSpeed(0, FORWARD);
    servoRF.write(base_servoRF);
    servoRB.write(base_servoLB);
}

/*
 * Stop
 */
void stopRun()
{
    servoLF.write(base_servoLF);
    servoLB.write(base_servoLB);
    servoRF.write(base_servoRF);
    servoRB.write(base_servoLB);
}

void stopRunWithTime(int sec)
{
    for(int i = 0; i < sec; i++)
    {
        stopRun();
    }
}


#endif
