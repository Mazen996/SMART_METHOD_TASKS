#include <Servo.h>
#include <Wire.h>

#define button1  8
#define button2  4
boolean lid=true;
Servo servo_9;
Servo servo_10; 
int pos=0; // The initial servo position

void setup() {
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
 // Use internal resistors for the button
  Wire.begin();
  servo_9.attach(9);
  servo_10.attach(10);
 //PWM Arduino pin for the servo
  servo_9.write(0); // The lid is closed
  servo_10.write(0);
  
}

void loop() {
  if(digitalRead(button1)==LOW){
 //Because of the internal resistors
    if(lid==true){
      for(pos=0;pos<=180;pos++){
        servo_9.write(pos);
 //When pos=180, the lid is fully open
        delay(10);
      }
    }
    else
    {
      for(pos=180;pos>=0;pos--){
        servo_9.write(pos);
 //When pos=0, the lid is closed again
        delay(10);
      }
    }
    lid=!lid;
  while(digitalRead(button2)==LOW);
 //Avoids bounces
  }
    if(digitalRead(button2)==LOW){
 //Because of the internal resistors
    if(lid==true){
      for(pos=0;pos<=180;pos++){
        servo_10.write(pos);
 //When pos=180, the lid is fully open
        delay(10);
      }
    }
    else
    {
      for(pos=180;pos>=0;pos--){
        servo_10.write(pos);
 //When pos=0, the lid is closed again
        delay(10);
      }
    }
    lid=!lid;
  while(digitalRead(button2)==LOW);
 //Avoids bounces
  }
}
