#include <Servo.h>
#include "ServoControl.h"
#include "MotorControl.h"
#include "Sensor.h"
#include "RouteOne.h"
#include "RouteTwo.h"
#include "RouteThree.h"
#include "RouteFour.h"

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
    pinMode(pin_switch2, INPUT);
    pinMode(pin_motor1, OUTPUT);
    pinMode(pin_motor2, OUTPUT);
    // set up serial printf
    Serial.begin(9600);
    printf_begin();
    // attach servo to pin
    servoLF.attach(pin_servoLF); 
    servoLB.attach(pin_servoLB);
    servoRF.attach(pin_servoRF);
    servoRB.attach(pin_servoRB);
    servoFront.attach(pin_servoFront); 
    // turn on motor
    turnMotorOn();
}

void loop()
{    
    turnLightDown();
    if(digitalRead(pin_switch) == 0)
    {
        delay(1000);
        if(digitalRead(pin_switch2) == 1)
        {
            delay(200);
            turnLightOn();
            delay(200);
            turnLightDown(); 
            routeOne();
        }
        else
        {
            delay(200);
            for(int i=0; i<2; i++)
            {
                turnLightOn();
                delay(200);
                turnLightDown(); 
                delay(200);
            }
            routeTwo();
        }
    }
    else if(digitalRead(pin_switch2) == 0)
    {
        delay(1000);
        if(digitalRead(pin_switch) == 1)
        {
            for(int i=0; i<3; i++)
            {
                turnLightOn();
                delay(200);
                turnLightDown(); 
                delay(200);
            }
            routeThree();
        }
        else
        {
            for(int i=0; i<4; i++)
            {
                turnLightOn();
                delay(200);
                turnLightDown(); 
                delay(200);
            }
            routeFour();
        }
    }
}



