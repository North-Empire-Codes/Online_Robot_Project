/*
The code that follows is for the ORP-Droid Control Console which controls the two ORP-Droids.
The ORP-Droid Control Console uses this
http://www.adafruit.com/products/1438 MotorShield and
an Arduino to control both ORP-Droid A and B at the same time. It is also connected to a
Raspberry Pi, via digital input ports, which is connected the the Online Robot Project webpage.
The Online Robot Project webpage can be found at: http://online-robot-project.sotabots.com
The assembly instructions can be found there. The rest of the code can be found on GITHub at:
https://github.com/NorthEmpireCo/Online_Robot_Project This project is sponsored by the SOTABots.
More information about the SOTABots can be found at http://www.sotabots.com the SOTABots webpage.
This project is under the GNU GENERAL PUBLIC LICENSE V.2 1991.
Author: Northern Emperor
Company: Northern Empire Codes
*/


/*
This section includes the right libraries
*/
#include <Wire.h> //Includes the wire library
#include <Adafruit_MotorShield.h> //Includes the MotorShield library
#include "utility/Adafruit_PWMServoDriver.h" //Includes the PWM Servo Driver library

/*
This Section is where the objects are defined
*/
//MotorShield
Adafruit_MotorShield shield = Adafruit_MotorShield(); //defines the MotorShield
//ORP-Droid A
Adafruit_DCMotor* leftMotorA = shield.getMotor(1); //defines the left motor for ORP-Droid A
Adafruit_DCMotor* rightMotorA = shield.getMotor(2); //defines the right motor for ORP-Droid A
//ORP-Droid B
Adafruit_DCMotor* leftMotorB = shield.getMotor(3); //defines the left motor for ORP-Droid B
Adafruit_DCMotor* rightMotorB = shield.getMotor(4); //defines the right motor for ORP-Droid B
//Important Integers
int motorFrequency = 1600; //Defines an integer for MotorShield Frequency
int motorSpd = 100; //Defines an integer for motor speed
int serialFrequency = 9600; //Defines an integer for serial port frequency
int input = -1; //Initializes the input variable


// This function sets up the ports on the Arduino
void setup() {
  //Setups up serial port to the Raspberry Pi
  Serial.begin(serialFrequency);
  //Starts Motor Shield
  shield.begin(motorFrequency);  // create with the variable frequency
  //AFMS.begin() create with the default frequency 1.6KHz
  
  //Set the inital speed of the motors based on a variable from 0(Full Stop)-255(Max Speed)
  //ORP-Droid A
  leftMotorA->setSpeed(motorSpd);
  rightMotorA->setSpeed(motorSpd);
  //ORP-Droid B
  leftMotorB->setSpeed(motorSpd);
  rightMotorB->setSpeed(motorSpd);
}

// This function loops forever as long as the Arduino has power
void loop() {
  input = Serial.read();
  //Checks direction for ORP-Droid A left motor 
  if(input == 65/*Looks for an A*/){
  	leftMotorA->run(FORWARD);
  }
  else if(input == 66/*Looks for a B*/){
  	leftMotorA->run(BACKWARD);
  }
  else if(input == 67/*Looks for a C*/){
  	leftMotorA->run(RELEASE);
  }
  //Checks direction for ORP-Droid A right motor
  else if(input == 69/*Looks for a D*/){
  	rightMotorA->run(FORWARD);
  }
  else if(input == 70 /*Looks for an E*/){
  	rightMotorA->run(BACKWARD);
  }
  else if(input == 71 /*Looks for an F*/){
  	rightMotorA->run(RELEASE);
  }
  //Checks direction for ORP-Droid B left motor 
  else if(input == 85 /*Looks for a U*/){
  	leftMotorB->run(FORWARD);
  }
  else if(input == 86 /*Looks for a V*/){
  	leftMotorB->run(BACKWARD);
  }
  else if(input == 87 /*Looks for a W*/){
  	leftMotorB->run(RELEASE);
  }
  //Checks direction for ORP-Droid B right motor 
  else if(input == 88 /*Looks for an X*/){
  	rightMotorB->run(FORWARD);
  }
  else if(input == 89 /*Looks for a Y*/){
  	rightMotorB->run(BACKWARD);
  }
  else if(input == 90 /*Looks for a Z*/){
  	rightMotorB->run(RELEASE);
  }
  delay(10);
}
