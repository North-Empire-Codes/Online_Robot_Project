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

//Commands in ASCII format
int A = 65; //Character for A
int B = 66; //Character for B
int C = 67; //Character for C
int D = 68; //Character for D
int E = 69; //Character for E
int F = 70; //Character for F
int U = 85; //Character for U
int V = 86; //Character for V
int W = 87; //Character for W
int X = 88; //Character for X
int Y = 89; //Character for Y
int Z = 90; //Character for Z

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
  if(input == A){
  	leftMotorA->run(FORWARD);
  }
  else if(input == B){
  	leftMotorA->run(BACKWARD);
  }
  else if(input == C){
  	leftMotorA->run(RELEASE);
  }
  //Checks direction for ORP-Droid A right motor
  else if(input == D){
  	rightMotorA->run(FORWARD);
  }
  else if(input == E){
  	rightMotorA->run(BACKWARD);
  }
  else if(input == F){
  	rightMotorA->run(RELEASE);
  }
  //Checks direction for ORP-Droid B left motor 
  else if(input == U){
  	leftMotorB->run(FORWARD);
  }
  else if(input == V){
  	leftMotorB->run(BACKWARD);
  }
  else if(input == W){
  	leftMotorB->run(RELEASE);
  }
  //Checks direction for ORP-Droid B right motor 
  else if(input == X){
  	rightMotorB->run(FORWARD);
  }
  else if(input == Y){
  	rightMotorB->run(BACKWARD);
  }
  else if(input == Z){
  	rightMotorB->run(RELEASE);
  }
  delay(10);
}
