#include "submodules/Exposer/exposer.h"
#include "submodules/Exposer/exposer.cpp"
#include <Servo.h>

Exposer* exposer = &Exposer::self();

uint8_t led = 0;

uint8_t testuint8 = 0;
uint16_t testuint16 = 0;
uint32_t testuint32 = 0;
int8_t testint8 = 0;
int16_t testint16 = 0;
int32_t testint32 = 0;
float testfloat = 0;
String teststring = "Batata";

unsigned long next;

Servo left_wheel;
Servo right_wheel;
int16_t left_pwm = 1000;
int16_t right_pwm = 1000;

void setup()
{
    Serial.begin(115200);
    left_wheel.attach(11);
    right_wheel.attach(12);
    /*exposer->registerVariable(VARNAME(led), Exposer::_uint8_t, &led);
    exposer->registerVariable(VARNAME(testuint8), Exposer::_uint8_t, &testuint8);
    exposer->registerVariable(VARNAME(testuint16), Exposer::_uint16_t, &testuint16);
    exposer->registerVariable(VARNAME(testuint32), Exposer::_uint32_t, &testuint32);
    exposer->registerVariable(VARNAME(testint8), Exposer::_int8_t, &testint8);
    exposer->registerVariable(VARNAME(testint16), Exposer::_int16_t, &testint16);
    exposer->registerVariable(VARNAME(testint32), Exposer::_int32_t, &testint32);
    exposer->registerVariable(VARNAME(testfloat), Exposer::_float, &testfloat);
    exposer->registerVariable(VARNAME(teststring), Exposer::_string, &teststring);
  */
    exposer->registerVariable(VARNAME(left_pwm), Exposer::_int16_t, &left_pwm);
    exposer->registerVariable(VARNAME(right_pwm), Exposer::_int16_t, &right_pwm);
    next = millis()+1000;
}

void loop()
{



    exposer->update();  

    if (millis()>next){
        left_wheel.writeMicroseconds(left_pwm);
        right_wheel.writeMicroseconds(right_pwm);
        next = millis()+1000;
    }

} 

