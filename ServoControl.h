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

void lfRunAtSpeed(int speed, int dir)
{
   int offset = 0;
    if (dir == BACKWARD) 
    {
        speed = 180 - speed;
    }
    servoLF.write(speed + offset);
}

void lbRunAtSpeed(int speed, int dir)
{
   int offset = 0;
    if (dir == BACKWARD) 
    {
        speed = 180 - speed;
    }
    servoLB.write(speed + offset);
}

void rfRunAtSpeed (int speed, int dir) 
{
    
    // int offset = 69;
    int offset = 0;
    if (dir == FORWARD) 
    {
        speed = 180 - speed;
    }
    servoRF.write(speed - offset);
}

void rbRunAtSpeed (int speed, int dir) 
{
    
    // int offset = 69;
    int offset = 0;
    if (dir == FORWARD) 
    {
        speed = 180 - speed;
    }
    servoRB.write(speed - offset);
}

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
    servoRF.write(speed - offset);
    servoRB.write(speed - offset);
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
    // turnMotorOn();
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
    // turnMotorDown();
    leftRunAtSpeed(0, FORWARD);
    rightRunAtSpeed(0, BACKWARD);
    // turnMotorOn();
}

void turnLeft() 
{
    // turnMotorDown();
    leftRunAtSpeed(0, BACKWARD);
    rightRunAtSpeed(0, FORWARD);
    // turnMotorOn();
}

// void turnRight() 
// {
//     turnMotorDown();
//     lbRunAtSpeed(80, FORWARD);
//     lfRunAtSpeed(0, FORWARD);
//     rbRunAtSpeed(80, BACKWARD);
//     rfRunAtSpeed(0, BACKWARD);
//     // turnMotorOn();
// }

// void turnLeft() 
// {
//     turnMotorDown();
//     lbRunAtSpeed(80, BACKWARD);
//     lfRunAtSpeed(0, BACKWARD);
//     rbRunAtSpeed(80, FORWARD);
//     rfRunAtSpeed(0, FORWARD);
//     // turnMotorOn();
// }

void turnRightWithTime(int sec)
{
    turnMotorDown();
    for(int i = 0; i < sec; i++)
    {
        turnRight();
    }
    // turnMotorOn();
}

void turnLeftWithTime(int sec)
{
    turnMotorDown();
    for(int i = 0; i < sec; i++)
    {
        turnLeft();
    }
    // turnMotorOn();
}

/*
 * Tune
 */
void tuneToLeft()
{
    rightRunAtSpeed(0, FORWARD);
    leftRunAtSpeed(90, FORWARD);
    // leftRunAtSpeed(80, FORWARD);
}

void tuneToLeftWithTime(int sec)
{
    for(int i=0; i<sec; i++)
    {
        tuneToLeft();
    }
}

void tuneToRight()
{
    // rightRunAtSpeed(80, FORWARD);
    rightRunAtSpeed(90, FORWARD);
    leftRunAtSpeed(0, FORWARD);
}

void tuneToRightWithTime(int sec)
{
    for(int i=0; i<sec; i++)
    {
        tuneToRight();
    }
}

//------2--------

void tuneToLeft2()
{
    rightRunAtSpeed(0, FORWARD);
    leftRunAtSpeed(80, FORWARD);
    // leftRunAtSpeed(80, FORWARD);
}

void tuneToLeftWithTime2(int sec)
{
    for(int i=0; i<sec; i++)
    {
        tuneToLeft2();
    }
}

void tuneToRight2()
{
    // rightRunAtSpeed(80, FORWARD);
    rightRunAtSpeed(80, FORWARD);
    leftRunAtSpeed(0, FORWARD);
}

void tuneToRightWithTime2(int sec)
{
    for(int i=0; i<sec; i++)
    {
        tuneToRight2();
    }
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
