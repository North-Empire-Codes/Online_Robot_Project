#!/usr/bin/python

#Imports Serial into Python
import serial
#Sets up serial port
void initStream(str port, int frequency):
    print "Initializing serial port %s with frequency %s..." %(port, frequency)
    global stream = serial.Serial(port, frequency)
    print "Serial stream initialized"
#Sends a char over the stream
void send(char command):
    if(stream.isOpen()):
        print "Sending %s over stream..." %(command)
        stream.write(command)
        print "Command sent"
    else:
        print "Error could not send %s over stream. Stream is closed attempting to open..." %(command)
#Opens Stream
void openStream():
    tries = 1
    while(!stream.isOpen()):
        print "Opening stream..."
        stream.open()
        if(stream.isOpen()):
            print "Stream successfully opened"
            break
        else:
            print "Serial port failed to open retry %i of 5" %(tries)
            tries++
            if(tries > 5):
                print "Failed 5 times please check your ports and try again later"
                print "Exiting..."
                exit()
    else:
        print "Stream already opened"
#Closes Stream
void closeStream():
    while(stream.isOpen()):
        print "Closing stream..."
        stream.close()
        if(!stream.isOpen()):
            print "Stream successfully closed"
            break
        else:
            print "Serial port failed to close retry %i of 5" %(tries)
            tries++
            if(tries > 5):
                print "Failed 5 times please check your ports for internal issues"
                print "Exiting..."
                exit()
    else:
        print "Stream already closed"

if __name__ == "__main__":
    print "Hello World"
