#include "deneyap.h"
#include  <ESP32Servo.h>
int input_value_one, input_value_two, input_value_three, input_value_four=0;
int calculated_value_one = 1500; 
int calculated_value_two = 1500;
int calculated_value_three = 1500;
int calculated_value_four = 2000;
int angle_one_min = 0;
int angle_one_max = 3000;
int angle_two_min = 0;
int angle_two_max = 3000;
int angle_three_min = 0;
int angle_three_max = 3000;
int angle_four_min = 1500;
int angle_four_max = 2000;
int jystp = 20;
#define SERVOPIN1 D12
#define SERVOPIN2 D13
#define SERVOPIN3 D14
#define SERVOPIN4 D15 
#define X1_pin A0
#define Y1_pin A1
#define X2_pin A2
#define Y2_pin A3

Servo servo_motor_1, servo_motor_2, servo_motor_3, servo_motor_4; 
 
void setup() 
{  
  servo_motor_1.attach(SERVOPIN1);
  servo_motor_2.attach(SERVOPIN2);
  servo_motor_3.attach(SERVOPIN3);
  servo_motor_4.attach(SERVOPIN4);
  
  pinMode(X1_pin, INPUT);
  pinMode(Y1_pin, INPUT);
  pinMode(X2_pin, INPUT);
  pinMode(Y2_pin, INPUT);

}

void loop() 
{
Serial.begin(9600);
ReadAnalog();
    servo_motor_1.writeMicroseconds(calculated_value_one);
    servo_motor_2.writeMicroseconds(calculated_value_two);
    servo_motor_3.writeMicroseconds(calculated_value_three);
    servo_motor_4.writeMicroseconds(calculated_value_four);
    delay(15);


}
void ReadAnalog() {
  input_value_one = analogRead(Y1_pin);
  input_value_two = analogRead(X1_pin);
  input_value_three = analogRead(X2_pin);
  input_value_four = analogRead(Y2_pin);
  
  if (input_value_one<1000 && calculated_value_one>angle_one_min) calculated_value_one -= jystp;
  if (input_value_one>3000 && calculated_value_one<angle_one_max) calculated_value_one += jystp;
  if (input_value_two<1000 && calculated_value_two>angle_two_min) calculated_value_two -= jystp;
  if (input_value_two>3000 && calculated_value_two<angle_two_max) calculated_value_two += jystp;
  if (input_value_three<1000 && calculated_value_three>angle_three_min) calculated_value_three -= jystp;
  if (input_value_three>3000 && calculated_value_three<angle_three_max) calculated_value_three += jystp;
  if (input_value_four<1000 && calculated_value_four>angle_four_min) calculated_value_four -= jystp;
  if (input_value_four>3000 && calculated_value_four<angle_four_max) calculated_value_four += jystp;
} 
