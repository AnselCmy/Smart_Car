#ifndef DETECTDIRCTION_H
#define DETECTDIRCTION_H

/*
 * 使用tune2的巡线，
 * 也就是在微调的时候两边都会转动，只是某一边比较慢
 * 并且这个函数在默认情况下是会打开motor的，在最后一个else里面
 */
int detectDirection(int* sensorVal, int* redVal, int isHighBridge = 0, int useOuterSensor = 0) 
{
    // calculation
    int lDiffll = sensorVal[sensorFL] - sensorVal[sensorFLL];
    int rDiffrr = sensorVal[sensorFR] - sensorVal[sensorFRR];
    int lrDiff = sensorVal[sensorFL] - sensorVal[sensorFR];
    int llrrDiff = sensorVal[sensorFLL] - sensorVal[sensorFRR];
    // parameters
    // turn
    int turnParam = 80;
    int turnTime = 200;
    // tune
    int tuneParam = 50;
    int tuneTime = 100;

    if(lrDiff > tuneParam) 
    {
        // 右转
        if(lrDiff > turnParam)
        {
            turnRightWithTime(turnTime);
        }
        // 向右微调
        else 
        {
            tuneToRightWithTime2(tuneTime);
        }
    }
    else if(lrDiff < -1*tuneParam)
    {
        // 左转
        if(lrDiff < -1*turnParam)
        {
            turnLeftWithTime(turnTime);
        }
        // 向左微调
        else 
        {
            tuneToLeftWithTime2(tuneTime);
        }
    }
    else 
    {
        turnMotorOn();
        forwardRunAtSpeed(0);
    }
    // printf("%d, %d, %d, %d, %d\n", sensorVal[sensorFLL], sensorVal[sensorFL], sensorVal[sensorFC], sensorVal[sensorFR], sensorVal[sensorFRR]);
    // printf("----------------------------------------------------\n");
    return 0;
}

/*
 * 使用tune2的巡线，
 * 也就是在微调的时候两边都会转动，只是某一边比较慢
 * 默认情况下不打开motor
 */
int detectDirectionWithoutMotor2(int* sensorVal, int* redVal, int isHighBridge = 0, int useOuterSensor = 0) 
{
    // calculation
    int lDiffll = sensorVal[sensorFL] - sensorVal[sensorFLL];
    int rDiffrr = sensorVal[sensorFR] - sensorVal[sensorFRR];
    int lrDiff = sensorVal[sensorFL] - sensorVal[sensorFR];
    int llrrDiff = sensorVal[sensorFLL] - sensorVal[sensorFRR];
    // parameters
    // turn
    int turnParam = 120;
    int turnTime = 150;
    // tune
    int tuneParam = 50;
    int tuneTime = 100;

    if(lrDiff > tuneParam) 
    {
        // 右转
        if(lrDiff > turnParam)
        {
            turnRightWithTime(turnTime);
        }
        // 向右微调
        else 
        {
            tuneToRightWithTime2(tuneTime);
        }
    }
    else if(lrDiff < -1*tuneParam)
    {
        // 左转
        if(lrDiff < -1*turnParam)
        {
            turnLeftWithTime(turnTime);
        }
        // 向左微调
        else 
        {
            tuneToLeftWithTime2(tuneTime);
        }
    }
    else 
    {
        forwardRunAtSpeed(0);
    }
    // printf("%d, %d, %d, %d, %d\n", sensorVal[sensorFLL], sensorVal[sensorFL], sensorVal[sensorFC], sensorVal[sensorFR], sensorVal[sensorFRR]);
    return 0;
}

/*
 * 这个巡线非常灵敏
 * 把微调和转弯都是设成了turnWithTime(200)
 * 转弯参数：40，微调参数：60
 */
int detectDirectionWithoutMotor(int* sensorVal, int* redVal, int isHighBridge = 0, int useOuterSensor = 0) 
{
    // calculation
    int lDiffll = sensorVal[sensorFL] - sensorVal[sensorFLL];
    int rDiffrr = sensorVal[sensorFR] - sensorVal[sensorFRR];
    int lrDiff = sensorVal[sensorFL] - sensorVal[sensorFR];
    int llrrDiff = sensorVal[sensorFLL] - sensorVal[sensorFRR];
    // parameters
    // turn
    int turnParam = 60;
    int turnTime = 200;
    // tune
    int tuneParam = 40;
    int tuneTime = 200;

    if(lrDiff > tuneParam) 
    {
        // 右转
        if(lrDiff > turnParam)
        {
            turnRightWithTime(turnTime);
        }
        // 向右微调
        else 
        {
            turnRightWithTime(tuneTime);
        }
    }
    else if(lrDiff < -1*tuneParam)
    {
        // 左转
        if(lrDiff < -1*turnParam)
        {
            turnLeftWithTime(turnTime);
        }
        // 向左微调
        else 
        {
            turnLeftWithTime(tuneTime);
        }
    }
    else 
    {
        forwardRunAtSpeed(0);
    }
    // printf("%d, %d, %d, %d, %d\n", sensorVal[sensorFLL], sensorVal[sensorFL], sensorVal[sensorFC], sensorVal[sensorFR], sensorVal[sensorFRR]);
    return 0;
}

int detectDirectionWithTime(int isHighBridge, int sec)
{
    for(int i = 0; i < sec; i++)
    { 
        detectDirection(getSensorVal(sensorVal), getRedVal(redVal), isHighBridge);
    }
}

#endif