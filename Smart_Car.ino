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
    // ultra
//    pinMode(pin_trig0, OUTPUT);
//    pinMode(pin_echo0, INPUT);
    // pinMode(pin_trig1, OUTPUT);
    // pinMode(pin_echo1, INPUT);
}

void loop()
{    
//     servoFront.write(0); 
//     detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
//     routeOne();
//    routeTwo();
//    routeThree();
//    routeFour();
 
  
//     printf("%d\t%d\n", digitalRead(pin_switch), digitalRead(pin_switch2));
    
    // turnMotorOn();
    // turnLightOn();

    // printf("%d\n", getUltraVal(pin_trig0, pin_echo0));
//    servoFront.write(0);
//    forwardRunAtSpeed(0);
//    turnMotorDown();
//    for(int i=0; i<3000; i++) 
//    {
//      detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
//    }
//    for(int i=0; i<3000; i++) 
//    {
//      detectDirection(getSensorVal(sensorVal), getRedVal(redVal));
//    }
//    stopRun();
//    while(1){};

//    int pos = 0;
//turnMotorDown();
//servoFront.write(0);
//while(1)
//{
//  detectDirectionWithoutMotor(getSensorVal(sensorVal), getRedVal(redVal));
//}
//      servoFront.write(180);
//      servoFront.write(0);
//      detectDirection(getSensorVal(sensorVal), getRedVal(redVal), 0);

//    printf("%d\n", digitalRead(pin_sensorFL));
//    printf("%d\t%d\t%d\n", analogRead(pin_sensorFL), analogRead(pin_sensorFC), analogRead(pin_sensorFR));
//      printf("%d\n", servoFront.read());

//    for(pos = 0; pos < 180; pos += 5)  // 从0度到180度运动
//    {                                                     // 每次步进一度
//        servoLF.write(pos);        // 指定舵机转向的角度
//        delay(50);                       // 等待15ms让舵机到达指定位置
//    }
//    for(pos = 180; pos>=1; pos-=5)   //从180度到0度运动  
//    {                                
//        servoLF.write(pos);         // 指定舵机转向的角度
//        delay(50);                        // 等待15ms让舵机到达指定位置
//    }

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



