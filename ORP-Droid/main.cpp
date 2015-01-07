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
Author: Avery D. Reich-Norris
Company: Northern Empire Companies
*/

/*
TABLE OF CONTENTS
  Section Title-Line Number
   ~Sub-section Title-Line Number
  Imports-
  Object List-
   ~MotorShield-
   ~ORP-Droid A-
   ~ORP-Droid B-
   ~Important Integers-
   ~Input/Output Pin List-
  Arduino Port Setup-
  Command Loop-
  Drive Commands-
   ~ORP-Droid A-
   ~ORP-Droid B-
  
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
int frequency = 1600; //Defines an integer for MotorShield Frequency
int motorSpd = 200; //Defines an integer for motor speed
//Digital Input/Output Pin List
int leftFwdA = 1; //Defines the forward left motor information pin from the Raspberry Pi for ORP-Droid A
int leftBwdA = 2; //Defines the backward left motor information pin from the Raspberry Pi for ORP-Droid A
int rightFwdA = 3; //Defines the forward right motor information pin from the Raspberry Pi for ORP-Droid A
int rightBwdA = 4; //Defines the backward right motor information pin from the Raspberry Pi for ORP-Droid A 
int leftFwdB = 5; //Defines the forward left motor information pin from the Raspberry Pi for ORP-Droid B
int leftBwdB = 6; //Defines the backward left motor information pin from the Raspberry Pi for ORP-Droid B
int rightFwdB = 7; //Defines the forward right motor information pin from the Raspberry Pi for ORP-Droid B
int rightBwdB = 8; //Defines the backward right motor information pin from the Raspberry Pi for ORP-Droid B

// This function sets up the ports on the Arduino
void setup() {
  //Setup Input Pins
  //ORP-Droid A
  pinMode(leftSlowA, INPUT);
  pinMode(leftFastA, INPUT);
  pinMode(rightSlowA, INPUT);
  pinMode(rightFastA, INPUT);
  //ORP-Droid B
  pinMode(leftSlowB, INPUT);
  pinMode(leftFastB, INPUT);
  pinMode(rightSlowB, INPUT);
  pinMode(rightFastB, INPUT);
  //Begins the shield processes
  shield.begin(frequency);  // create with the variable frequency
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
	//Checks direction for ORP-Droid A left motor 
  if(digitalRead(leftFwdA) == HIGH and digitRead(leftBwdA) == LOW){
  	leftDriveA(FORWARD);
  }
  else if(digitalRead(leftFwdA) == LOW and digitRead(leftBwdA) == HIGH){
  	leftDriveA(BACKWARD);
  }
  else{
  	leftDriveA(RELEASE);
  }
  //Checks direction for ORP-Droid A right motor 
  if(digitalRead(rightFwdA) == HIGH and digitRead(rightBwdA) == LOW){
  	rightDriveA(FORWARD);
  }
  else if(digitalRead(leftFwdA) == LOW and digitRead(rightBwdA) == HIGH){
  	rightDriveA(BACKWARD);
  }
  else{
  	rightDriveA(RELEASE);
  }
  //Checks direction for ORP-Droid B left motor 
  if(digitalRead(leftFwdB) == HIGH and digitRead(leftBwdB) == LOW){
  	leftDriveB(FORWARD);
  }
  else if(digitalRead(leftFwdB) == LOW and digitRead(leftBwdB) == HIGH){
  	leftDriveB(BACKWARD);
  }
  else{
  	leftDriveB(RELEASE);
  }
  //Checks direction for ORP-Droid B right motor 
  if(digitalRead(rightFwdB) == HIGH and digitRead(rightBwdB) == LOW){
  	rightDriveB(FORWARD);
  }
  else if(digitalRead(rightFwdB) == LOW and digitRead(rightBwdB) == HIGH){
  	rightDriveB(BACKWARD);
  }
  else{
  	rightDriveB(RELEASE);
  }
  delay(50);
}

//This function run the left motor for ORP-Droid A in a defined direction
void leftDriveA(command){
	leftMotorA->run(command);
}
void rightDriveA(command){
	rightMotorA->run(command);
}
void leftDriveB(command){
	leftMotorB->run(command);
}
void rightDriveB(command){
	rightMotorB->run(command);
}
