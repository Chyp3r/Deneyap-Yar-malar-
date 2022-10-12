#include "deneyap.h"
#include <ESP32Servo.h>
#define X3_pin A1
#define Y3_pin A2
#define SW D4
#define MOT_DIR1 D12 
#define MOT_DIR2 D13  
#define MOT_DIR3 D14  
#define MOT_DIR4 D15 
#define MOT_ENA D8
#define MOT_ENB D9
int valin3;
int valin4;
int a;
void setup() {
 Serial.begin(9600); 
 pinMode(SW, INPUT_PULLUP);
 pinMode(MOT_ENA, OUTPUT); // Motor hız kontrol pini cikis olarak ayarlandi
 pinMode(MOT_DIR1, OUTPUT); // Motor yon secme pin1 cikis olarak ayarlandi
 pinMode(MOT_DIR2, OUTPUT); // Motor yon secme pin2 cikis olarak ayarlandi
 pinMode(MOT_ENB, OUTPUT); // Motor hız kontrol pini cikis olarak ayarlandi
 pinMode(MOT_DIR3, OUTPUT); // Motor yon secme pin1 cikis olarak ayarlandi
 pinMode(MOT_DIR4, OUTPUT); // Motor yon secme pin2 cikis olarak ayarlandi
}

void loop() {
  // put your main code here, to run repeatedly:
 a = digitalRead(SW);
 valin3 = analogRead(X3_pin);
 valin4 = analogRead(Y3_pin);
 Serial.println(a);

 if (valin3 > 3900 && valin4>4000 )
 {
  digitalWrite(MOT_DIR1, LOW);
  digitalWrite(MOT_DIR2, HIGH);
  digitalWrite(MOT_DIR3, LOW);
  digitalWrite(MOT_DIR4, LOW);
  delay(15);
 }
 else if (valin3 > 3900 && valin4<1000 )
 {
  digitalWrite(MOT_DIR1, LOW);
  digitalWrite(MOT_DIR2, LOW);
  digitalWrite(MOT_DIR3, LOW);
  digitalWrite(MOT_DIR4, HIGH);
  delay(15);
  
 }
  else if (valin3 >3900)
 {
  digitalWrite(MOT_DIR1, LOW);
  digitalWrite(MOT_DIR2, HIGH);
  digitalWrite(MOT_DIR3, LOW);
  digitalWrite(MOT_DIR4, HIGH);
  delay(15);
  
 }
 else if (valin3 < 3900 && valin3 > 1000)
 {
  digitalWrite(MOT_DIR1, LOW);
  digitalWrite(MOT_DIR2, LOW);
  digitalWrite(MOT_DIR3, LOW);
  digitalWrite(MOT_DIR4, LOW);
  delay(15);
 }
 
  else
 {
  digitalWrite(MOT_DIR1, HIGH);
  digitalWrite(MOT_DIR2, LOW);
  digitalWrite(MOT_DIR3, HIGH);
  digitalWrite(MOT_DIR4, LOW);
  delay(15);
 }
}
