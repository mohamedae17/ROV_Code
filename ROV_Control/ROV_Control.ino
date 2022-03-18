#include <Servo.h>
// Motors
Servo l1, l2, r1, r2, v1, v2, micro;
int l1_led = 27, l2_led = 33, r1_led = 31, r2_led = 29, v1_led = 23, v2_led = 25, micro_led = 37;

//Camera Servos
Servo servo1, servo2;
int serPos1 = 90, serPos2 = 90;

// Leak
#define leak 47

//Temp sensor
//#define temp A15

int prevDir = -1;

void setup() {
  // Motors
  l1.attach(9);
  l2.attach(8);
  r1.attach(7);
  r2.attach(10);

  v1.attach(13);
  v2.attach(11);
  
  micro.attach(4);

  v1.writeMicroseconds(1500);
  v2.writeMicroseconds(1500);
  micro.writeMicroseconds(1500);
  l1.writeMicroseconds(1500);
  l2.writeMicroseconds(1500);
  r1.writeMicroseconds(1500);
  r2.writeMicroseconds(1500);

  pinMode(l1_led, OUTPUT);
  pinMode(l2_led, OUTPUT);
  pinMode(r1_led, OUTPUT);
  pinMode(r2_led, OUTPUT);
  pinMode(v1_led, OUTPUT);
  pinMode(v2_led, OUTPUT);
  pinMode(micro_led, OUTPUT);

  // Camera Servos
  servo1.attach(2);
  servo2.attach(5);

  servo1.write(serPos1);
  servo1.write(serPos2);

  // Leak
  pinMode(leak, INPUT);

  // Temp sensor
  // pinMode(temp, INPUT);

  Serial.begin(9600);
  Serial.write('i');
}

void loop() {
  if (Serial.available())
  {
    char command = Serial.read();
    Serial.write((char)command);
    if (command >> 7 == 0)
    {
      Serial.write((char)command);
      int dir = command & 15;
      int Speed = command >> 4;
      Speed *= 50;
      if (dir != prevDir)
      {
        move(dir, Speed);
      }
    }
    else
    {
      Serial.write((char)command);
      int dir = command & 127;
      if (dir == 4)
      {
        //int tempValue = analogRead(temp);
        //Serial.write(char(tempValue));
      }
      else
      {
        servoMove(dir);
      }
    }
  }

  int leakValue = digitalRead(leak);
  if (leakValue)
    Serial.write(char(255));

}
