#include "DetectDirection.h"
#include "Light.h"
#include "Define.h"

#ifndef ROUTEONE_H
#define ROUTEONE_H

void turnRight90()
{
    // turnRightWithTime(7200);
    // turnRightWithTime(7000);
    // tuneToRightWithTime(7000);
    for(int i=0; i<12000; i++)
    {
      rightRunAtSpeed(90, BACKWARD);
      leftRunAtSpeed(0, FORWARD);
    }
}

void turnRight180()
{
    // turnRightWithTime(11100);
    turnRightWithTime(11000);
}

// int ifHighBidgeStart()
// {
//     int ultraVal = getUltraVal();
//     // printf("%d， %d\n", bridgeCnt, ultraVal);
//     if(ultraVal <= 7)
//     {
//         bridgeCnt++;
//         // when get the signal of ultra turn on the light
//         turnLightOn();
//         delay(10);
//         turnLightDown();
//         // delay 
//         detectDirectionWithTime(0, 300);
//     }
//     if(bridgeCnt == 3)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

int ifHighBidgeStart()
{
    int ultraVal = getUltraVal(pin_trig0, pin_echo0);
    // printf("%d\n", ultraVal);
    int thresholdMax = 21;
    int thresholdMin = 16;
    int reallyGet = true;
    if(ultraVal <= thresholdMax && ultraVal >= thresholdMin)
    {
        reallyGet = true;
        // 多次判断
        for(int i=0; i<5; i++)
        {
            ultraVal = getUltraVal(pin_trig0, pin_echo0);
            if(ultraVal <= thresholdMax && ultraVal >= thresholdMin) 
            {
                reallyGet = false;
                break;
            }
        }
        if(reallyGet)
        {
            turnLightOn();
            delay(10);
            turnLightDown();
            // // delay 
            // detectDirectionWithTime(0, 300);
            // stopRunWithTime(10000);
            // turnLightOn();
            return 1;
        }
    }
    return 0;
}

// void routeOne()
// {
//     // step1 开始->栅格->卡住
//     turnMotorOn();                        // 关电机
//     servoFront.write(60);                   // 把前面调成60度    
//     forwardRunAtSpeedWithTime(0, 15000);    // 在栅格前面一段不循迹 
//     detectDirectionWithTime(0, 550);        // 过栅格
//     servoFront.write(180);                  // 把前面调成180度  
//     turnMotorOn(1);
//     detectDirectionWithTime(0, 150);        // 开始循迹直到卡在窄桥上
//     stopRun();                              // 舵机停止
//     // step2 卡住结束->上窄桥->右转
//     turnMotorOn();                          // 开电机
//     servoFront.write(60);                   // 把前面调回60度    
//     detectDirectionWithTime(0, 350);        // 开始循迹上坡
//     stopRun();                              // 停止
//     turnMotorDown();                        // 关电机
//     turnRight90();                          // 右转90度
//     stopRun();                              // 停止
//     // step3 上高台
//     turnMotorOn();                          // 开电机
//     forwardRunAtSpeedWithTime(0, 30000);    // 上高台
//     turnMotorDown();                        
//     stopRun();
//     // // step4 转回180->下高台
//     // turnRight180();
//     // forwardRunAtSpeedWithTime(0, 30000);
//     // stopRun();

//     while(1){
//         // servoFront.write(180);
//         // detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
//     }
//     // detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
//     // detectDirectionWithTime(0, 10000);
// }



void routeOne()
{
    // step1 开始->栅格->卡住
    turnMotorOn();                        // 关电机
    servoFront.write(60);                   // 把前面调成60度    
    forwardRunAtSpeedWithTime(0, 15000);    // 在栅格前面一段不循迹 
    turnLightOn();
    detectDirectionWithTime(0, 3000);        // 过栅格
    detectDirectionWithTime(0, 1000);        // 过栅格
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
    forwardRunAtSpeedWithTime(0, 22000);
    stopRun();                              // 停止
    turnMotorDown();                        // 关电机
    turnRight90();                          // 右转90度
    stopRun();                              // 停止
    // step3 上高台
    turnMotorOn();                          // 开电机
    forwardRunAtSpeedWithTime(0, 25000);    // 上高台
    turnMotorDown();                        
    stopRun();
    // // step4 转回180->下高台
    // turnRight180();
    // forwardRunAtSpeedWithTime(0, 30000);
    // stopRun();

    while(1){
        // servoFront.write(180);
        // detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    }
    // detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    // detectDirectionWithTime(0, 10000);
}

#if 0
void routeOne()
{
    getSensorVal(sensorVal);
    int crossCnt = 0;
    int i = 0;
    // int highBridgeParam = 1350;
    // int highBridgeParam = 2500;
    int highBridgeParam = 250;
    // 不循迹直走
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 5000);
    // turnLightOn();
    // delay(200);
    // turnLightDown();
    // turnLightOn();
    // delay(200);
    // turnLightDown();
    // turnLightOn();
    // delay(200);
    // turnLightDown();
    // stopRunWithTime(10000);
    // 直到要上高台
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
    // forwardRunAtSpeedWithTime(0, 10000);
    forwardRunAtSpeedWithTime(0, 3000);
    // turn right 180
    turnMotorDown();
    stopRunWithTime(100);
    turnRight180();
    stopRunWithTime(100);
    forwardRunAtSpeedWithTime(0, 10000);
    forwardRunAtSpeedWithTime(0, 10000);
    // forwardRunAtSpeedWithTime(0, 10000);
    turnMotorDown();
    stopRunWithTime(100);
    turnRight90();
    stopRunWithTime(100);
    // while(!(sensorVal[sensorFLL] > 200 && sensorVal[sensorFRR] > 200))
    // {
    //     detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    // }
    // // highBridge END
    // while(!(sensorVal[sensorFLL] < 200 && sensorVal[sensorFRR] < 200))
    // {
    //     detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    // }
    // // at the second cross 
    // turnRight90();
    while(1)
    {
        detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    }
}

#endif

#endif