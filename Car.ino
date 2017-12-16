#include <Servo.h>
#include "ServoControl.h"
#include "MotorControl.h"
#include "Sensor.h"
#include "RouteOne.h"
#include "RouteTwo.h"
#include "RouteThree.h"

// for serial printf
int serial_putc(char c, struct __file*)
{
      Serial.write(c);
      return c;
}

void printf_begin(void)
{
    fdevopen(&serial_putc, 0);
}

void setup() 
{
    // pin mode
    pinMode(pin_light, OUTPUT);
    pinMode(pin_switch, INPUT);
    // set up serial printf
    Serial.begin(9600);
    printf_begin();
    // attach servo to pin
    servoLF.attach(pin_servoLF); 
    servoLB.attach(pin_servoLB);
    servoRF.attach(pin_servoRF);
    servoRB.attach(pin_servoRB);
    // turn on motor
    turnMotorOn();
    // ultra
    pinMode(pin_trig, OUTPUT);
    pinMode(pin_echo, INPUT);
}

void loop() 
{    
//    printf("%d\n", getUltraVal());   
//    printf("%d\n", digitalRead(pin_switch2));
//    routeOne();
//    routeTwo();
//    tuneToRight();    
//    run1();  
//    detectDirectionWithTime(0, 500);
//    stopRun();
//    printf("end");
//    while(1){}
//    printf("%d\n", digitalRead(3));
    
    if(digitalRead(pin_switch) == 0)
    {
        turnLightDown();
        routeOne();
    }
    else if(digitalRead(pin_switch2) == 0)
    {
        delay(1000);
        if(digitalRead(pin_switch) == 0)
        {
            turnLightDown();
            delay(200);
            turnLightOn();
            delay(200);
            turnLightDown();
            delay(200);
            turnLightOn();
            delay(200);
            turnLightDown();
            delay(200);
            turnLightOn();
            delay(200);
            turnLightDown();
            routeThree();
        }
        else 
        {
            turnLightDown();
            delay(200);
            turnLightOn();
            delay(200);
            turnLightDown();
            delay(200);
            turnLightOn();
            delay(200);
            turnLightDown();
            routeTwo();
        }
    }
    // only detect direction
    else 
    {
        turnLightOn();
        detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
    }
    
//    if(getUltraVal() <= 7)
//    {
//        turnLightOn();
//        delay(10);
//        turnLightDown();
//    }
//    detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 0);

//    forwardRunAtSpeed(0);
//    tuneToLeft();
//    detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1);
//    detectDirectionWithTime(0, 100);
//    detectDirectionWithTime(0, 100);
//    turnRight90();
//    while(1)
//    {}
//    run1();
//    detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 0);
//    stop();
//    printf("%d， %d\n", digitalRead(4), digitalRead(3));
//    printf("%d, %d. %d\n", analogRead(pin_sensorFL), analogRead(pin_sensorFC), analogRead(pin_sensorFR));
//    digitalWrite(13, HIGH);
//    printf("%d\n", digitalRead(2));
//    long duration, cm;
//    detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 1, 0);
}



