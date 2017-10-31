//#include "submodules/Exposer/exposer.h"
//#include "submodules/Exposer/exposer.cpp"
#include <Servo.h>

#define LOOP_DELAY 2000
#define RIGHT_B 1600
#define LEFT_B 1600
#define RIGHT_F 1200
#define LEFT_F 1200
#define STOP_MOTOR 1500

//Exposer* exposer = &Exposer::self();

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

char rc;
int robot_vel;

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

    exposer->registerVariable(VARNAME(left_pwm), Exposer::_int16_t, &left_pwm);
    exposer->registerVariable(VARNAME(right_pwm), Exposer::_int16_t, &right_pwm);
    next = millis()+1000;  */
    delay(50);
}

void loop()
{

  while(!Serial.available() ){}
    rc = Serial.read();
    Serial.println(rc);
    if(rc == 'm'){
      while(!Serial.available() ){}
      rc = Serial.read();
      move_robot(rc);
    }
    if(rc == 'c'){
      Serial.println("Pegar copo");
    }
    if(rc == 'o'){
      Serial.println("Ordenhar vaca");
    }    
    if(rc == 'q'){
      while(!Serial.available() ){}
      robot_vel = Serial.parseInt();
      Serial.println(robot_vel);
      left_wheel.writeMicroseconds(robot_vel);
      right_wheel.writeMicroseconds(robot_vel);
      delay(10);
      left_wheel.writeMicroseconds(robot_vel);
      right_wheel.writeMicroseconds(robot_vel);
    }
    /*exposer->update();  

    if (millis()>next){
        left_wheel.writeMicroseconds(left_pwm);
        right_wheel.writeMicroseconds(right_pwm);
        next = millis()+1000;
    }*/

} 

void move_robot(char dir){
  left_wheel.writeMicroseconds(1400);
  right_wheel.writeMicroseconds(1400);
  delay(LOOP_DELAY*2);
  if(dir == 'f'){
    left_wheel.writeMicroseconds(LEFT_F);
    right_wheel.writeMicroseconds(RIGHT_F);
  }
  if(dir == 'b'){
    left_wheel.writeMicroseconds(LEFT_B);
    right_wheel.writeMicroseconds(RIGHT_B);
  }
  if(dir == 'l'){
    left_wheel.writeMicroseconds(LEFT_B);
    right_wheel.writeMicroseconds(RIGHT_F);
  }
  if(dir == 'r'){
    left_wheel.writeMicroseconds(LEFT_F);
    right_wheel.writeMicroseconds(RIGHT_B);
  }

  delay(LOOP_DELAY);
  left_wheel.writeMicroseconds(STOP_MOTOR);
  right_wheel.writeMicroseconds(STOP_MOTOR);
  delay(50);
}

