#!/usr/bin/python

#Imports
#Import Serial Streamer
from SerialStream import *
#Import sleep timer
from time import sleep

#Variables
#ORP-Droid path variable
ORPDroidPath = "/dev/ttyACM0"
#ORP-Droid Arduino baudrate
baudrate = 9600
#Test timer in seconds
testTimer = 4

#Commands
#Uses ASCII character references

#ORP-Droid A left motor commands
leftFwdA = "A" #Character for forward
leftBwdA = "B" #Character for backard
leftStopA = "C" #Character for stop

#ORP-Droid A right motor commands
rightFwdA = "D" #Character for forward
rightBwdA = "E" #Character for backward
rightStopA = "F" #Character for stop

#ORP-Droid B left motor commands
leftFwdB = "U" #Character for forward
leftBwdB = "V" #Character for backward
leftStopB = "W" #Character for stop

#ORP-Droid B right motor commands
rightFwdB = "X" #Character for forward
rightBwdB = "Y" #Character for backward
rightStopB = "Z" #Character for stop


def start():
        initializeStream(ORPDroidPath, baudrate)
        openStream()

def end():
        closeStream()
        exit()

def droidAFwd():
        send(leftFwdA)
        send(rightFwdA)
        
def droidALeft():
        send(leftBwdA)
        send(rightFwdA)

def droidABwd():
        send(leftBwdA)
        send(rightBwdA)
        
def droidARight():
        send(leftFwdA)
        send(rightBwdA)
        
def droidAStop():
        send(leftStopA)
        send(rightStopB)
        
def droidBFwd():
        send(leftFwdB)
        send(rightFwdB)
        
def droidBLeft():
        send(leftBwdB)
        send(rightFwdB)
        
def droidBBwd():
        send(leftBwdB)
        send(rightBwdB)
        
def droidBRight():
        send(leftFwdB)
        send(rightBwdB)
        
def droidStopB():
        send(leftStopB)
        send(rightStopB)

def fullTest():
        #Runs test of all the commands
        print "Test 1"
        send(leftFwdA)
        sleep(testTimer)

        print "Test 2"
        send(leftBwdA)
        sleep(testTimer)

        print "Test 3"
        send(leftStopA)
        sleep(testTimer)

        print "Test 4"
        send(rightFwdA)
        sleep(testTimer)

        print "Test 5"
        send(rightBwdA)
        sleep(testTimer)

        print "Test 6"
        send(rightStopA)
        sleep(testTimer)

        print "Test 7"
        send(leftFwdB)
        sleep(testTimer)

        print "Test 8"
        send(leftBwdB)
        sleep(testTimer)

        print "Test 9"
        send(leftStopB)
        sleep(testTimer)

        print "Test 10"
        send(rightFwdB)
        sleep(testTimer)

        print "Test 11"
        send(rightBwdB)
        sleep(testTimer)

        print "Test 12"
        send(rightStopB)
        sleep(testTimer)

