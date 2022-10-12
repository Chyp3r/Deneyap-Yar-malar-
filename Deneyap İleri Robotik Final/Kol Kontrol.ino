#include "deneyap.h"
#include  <ESP32Servo.h>
int teta1min = 0;
int teta1max = 3000;
int teta2min = 0;
int teta2max = 3000;
int teta3min = 0;
int teta3max = 3000;
int teta4min = 1500;
int teta4max = 2000;
int valin1, valin2, valin3, valin4=0;
int valcalc1 = 1500; 
int valcalc2 = 1500;
int valcalc3 = 1500;
int valcalc4 = 2000;
int jystp = 20;
#define X1_pin A0
#define Y1_pin A1
#define X2_pin A2
#define Y2_pin A3
#define SERVOPIN1 D12
#define SERVOPIN2 D13
#define SERVOPIN3 D14
#define SERVOPIN4 D15 
Servo myservo1, myservo2, myservo3, myservo4; 
 
void setup() {  
  myservo1.attach(SERVOPIN1);
  myservo2.attach(SERVOPIN2);
  myservo3.attach(SERVOPIN3);
  myservo4.attach(SERVOPIN4);
  pinMode(X1_pin, INPUT);
  pinMode(Y1_pin, INPUT);
  pinMode(X2_pin, INPUT);
  pinMode(Y2_pin, INPUT);

}

void loop() {
Serial.begin(9600);
ReadAnalog();
    myservo1.writeMicroseconds(valcalc1);
    myservo2.writeMicroseconds(valcalc2);
    myservo3.writeMicroseconds(valcalc3);
    myservo4.writeMicroseconds(valcalc4);
    delay(15);


}
void ReadAnalog() {
  valin1 = analogRead(Y1_pin);
  valin2 = analogRead(X1_pin);
  valin3 = analogRead(X2_pin);
  valin4 = analogRead(Y2_pin);
  Serial.println(valin1);
  if (valin1<1000 && valcalc1>teta1min) valcalc1 -= jystp;
  if (valin1>3000 && valcalc1<teta1max) valcalc1 += jystp;
  if (valin2<1000 && valcalc2>teta2min) valcalc2 -= jystp;
  if (valin2>3000 && valcalc2<teta2max) valcalc2 += jystp;
  if (valin3<1000 && valcalc3>teta3min) valcalc3 -= jystp;
  if (valin3>3000 && valcalc3<teta3max) valcalc3 += jystp;
  if (valin4<1000 && valcalc4>teta4min) valcalc4 -= jystp;
  if (valin4>3000 && valcalc4<teta4max) valcalc4 += jystp;
} 
