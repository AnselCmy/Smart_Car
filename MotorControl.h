#include "Define.h"

#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

void turnMotorOn(int reverse = 0)
{
    if(reverse)
    {
        digitalWrite(pin_motor2, LOW);
        digitalWrite(pin_motor1, HIGH);
    }
    else
    {
        digitalWrite(pin_motor2, HIGH);
        digitalWrite(pin_motor1, LOW);
        // digitalWrite(9, HIGH);
        // digitalWrite(10, LOW);
    }
}

void turnMotorDown()
{
    digitalWrite(pin_motor2, LOW);
    digitalWrite(pin_motor1, LOW);
}

#endif