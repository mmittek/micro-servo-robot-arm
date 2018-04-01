/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#include <string.h>

Servo L1;  // create servo object to control a servo
Servo L2;
Servo L3;
Servo L4;


int val;    // variable to read the value from the analog pin
char linebuf[512];


void setup() {
  L1.attach(8);  // attaches the servo on pin 9 to the servo object
  L2.attach(9);  // attaches the servo on pin 9 to the servo object
  L3.attach(7);  // attaches the servo on pin 9 to the servo object
  L4.attach(6);  // attaches the servo on pin 9 to the servo object

L1.write(60);
L2.write(83);
L3.write(73);
L4.write(98);
Serial.begin(115200);
 memset(linebuf, 0, sizeof(linebuf));
}


uint8_t angles[4];
int i;
uint8_t newangles[4];
void loop() {

  if(Serial.available() == 4) {
    for(i=0; i<4; i++) {
      newangles[i] = Serial.read();     
    }

    if(newangles[0] != angles[0] ){ L1.write(newangles[0]); angles[0] = newangles[0];}    
    if(newangles[1] != angles[1] ){ L2.write(newangles[1]); angles[1] = newangles[1];}    
    if(newangles[2] != angles[2] ){ L3.write(newangles[2]); angles[2] = newangles[2];}    
    if(newangles[3] != angles[3] ){ L4.write(newangles[3]); angles[3] = newangles[3];}    
  }
  
  
//  delay(1);                           // waits for the servo to get there
}

