#ifndef DETECTDIRCTION_H
#define DETECTDIRCTION_H

int ifTuneRightOnBridge(int* sensorVal)
{
    int flag = 1;
    int sensor;
    for(sensor = sensorFL; sensor < sensorNUM; sensor++)
    {
        if(sensorVal[sensor] > 100)
        {
            flag = 0;
            break;
        }
    }
    if(flag && sensorVal[sensorFLL] > 100)
    {
        return 1;
    }
    return 0;
}

int ifTuneLeftOnBridge(int* sensorVal)
{
    int flag = 1;
    int sensor;
    for(sensor = sensorFLL; sensor < sensorFRR; sensor++)
    {
        if(sensorVal[sensor] > 100)
        {
            flag = 0;
            break;
        }
    }
    if(flag && sensorVal[sensorFRR] > 100)
    {
        return 1;
    }
    return 0;
}

int detectDirection(int* sensorVal, int* redVal, int isHighBridge = 0, int useOuterSensor = 0) 
{
    // turnMotorOn();
    int lDiffll = sensorVal[sensorFL] - sensorVal[sensorFLL];
    int rDiffrr = sensorVal[sensorFR] - sensorVal[sensorFRR];
    int lrDiff = sensorVal[sensorFL] - sensorVal[sensorFR];
    int llrrDiff = sensorVal[sensorFLL] - sensorVal[sensorFRR];
    int doHighBridgeTune = 0;
    if(useOuterSensor)
    {
        if(llrrDiff > 200)
        {
            onlyUseLeft();
        }
        else if(llrrDiff < -200)
        {
            onlyUseRight();
        }
    }
    if(isHighBridge)
    {
        // if(llrrDiff < -20)
        // // if(ifTuneLeftOnBridge(getSensorVal(sensorVal)))
        // {
        //     // tuneToLeft();
        //     // turnRightWithTime(500);
        //     tuneToRight();
        //     // turnLeftWithTime(300);
        //     doHighBridgeTune = 1;
        // }
        // // else if(ifTuneRightOnBridge(getSensorVal(sensorVal)))
        // else if(llrrDiff > 20)
        // {
        //     // tuneToRight();
        //     // turnLeftWithTime(500);
        //     tuneToLeft();
        //     // turnRightWithTime(300);
        //     doHighBridgeTune = 1;
        // }
    }
    if(!useOuterSensor)
    // if(!doHighBridgeTune && !useOuterSensor)
    {
        if(lrDiff > 50) 
        {
            // 右转
            if(lrDiff > 120)
            {
                turnRightWithTime(100);
            }
            // 向右微调
            else 
            {
                tuneToRightWithTime(100);
            }
        }
        else if(lrDiff < -50)
        {
            // 左转
            if(lrDiff < -120)
            {
                turnLeftWithTime(100);
            }
            // 向左微调
            else 
            {
                tuneToLeftWithTime(100);
            }
        }
        else 
        {
            forwardRunAtSpeed(0);
        }
    }
   printf("%d, %d, %d, %d, %d\n", sensorVal[sensorFLL], sensorVal[sensorFL], sensorVal[sensorFC], sensorVal[sensorFR], sensorVal[sensorFRR]);
   // printf("%d， %d\n", redVal[redL], redVal[redR]);
   // printf("----------------------------------------------------\n");
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