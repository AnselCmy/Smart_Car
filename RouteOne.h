#include "DetectDirection.h"
#include "Light.h"
#include "Define.h"

#ifndef ROUTEONE_H
#define ROUTEONE_H

void turnRight90()
{
    for(int i=0; i<12000; i++)
    {
      rightRunAtSpeed(90, BACKWARD);
      leftRunAtSpeed(0, FORWARD);
    }
}

void routeOne()
{
    // step1 开始->栅格->卡住
    turnMotorOn();                          // 关电机
    servoFront.write(60);                   // 把前面调成60度    
    forwardRunAtSpeedWithTime(0, 15000);    // 在栅格前面一段不循迹 
    turnLightOn();
    detectDirectionWithTime(0, 3000);       // 过栅格
    detectDirectionWithTime(0, 1000);       // 过栅格
    servoFront.write(180);                  // 把前面调成180度  
    turnMotorDown();
    for(int i=0; i<2800; i++)
    {
        detectDirectionWithoutMotor2(getSensorVal(sensorVal), getRedVal(redVal));
    }
    stopRun();                              // 舵机停止
    // step2 卡住结束->上窄桥->右转
    turnMotorOn();                          // 开电机
    servoFront.write(60);                   // 把前面调回60度    
    forwardRunAtSpeedWithTime(0, 22000);    // 直走上窄桥
    stopRun();                              // 停止
    turnMotorDown();                        // 关电机
    turnRight90();                          // 右转90度
    stopRun();                              // 停止
    // step3 上高台
    turnMotorOn();                          // 开电机
    while(1)
    {
        forwardRunAtSpeed(0);               // 上高台
    }
}

#endif