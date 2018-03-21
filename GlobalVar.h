#ifndef GLOBALVAR_H
#define GLOBALVAR_H

// sensor enum 
enum sensor
{
    sensorFLL,
    sensorFL,
    sensorFC,
    sensorFR,
    sensorFRR,
    sensorNUM
};
enum red
{
    redL,
    redR,
    redNUM
};
// array of sensor pin
int sensorPin[] = {pin_sensorFLL, pin_sensorFL, pin_sensorFC, pin_sensorFR, pin_sensorFRR};
// servo 
Servo servoLF;
Servo servoRF;
Servo servoLB;
Servo servoRB;
Servo servoFront;
// alloc mem for sensor value 
int* sensorVal = (int*)malloc(5 * sizeof(int));
// for red value
int* redVal = (int*)malloc(2 * sizeof(int));
// cnt for heigh bridge
int bridgeCnt = 0;

#endif