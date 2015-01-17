#!/usr/bin/python
#Imports Serial into Python
import serial
#Sets up serial port
def initStream(port, frequency):
        print "Initializing serial port %s with frequency %i..." %(port, frequency)
        global stream
        stream = serial.Serial(port, frequency)
        print "Serial stream initialized"
#Sends a byte over the stream
def send(command):
        if(stream.isOpen()):
                print "Sending %s over stream..." %(command)
                stream.write(command)
                print "Command sent"
        else:
                print "Error could not send %s over stream. Stream is closed attempting to open..." %(command)
                openStream()
#Receives a byte over the stream
def receive():
        if(stream.isOpen):
                print "Receiving..."
                return stream.readline()
        else:
                print "Error could not receive byte over stream. Stream is closed attempting to open..."
                openStream()
#Opens Stream
def openStream():
        tries = 1
        while(not stream.isOpen()):
                print "Opening stream..."
                stream.open()
                if(stream.isOpen()):
                        print "Stream successfully opened"
                        break
                else:
                        print "Serial port failed to open retry %i of 5" %(tries)
                        tries =+ 1
                        if(tries > 5):
                                print "Failed 5 times please check your ports and try again later"
                                print "Exiting..."
                                exit()
        else:
                print "Stream already opened"
#Closes Stream
def closeStream():
        tries = 1
        while(stream.isOpen()):
                print "Closing stream..."
                stream.close()
                if(not stream.isOpen()):
                        print "Stream successfully closed"
                        break
                else:
                        print "Serial port failed to close retry %i of 5" %(tries)
                        tries =+ 1
                        if(tries > 5):
                                print "Failed 5 times please check your ports for internal issues"
                                print "System will now exit"
                                print "Exiting..."
                                exit()
        else:
                print "Stream already closed"
