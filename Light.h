#ifndef LIGHT_H
#define LIGHT_H

void turnLightOn()
{
    digitalWrite(pin_light, HIGH);
}

void turnLightDown()
{
    digitalWrite(pin_light, LOW);
}

#endif