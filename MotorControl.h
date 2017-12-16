#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

void turnMotorOn(int reverse = 0)
{
    if(reverse)
    {
        digitalWrite(6, LOW);
        digitalWrite(5, HIGH);
    }
    else
    {
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
    }
}

void turnMotorDown()
{
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
}

#endif