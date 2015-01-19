#!/usr/bin/python

#Imports Serial into Python
import serial

#Function to initialize stream
def initializeStream(portPath, frequency):
        #Makes variable stream global
        global stream
        print "Initializing stream with the port path '%s' with the frequency of %d..." %(portPath, frequency)
        stream = serial.Serial(portPath, frequency)
        print "Done initializing"

#Function to open stream
def openStream():
        #Checks if stream is closed
        if(not stream.isOpen()):
                print "Opening stream..."
                stream.open()
                #Checks if stream opened
                if(stream.isOpen()):
                        print "Stream opened"
                else:
                        print "Error could not open stream"
        else:
                print "Stream already opened"

#Function to close stream
def closeStream():
        #Checks if stream is open
        if(stream.isOpen()):
                print "Closing stream..."
                stream.close()
                #Checks if stream closed
                if(not stream.isOpen()):
                        print "Stream closed"
                else:
                        print "Error could not close stream"
        else:
                print "Stream already closed"

#Function to send data
def send(data):
        #Checks if stream is opened
        if(stream.isOpen()):
                #Writes data to the serial stream
                print "Sending %s over stream..." %(data)
                stream.write(data)
                print "Data sent"
        else:
                print "Cannot send %s over stream. Stream is not open" %(data)
                openStream()

def receive():
        #Checks if stream is opened
        if(stream.isOpen()):
                #Receives data from stream
                print "Looking for data over stream..."
                input = stream.readline()
                print "Data found"
                return input
        else:
                print "Cannot receive data over stream. Stream is not open"
                openStream()
